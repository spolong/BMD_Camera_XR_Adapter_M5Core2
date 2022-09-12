# BMD Camera XR Adapter Plan

## Dev log

### WiFi model:
1. test smartconfig -- wechat cloud not work , ESP-Touch only.
2. add airkey , but cloud not work. ( esp_smartconfig_set_type(SC_TYPE_ESPTOUCH_AIRKISS); )
3. auto reconnect WiFi, When WiFi.status() is True.
4. need a button for start smartconfig
5. auto reconnect WiFi, When WiFi disconnected.

### BLE model:
1. review old library -- bleconnect
2. BLE Client with PIN Code

### Input and Output model:
1. LVGL test
2. UI for WiFi and BLE Test

## Development Environment
- IDE[VSCode](https://github.com/microsoft/vscode)
- IoT IDE[PlatformIO](https://github.com/platformio/platformio-vscode-ide)
- [Arduino](https://github.com/arduino/Arduino)

### Hardware
- [M5StackCore2](https://github.com/m5stack/M5Core2)

#### Hardware model: todo
0. ESP32 Dev (M5 Stack Core)
1. 9DOF sensor
2. TOF sensor
3. M5POE
4. M5Plus

### Software
- [ESP32-Arduino](https://github.com/espressif/arduino-esp32)
- [LVGL](https://github.com/lvgl/lvgl)
- [SquareLine Studio](https://docs.squareline.io/docs/squareline/)

#### Software model: todo
0. input and output UI
1. Wi-Fi scan and connect
2. BLE scan and connect
3. getting 6DOF sensor data and TOF sensor data
4. OSC input and output

### Function: todo
1. Get the camera metadata and sending to the PC by OSC
2. Get the lens metadata and sending to the PC by OSC
3. Get the camera 6DOF data and sending to the PC by OSC
4. Get the camera timecode and sending to the PC by OSC
5. Set up the camera and lens by OSC
6. Set up the camera timecode by NTP
7. Auto focus by TOF sensor

## UI Layout Plan

### init page

#### Scanning Camera
Scan Button -> one of results connecting -> Input PinCode -> OK
touch icon -> waiting -> Check the Camera for PIN -> keyboard -> Icon for next


#### Connecting Wi-Fi
Scan SSID -> Result List -> Input PWD -> OK
Touch Icon -> waiting -> Select your WiFi -> keyboard

#### Function Setup
- timecode and NTP server
- IMU
- Lens Meta data
- Camera Meta data
- OSC Server and Port
- Auto Focus
- Metabones Switch

#### Done

### Summary page
- BMD Camera XR Adapter 
- WiFi & BLE RSSI 
- Device Name Or Model Name
- IP Address and Port
- delay (ping)
- Focus Distance
    - Depth of Field (BMPCC 6K or newer)
    - Focus Point (Only BMPCC4K)
- Camera-Subject Distance (via ToF sensor)
- Focal Length of the Lens

## How to USE 
1. copy the lv_conf.h from the src folder into the .pio/libdeps/lvgl folder (you have to do this since the lvgl library is pulled from github)
2. edit the .pio/libdeps/lvgl/src/misc/lv_conf_internal.h and change the line like so:
```c
#elif defined(LV_CONF_INCLUDE_SIMPLE)         /*Or simply include lv_conf.h is enabled*/
        #include "lv_conf.h"
    #else
        #include "lv_conf.h"                //(prior to that this line had "../../lv_conf.h" remove the ../../)//
    #endif
```
> taken from:[m5core2-lvgl8-SquarelineStudio-PlatformIO](https://github.com/OzInFl/m5core2-lvgl8-SquarelineStudio-PlatformIO)

# Acknowledgments
- [BlueMagic32](https://github.com/schoolpost/BlueMagic32) 
- [BMPCC_Remote_Esp32](https://github.com/creacominc/BMPCC_Remote_Esp32)
- [m5core2-lvgl8-SquarelineStudio-PlatformIO](https://github.com/OzInFl/m5core2-lvgl8-SquarelineStudio-PlatformIO)
- https://forum.m5stack.com/topic/3613/how-to-run-lvgl-on-m5stack
- https://macsbug.wordpress.com/2021/07/05/co2-monitor-with-m5stack-and-lvgl/
- https://macsbug.wordpress.com/2021/07/03/lvgl-with-m5stack-part-2/