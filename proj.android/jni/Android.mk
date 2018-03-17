LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH))

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
../../Classes/AppDelegate.cpp \
../../Classes/Admob.cpp \
../../Classes/AdmodAndroid.cpp \
../../Classes/AIRandomSuggest.cpp \
../../Classes/AlgorithmPikachu.cpp \
../../Classes/AlgorithmRandom.cpp \
../../Classes/AndroidScene.cpp \
../../Classes/BaseOject.cpp \
../../Classes/ButtonCustom.cpp \
../../Classes/DataUser.cpp \
../../Classes/DrawLinePikachu.cpp \
../../Classes/GameScene.cpp \
../../Classes/GameBoard.cpp \
../../Classes/HomeScene.cpp \
../../Classes/MyLine.cpp \
../../Classes/PikachuObject.cpp \
../../Classes/GameCenterAndGoolePlay.cpp \
../../Classes/PopupGame.cpp \
../../Classes/ProgressBarCustom.cpp

LOCAL_LDLIBS := -landroid \
-llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += android_native_app_glue
LOCAL_LDLIBS += -landroid
LOCAL_LDLIBS += -llog



# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-add-path,$(LOCAL_PATH))

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
