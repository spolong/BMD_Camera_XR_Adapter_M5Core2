#include "lvgl_driver/lvgl_driver_M5Core2.h"

// UI Task
void UI_Task(void * pvParam){
  M5Core2_lvgl_begin();
  while (1)
  {
    M5.update();
    lv_task_handler();
  }
  
}

void setup()
{
  // create task for UI -> Core 1
  xTaskCreatePinnedToCore(UI_Task,"UI Task",1024 * 32,NULL,1,NULL,1);
  vTaskDelete(NULL);
}

void loop()
{

}