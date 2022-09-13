// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

void animationShowKB4WiFi_Animation(lv_obj_t * TargetObject, int delay);
extern lv_obj_t * ui_Scanning_WiFi_and_BLE1;
extern lv_obj_t * ui_CompatibilityNotes;
void ui_event_WiFiPWD(lv_event_t * e);
extern lv_obj_t * ui_WiFiPWD;
void ui_event_WiFiSSID(lv_event_t * e);
extern lv_obj_t * ui_WiFiSSID;
extern lv_obj_t * ui_KB4WiFi;
extern lv_obj_t * ui_ScanSpinner;
extern lv_obj_t * ui_PageName;
extern lv_obj_t * ui_Scanning_Camera;
extern lv_obj_t * ui_CameraList;
extern lv_obj_t * ui_BLEPINCODE;
extern lv_obj_t * ui_KB4Camera;
extern lv_obj_t * ui_Bar1;
extern lv_obj_t * ui_Summary;
extern lv_obj_t * ui_XR_Setup;
extern lv_obj_t * ui_Auto_Focus;
extern lv_obj_t * ui_About_me;

void scanWiFiNow(lv_event_t * e);





void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
