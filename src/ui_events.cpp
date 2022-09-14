// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include <M5Core2.h>
#include <WiFi.h>

void scanWiFiNow(lv_event_t * e)
{
        //     lv_ui_flag_modify(ui_ScanSpinner, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        // _ui_flag_modify(ui_symbolWiFi, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        // _ui_state_modify(ui_ScanSwitch, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    Serial.println("Setup done");
        Serial.println("scan start");
    lv_obj_clear_flag(ui_ScanSpinner,LV_OBJ_FLAG_HIDDEN);
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");
}
