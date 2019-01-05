#include "PlayFab.h"

// Settings
#include "PlayFabRuntimeSettings.h"
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR
#include "PlayFabSettings.h"

// Api's
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabMatchmakerAPI.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabEntityAPI.h"

DEFINE_LOG_CATEGORY(LogPlayFab);

#define LOCTEXT_NAMESPACE "FPlayFabModule"

class FPlayFabModule : public IPlayFabModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    // Settings
    void RegisterSettings();
    void UnregisterSettings();

    /** Callback for when the settings were saved. */
    bool HandleSettingsSaved();

    FString GetTitleId() const override { return PlayFab::PlayFabSettings::titleId; };
    PlayFabAdminPtr GetAdminAPI() const override { return AdminAPI; };
    PlayFabMatchmakerPtr GetMatchmakerAPI() const override { return MatchmakerAPI; };
    PlayFabServerPtr GetServerAPI() const override { return ServerAPI; };
    PlayFabClientPtr GetClientAPI() const override { return ClientAPI; };
    PlayFabEntityPtr GetEntityAPI() const override { return EntityAPI; };

    PlayFabAdminPtr AdminAPI;
    PlayFabMatchmakerPtr MatchmakerAPI;
    PlayFabServerPtr ServerAPI;
    PlayFabClientPtr ClientAPI;
    PlayFabEntityPtr EntityAPI;
};

void FPlayFabModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    RegisterSettings();
    HandleSettingsSaved();

    // create the API
    ClientAPI = MakeShareable(new PlayFab::UPlayFabClientAPI());
    EntityAPI = MakeShareable(new PlayFab::UPlayFabEntityAPI());

#if WITH_SERVER_CODE
    ServerAPI = MakeShareable(new PlayFab::UPlayFabServerAPI());
    MatchmakerAPI = MakeShareable(new PlayFab::UPlayFabMatchmakerAPI());
    AdminAPI = MakeShareable(new PlayFab::UPlayFabAdminAPI());
#endif
}

void FPlayFabModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    UnregisterSettings();
}

void FPlayFabModule::RegisterSettings()
{
#if WITH_EDITOR
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "PlayFab",
            LOCTEXT("PlayFabSettingsName", "PlayFab"),
            LOCTEXT("PlayFabSettingsDescription", "Configure the PlayFab plugin"),
            GetMutableDefault<UPlayFabRuntimeSettings>()
        );

        if (SettingsSection.IsValid())
        {
            SettingsSection->OnModified().BindRaw(this, &FPlayFabModule::HandleSettingsSaved);
        }
    }
#endif // WITH_EDITOR
}

void FPlayFabModule::UnregisterSettings()
{
#if WITH_EDITOR
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "PlayFab");
    }
#endif
}

bool FPlayFabModule::HandleSettingsSaved()
{
    // copy to the internal structure
    PlayFab::PlayFabSettings::serverURL = FString(); // flush the previous Server URL
    PlayFab::PlayFabSettings::useDevelopmentEnvironment = GetDefault<UPlayFabRuntimeSettings>()->bUseDevelopmentEnvironment;
    PlayFab::PlayFabSettings::developmentEnvironmentURL = GetDefault<UPlayFabRuntimeSettings>()->DevelopmentEnvironmentURL;
    PlayFab::PlayFabSettings::productionEnvironmentURL = GetDefault<UPlayFabRuntimeSettings>()->ProductionEnvironmentURL;
    PlayFab::PlayFabSettings::titleId = GetDefault<UPlayFabRuntimeSettings>()->TitleId;
    PlayFab::PlayFabSettings::developerSecretKey = GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey;

    return true;
}
#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabModule, PlayFab)
