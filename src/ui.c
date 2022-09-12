// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
void ui_event_Roller1(lv_event_t * e);
lv_obj_t * ui_Roller1;
lv_obj_t * ui_Roller2;
lv_obj_t * ui_Roller3;
lv_obj_t * ui_Roller4;
lv_obj_t * ui_Roller5;
lv_obj_t * ui_Roller6;
lv_obj_t * ui_Button2;
lv_obj_t * ui_Label1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_Roller1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        usr_lv_r1numchange(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_color_black());
    lv_style_set_text_color(&style, lv_color_white());
    lv_style_set_border_width(&style, 0);
    lv_style_set_pad_all(&style, 0);
    lv_obj_add_style(ui_Screen1, &style, 0);

    ui_Roller1 = lv_roller_create(ui_Screen1);
    lv_roller_set_options(ui_Roller1, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(ui_Roller1, 50);
    lv_obj_set_height(ui_Roller1, 141);
    lv_obj_set_x(ui_Roller1, -126);
    lv_obj_set_y(ui_Roller1, 35);
    lv_obj_set_align(ui_Roller1, LV_ALIGN_CENTER);
    lv_obj_add_style(ui_Roller1,&style,0);
    lv_obj_set_style_bg_opa(ui_Roller1,LV_OPA_TRANSP,LV_PART_SELECTED);
    lv_roller_set_visible_row_count(ui_Roller1,3);

    ui_Roller2 = lv_roller_create(ui_Screen1);
    lv_roller_set_options(ui_Roller2, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(ui_Roller2, 50);
    lv_obj_set_height(ui_Roller2, 141);
    lv_obj_set_x(ui_Roller2, -76);
    lv_obj_set_y(ui_Roller2, 35);
    lv_obj_set_align(ui_Roller2, LV_ALIGN_CENTER);

    ui_Roller3 = lv_roller_create(ui_Screen1);
    lv_roller_set_options(ui_Roller3, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(ui_Roller3, 50);
    lv_obj_set_height(ui_Roller3, 141);
    lv_obj_set_x(ui_Roller3, -26);
    lv_obj_set_y(ui_Roller3, 35);
    lv_obj_set_align(ui_Roller3, LV_ALIGN_CENTER);

    ui_Roller4 = lv_roller_create(ui_Screen1);
    lv_roller_set_options(ui_Roller4, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(ui_Roller4, 50);
    lv_obj_set_height(ui_Roller4, 141);
    lv_obj_set_x(ui_Roller4, 24);
    lv_obj_set_y(ui_Roller4, 35);
    lv_obj_set_align(ui_Roller4, LV_ALIGN_CENTER);

    ui_Roller5 = lv_roller_create(ui_Screen1);
    lv_roller_set_options(ui_Roller5, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(ui_Roller5, 50);
    lv_obj_set_height(ui_Roller5, 141);
    lv_obj_set_x(ui_Roller5, 74);
    lv_obj_set_y(ui_Roller5, 35);
    lv_obj_set_align(ui_Roller5, LV_ALIGN_CENTER);

    ui_Roller6 = lv_roller_create(ui_Screen1);
    lv_roller_set_options(ui_Roller6, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);
    lv_obj_set_width(ui_Roller6, 50);
    lv_obj_set_height(ui_Roller6, 141);
    lv_obj_set_x(ui_Roller6, 124);
    lv_obj_set_y(ui_Roller6, 35);
    lv_obj_set_align(ui_Roller6, LV_ALIGN_CENTER);

    ui_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button2, 88);
    lv_obj_set_height(ui_Button2, 35);
    lv_obj_set_x(ui_Button2, 93);
    lv_obj_set_y(ui_Button2, -78);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -119);
    lv_obj_set_y(ui_Label1, -77);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Roller1, ui_event_Roller1, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
