// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

///////////////////// VARIABLES ////////////////////
void animationShowKB4WiFi_Animation(lv_obj_t * TargetObject, int delay);
lv_obj_t * ui_Scanning_WiFi;
lv_obj_t * ui_CompatibilityNotes;
void ui_event_WiFiPWD(lv_event_t * e);
lv_obj_t * ui_WiFiPWD;
lv_obj_t * ui_KB4WiFi;
lv_obj_t * ui_PageName;
lv_obj_t * ui_symbolWiFi;
void ui_event_ScanSwitch(lv_event_t * e);
lv_obj_t * ui_ScanSwitch;
lv_obj_t * ui_scanSwitchLabel;
lv_obj_t * ui_ScanSpinner;
lv_obj_t * ui_Scanning_Camera;
lv_obj_t * ui_CameraList;
lv_obj_t * ui_BLEPINCODE;
lv_obj_t * ui_KB4Camera;
lv_obj_t * ui_Summary;
lv_obj_t * ui_XR_Setup;
lv_obj_t * ui_Auto_Focus;
lv_obj_t * ui_About_me;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void animationShowKB4WiFi_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 180, 60);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_WiFiPWD(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_flag_modify(ui_KB4WiFi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        animationShowKB4WiFi_Animation(ui_KB4WiFi, 0);
    }
    if(event_code == LV_EVENT_DEFOCUSED) {
        _ui_flag_modify(ui_KB4WiFi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_basic_set_property(ui_KB4WiFi, _UI_BASIC_PROPERTY_POSITION_Y,  180);
    }
    if(event_code == LV_EVENT_READY) {
        _ui_flag_modify(ui_KB4WiFi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_basic_set_property(ui_KB4WiFi, _UI_BASIC_PROPERTY_POSITION_Y,  180);
        connect_WiFi_init(e);
    }
}
void ui_event_ScanSwitch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        _ui_flag_modify(ui_ScanSpinner, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_symbolWiFi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_state_modify(ui_ScanSwitch, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
        scanWiFiNow(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Scanning_WiFi_screen_init(void)
{
    ui_Scanning_WiFi = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Scanning_WiFi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CompatibilityNotes = lv_label_create(ui_Scanning_WiFi);
    lv_obj_set_width(ui_CompatibilityNotes, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CompatibilityNotes, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_CompatibilityNotes, 0);
    lv_obj_set_y(ui_CompatibilityNotes, 97);
    lv_obj_set_align(ui_CompatibilityNotes, LV_ALIGN_CENTER);
    lv_label_set_text(ui_CompatibilityNotes, "Only 2.4G Wi Fi is supported");

    ui_WiFiPWD = lv_textarea_create(ui_Scanning_WiFi);
    lv_obj_set_width(ui_WiFiPWD, 256);
    lv_obj_set_height(ui_WiFiPWD, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_WiFiPWD, 0);
    lv_obj_set_y(ui_WiFiPWD, -40);
    lv_obj_set_align(ui_WiFiPWD, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_WiFiPWD, "Password");
    lv_textarea_set_one_line(ui_WiFiPWD, true);
    // lv_textarea_set_password_mode(ui_WiFiPWD, true)
    lv_obj_add_flag(ui_WiFiPWD, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_style_text_font(ui_WiFiPWD, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_KB4WiFi = lv_keyboard_create(ui_Scanning_WiFi);
    lv_obj_set_width(ui_KB4WiFi, 320);
    lv_obj_set_height(ui_KB4WiFi, 120);
    lv_obj_set_x(ui_KB4WiFi, 0);
    lv_obj_set_y(ui_KB4WiFi, 180);
    lv_obj_set_align(ui_KB4WiFi, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_KB4WiFi, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_PageName = lv_label_create(ui_Scanning_WiFi);
    lv_obj_set_width(ui_PageName, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PageName, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PageName, -51);
    lv_obj_set_y(ui_PageName, -92);
    lv_obj_set_align(ui_PageName, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PageName, "Initializtion -- WiFi (2/4)");
    lv_obj_set_style_text_font(ui_PageName, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_symbolWiFi = lv_label_create(ui_Scanning_WiFi);
    lv_obj_set_width(ui_symbolWiFi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_symbolWiFi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_symbolWiFi, 0);
    lv_obj_set_y(ui_symbolWiFi, -20);
    lv_obj_set_align(ui_symbolWiFi, LV_ALIGN_CENTER);
    lv_label_set_text(ui_symbolWiFi, "\xEF\x87\xAB");
    lv_obj_set_style_text_font(ui_symbolWiFi, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScanSwitch = lv_switch_create(ui_Scanning_WiFi);
    lv_obj_set_width(ui_ScanSwitch, 80);
    lv_obj_set_height(ui_ScanSwitch, 30);
    lv_obj_set_x(ui_ScanSwitch, 0);
    lv_obj_set_y(ui_ScanSwitch, 64);
    lv_obj_set_align(ui_ScanSwitch, LV_ALIGN_CENTER);

    ui_scanSwitchLabel = lv_label_create(ui_Scanning_WiFi);
    lv_obj_set_width(ui_scanSwitchLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_scanSwitchLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scanSwitchLabel, 0);
    lv_obj_set_y(ui_scanSwitchLabel, 34);
    lv_obj_set_align(ui_scanSwitchLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_scanSwitchLabel, "Scan Now");
    lv_obj_set_style_text_font(ui_scanSwitchLabel, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScanSpinner = lv_spinner_create(ui_Scanning_WiFi, 1000, 90);
    lv_obj_set_width(ui_ScanSpinner, 80);
    lv_obj_set_height(ui_ScanSpinner, 80);
    lv_obj_set_x(ui_ScanSpinner, 0);
    lv_obj_set_y(ui_ScanSpinner, -20);
    lv_obj_set_align(ui_ScanSpinner, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ScanSpinner, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_ScanSpinner, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_add_event_cb(ui_WiFiPWD, ui_event_WiFiPWD, LV_EVENT_ALL, NULL);
    lv_keyboard_set_textarea(ui_KB4WiFi, ui_WiFiPWD);
    lv_obj_add_event_cb(ui_ScanSwitch, ui_event_ScanSwitch, LV_EVENT_ALL, NULL);

}
void ui_Scanning_Camera_screen_init(void)
{
    ui_Scanning_Camera = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Scanning_Camera, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_CameraList = lv_dropdown_create(ui_Scanning_Camera);
    lv_dropdown_set_options(ui_CameraList, "");
    lv_dropdown_set_text(ui_CameraList, "Camera List");
    lv_obj_set_width(ui_CameraList, 256);
    lv_obj_set_height(ui_CameraList, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_CameraList, -10);
    lv_obj_set_y(ui_CameraList, -84);
    lv_obj_set_align(ui_CameraList, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_CameraList, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_BLEPINCODE = lv_textarea_create(ui_Scanning_Camera);
    lv_obj_set_width(ui_BLEPINCODE, 94);
    lv_obj_set_height(ui_BLEPINCODE, LV_SIZE_CONTENT);    /// 70
    lv_obj_set_x(ui_BLEPINCODE, -90);
    lv_obj_set_y(ui_BLEPINCODE, -34);
    lv_obj_set_align(ui_BLEPINCODE, LV_ALIGN_CENTER);
    lv_textarea_set_max_length(ui_BLEPINCODE, 6);
    lv_textarea_set_placeholder_text(ui_BLEPINCODE, "PIN Code");
    lv_textarea_set_one_line(ui_BLEPINCODE, true);

    ui_KB4Camera = lv_keyboard_create(ui_Scanning_Camera);
    lv_keyboard_set_mode(ui_KB4Camera, LV_KEYBOARD_MODE_NUMBER);
    lv_obj_set_width(ui_KB4Camera, 317);
    lv_obj_set_height(ui_KB4Camera, 120);
    lv_obj_set_x(ui_KB4Camera, -1);
    lv_obj_set_y(ui_KB4Camera, 57);
    lv_obj_set_align(ui_KB4Camera, LV_ALIGN_CENTER);

    lv_keyboard_set_textarea(ui_KB4Camera, ui_BLEPINCODE);

}
void ui_Summary_screen_init(void)
{
    ui_Summary = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Summary, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
void ui_XR_Setup_screen_init(void)
{
    ui_XR_Setup = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_XR_Setup, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
void ui_Auto_Focus_screen_init(void)
{
    ui_Auto_Focus = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Auto_Focus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
void ui_About_me_screen_init(void)
{
    ui_About_me = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_About_me, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Scanning_WiFi_screen_init();
    ui_Scanning_Camera_screen_init();
    ui_Summary_screen_init();
    ui_XR_Setup_screen_init();
    ui_Auto_Focus_screen_init();
    ui_About_me_screen_init();
    lv_disp_load_scr(ui_Scanning_WiFi);
}
