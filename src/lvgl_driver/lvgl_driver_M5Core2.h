
#ifndef _LVGL_DRIVER_M5CORE2_H
#define _LVGL_DRIVER_M5CORE2_H

#include <M5Core2.h>
#include "ui/ui.h"
#include "ui/ui_helpers.h"
#include "lvgl.h"

// init the tft espi
static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;  // Descriptor of a display driver
static lv_indev_drv_t indev_drv; // Descriptor of a touch driver

void tft_lv_initialization();
void my_disp_flush();
void init_disp_driver();
void my_touchpad_read();
void init_touch_driver();
void M5Core2_lvgl_begin();

#endif