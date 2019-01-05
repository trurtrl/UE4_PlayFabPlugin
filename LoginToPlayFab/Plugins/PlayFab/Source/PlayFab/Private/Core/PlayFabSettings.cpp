#include "PlayFabSettings.h"

namespace PlayFab
{
    const FString PlayFabSettings::sdkVersion = "0.0.180507";
    const FString PlayFabSettings::buildIdentifier = "jbuild_unrealcppsdk_1";
    const FString PlayFabSettings::versionString = "UE4SDK-0.0.180507";

    bool PlayFabSettings::useDevelopmentEnvironment = false;
    FString PlayFabSettings::serverURL;
    FString PlayFabSettings::developmentEnvironmentURL = ".playfabsandbox.com";
    FString PlayFabSettings::productionEnvironmentURL = ".playfabapi.com";
    FString PlayFabSettings::titleId;
    FString PlayFabSettings::clientSessionTicket;
    FString PlayFabSettings::developerSecretKey;
    FString PlayFabSettings::entityToken;
    FString PlayFabSettings::advertisingIdType;
    FString PlayFabSettings::advertisingIdValue;

    bool PlayFabSettings::disableAdvertising = false;
    const FString PlayFabSettings::AD_TYPE_IDFA = "Idfa";
    const FString PlayFabSettings::AD_TYPE_ANDROID_ID = "Adid";
}
