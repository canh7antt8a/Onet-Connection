//
//  GameCenterAndGoolePlay.cpp
//  OnlyColor
//
//  Created by Nguyen Chi Hoang on 3/19/17.
//
//

#include "cocos2d.h"
#include "GameCenterAndGoolePlay.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "AdmobIOSWrapper.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "AdmodAndroid.h"
#endif


static GameCenterAndGoolePlay _sbManager;
GameCenterAndGoolePlay* GameCenterAndGoolePlay::getInstance()
{
    return &_sbManager;
}
void GameCenterAndGoolePlay::showAchievements()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    AdmobIOSWrapper::getInstance()->showAchiment();
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    AdmodAndroid::showAchimentGoolgle();
#endif
}

void GameCenterAndGoolePlay::postAchievementGoogleAndApple( int levelGoogle){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    AdmodAndroid::unlockAchimentGoogle(levelGoogle);
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    if(levelGoogle == 1){
        AdmobIOSWrapper::getInstance()->unlockAchimnet("Beginner01", 5);
    }
    if(levelGoogle == 4){
        AdmobIOSWrapper::getInstance()->unlockAchimnet("Meda_Second_02", 10);
    }
    if(levelGoogle == 8){
        AdmobIOSWrapper::getInstance()->unlockAchimnet("MedalFirst_03", 15);
    }
    if(levelGoogle == 12){
        AdmobIOSWrapper::getInstance()->unlockAchimnet("Trophy_01", 20);
    }
#endif
}
