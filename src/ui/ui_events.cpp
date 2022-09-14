// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.0
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include <WiFi.h>

// Create a SSID List
static lv_obj_t *wifiList;

const char *wifiSSID;
const char *wifiPWD;

// connect WiFi
void connect_WiFi_init(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *obj = lv_event_get_target(e);
	wifiPWD = lv_textarea_get_text(obj);
	LV_LOG_USER("SSID: %s", wifiSSID);
	LV_LOG_USER("SSID: %s", wifiPWD);
	WiFi.begin(wifiSSID, wifiPWD);
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

// Select WiFi by SSID Item
void Select_WiFi_SSID_Item(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *obj = lv_event_get_target(e);
	if (code == LV_EVENT_CLICKED)
	{
		LV_LOG_USER("Clicked: %s", lv_list_get_btn_text(wifiList, obj));
		wifiSSID = lv_list_get_btn_text(wifiList, obj);
		lv_obj_add_flag(wifiList, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_symbolWiFi, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_scanSwitchLabel, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(ui_ScanSwitch, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(ui_WiFiPWD, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_PRESSED)
	{
		LV_LOG_USER("Pressed: %s", lv_list_get_btn_text(wifiList, obj));
	}
}

// Scan WiFi Task
void Scan_WiFi_Task(void *pvParam)
{

	// Set WiFi to station mode and disconnect from an AP if it was previously connected
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);

	Serial.println("Setup done");
	Serial.println("scan start");

	// WiFi.scanNetworks will return the number of networks found
	int n = WiFi.scanNetworks();

	wifiList = lv_list_create(ui_Scanning_WiFi);
	lv_obj_set_size(wifiList, 320, 240);
	lv_obj_center(wifiList);
	// Add buttons to the list
	lv_obj_t *btn;

	Serial.println("scan done");

	// Stop the Spinner , it use 45% CPU
	lv_obj_add_flag(ui_ScanSpinner, LV_OBJ_FLAG_HIDDEN);

	if (n == 0)
	{
		Serial.println("no networks found");
	}
	else
	{
		Serial.print(n);
		Serial.println(" networks found");
		lv_list_add_text(wifiList, "WiFi SSDI List");
		lv_obj_set_style_text_font(wifiList, &lv_font_montserrat_20, LV_PART_MAIN);
		for (int i = 0; i < n; ++i)
		{
			// Print SSID and RSSI for each network found
			Serial.print(i + 1);
			Serial.print(": ");
			Serial.print(WiFi.SSID(i));
			Serial.print(" (");
			Serial.print(WiFi.RSSI(i));
			Serial.print(")");
			Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
			delay(10);
			if (WiFi.RSSI(i) > -65)
			{
				/* code */
				btn = lv_list_add_btn(wifiList, LV_SYMBOL_WIFI, WiFi.SSID(i).c_str());
				delay(10);
				lv_obj_add_event_cb(btn, Select_WiFi_SSID_Item, LV_EVENT_ALL, NULL);
			}
		}
		lv_list_add_text(wifiList, "Other operation");
		btn = lv_list_add_btn(wifiList, LV_SYMBOL_CLOSE, "Skip WiFi");
		btn = lv_list_add_btn(wifiList, LV_SYMBOL_SHUFFLE, "Scan again");
		lv_obj_add_event_cb(btn, scanWiFiNow, LV_EVENT_CLICKED, NULL);
	}
	Serial.println("List Show Done.");
	delay(100);
	WiFi.scanDelete();
	vTaskDelete(NULL);
}

void scanWiFiNow(lv_event_t *e)
{
	// Wifi work on Core 0
	xTaskCreatePinnedToCore(Scan_WiFi_Task, "Scan WiFi Task", 1024 * 32, NULL, 1, NULL, 0);
}
