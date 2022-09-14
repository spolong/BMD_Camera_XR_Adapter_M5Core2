// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include <WiFi.h>

// Scan WiFi Task
void Scan_WiFi_Task(void * pvParam){

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
	Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();

	// Create a SSID List
	static lv_obj_t * wifiList;
	wifiList = lv_list_create(ui_Scanning_WiFi);
	lv_obj_set_size(wifiList,320,240);
	lv_obj_center(wifiList);
	// Add buttons to the list
	lv_obj_t * btn;

    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
		lv_list_add_text(wifiList,"WiFi SSDI List");
	    lv_obj_set_style_text_font(wifiList, &lv_font_montserrat_30, LV_PART_MAIN);
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(30);
			if (WiFi.RSSI(i) > -70)
			{
				/* code */
				btn = lv_list_add_btn(wifiList,LV_SYMBOL_WIFI,WiFi.SSID(i).c_str());
			}
        }
		lv_list_add_text(wifiList,"Other operation");
		btn = lv_list_add_btn(wifiList,LV_SYMBOL_SHUFFLE,"Scan again");
		btn = lv_list_add_btn(wifiList,LV_SYMBOL_CLOSE,"Skip WiFi");
    }
    Serial.println("List Show Done.");
	vTaskDelete(NULL);
}

void scanWiFiNow(lv_event_t * e)
{
	xTaskCreatePinnedToCore(Scan_WiFi_Task,"Scan WiFi Task",1024 * 32,NULL,1,NULL,0);
}
