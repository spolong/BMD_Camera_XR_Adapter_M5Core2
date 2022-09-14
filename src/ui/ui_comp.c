// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project


#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

uint32_t LV_EVENT_GET_COMP_CHILD;

typedef struct {
    uint32_t child_idx;
    lv_obj_t * child;
} ui_comp_get_child_t;

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx)
{
    ui_comp_get_child_t info;
    info.child = NULL;
    info.child_idx = child_idx;
    lv_event_send(comp, LV_EVENT_GET_COMP_CHILD, &info);
    return info.child;
}

void get_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    ui_comp_get_child_t * info = lv_event_get_param(e);
    info->child = c[info->child_idx];
}

void del_component_child_event_cb(lv_event_t * e)
{
    lv_obj_t ** c = lv_event_get_user_data(e);
    lv_mem_free(c);
}


// COMPONENT WiFi SSID

lv_obj_t * ui_WiFi_SSID_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_WiFi_SSID;
    cui_WiFi_SSID = lv_dropdown_create(comp_parent);
    lv_dropdown_set_text(cui_WiFi_SSID, "Wi-Fi SSID");
    lv_obj_set_width(cui_WiFi_SSID, 256);
    lv_obj_set_height(cui_WiFi_SSID, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_WiFi_SSID, -7);
    lv_obj_set_y(cui_WiFi_SSID, -78);
    lv_obj_set_align(cui_WiFi_SSID, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_WiFi_SSID, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_WIFI_SSID_NUM);
    children[UI_COMP_WIFI_SSID_WIFI_SSID] = cui_WiFi_SSID;
    lv_obj_add_event_cb(cui_WiFi_SSID, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_WiFi_SSID, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_WiFi_SSID;
}

