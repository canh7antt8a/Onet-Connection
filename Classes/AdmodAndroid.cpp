//
//  AdmodAndroid.cpp

#include "AdmodAndroid.h"
#include "cocos2d.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "jni/JniHelper.h"
extern "C"{
    void AdmodAndroid::showBanner(){

        JniMethodInfo methodInfo;
        bool b = JniHelper::getStaticMethodInfo(methodInfo,"org.cocos2dx.cpp.AppActivity","showAd","()V");
        if(b){
        	 log("aaaaaaaaaaaaaaaaaaaaaaaaaaa");
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
            
        }else{
            log("Error");
        }
    }
    void AdmodAndroid::hideBanner(){
        JniMethodInfo methodInfo;
        bool b = JniHelper::getStaticMethodInfo(methodInfo,"org.cocos2dx.cpp.AppActivity","hideAd","()V");
        if(b){
       	 log("bbbbbbbbbbbbbbbbbbbbbbbbbb");
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }else{
            log("Error");
        }
    }
    void AdmodAndroid::showFullAdvertiment(){
        JniMethodInfo methodInfo;
        bool b = JniHelper::getStaticMethodInfo(methodInfo,"org.cocos2dx.cpp.AppActivity","showInterstitialAd","()V");
        if(b)
        {
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }
        else{
            log("Error");
        }

    }
    bool AdmodAndroid::getStatusShowFull()
    {
        JniMethodInfo methodInfo;
        bool b = JniHelper::getStaticMethodInfo(methodInfo,"org.cocos2dx.cpp.AppActivity","getStatusAdMode","()Z");
        if(b){
            log("bbbbbbbbbbbbbbbbbbbbbbbbbb");
            jboolean status =  methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
            return (bool)status;
        }else{
            log("Error");
            return false;
        }
    }
    
    
    void AdmodAndroid::unlockAchimentGoogle(int levelUnlock)
    {
        JniMethodInfo methodInfo;
        jint p = (jint)levelUnlock;
        bool b = JniHelper::getStaticMethodInfo(methodInfo,"com.nguyenhoang.game.GoogleLeaderboards","jniUnlock","(I)V");
        if(b)
        {
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,p);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }
    }
    void AdmodAndroid::showAchimentGoolgle() {
        JniMethodInfo methodInfo;
        bool b = JniHelper::getStaticMethodInfo(methodInfo,"com.nguyenhoang.game.GoogleLeaderboards","jniShowAchiment","()V");
        if(b){
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }
    }
}
#endif
