#
# libbluedroid
#

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	bluetooth.c

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/include \
	system/bluetooth/bluez-clean-headers

ifeq ($(BOARD_ANT_WIRELESS_POWER),"bluedroid")
LOCAL_CFLAGS += -DBOARD_HAVE_ANT_WIRELESS

LOCAL_SRC_FILES += \
	antradio.c
endif

LOCAL_SHARED_LIBRARIES := \
	libcutils

LOCAL_MODULE := libbluedroid

include $(BUILD_SHARED_LIBRARY)
