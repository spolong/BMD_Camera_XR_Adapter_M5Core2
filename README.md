# BMD Camera XR Adapter Plan

## Development Environment
- IDE[VSCode](https://github.com/microsoft/vscode)
- IoT IDE[PlatformIO](https://github.com/platformio/platformio-vscode-ide)
- [Arduino](https://github.com/arduino/Arduino)

### Hardware
- [M5StackCore2](https://github.com/m5stack/M5Core2)

### Software
- [ESP32-Arduino](https://github.com/espressif/arduino-esp32)
- [LVGL](https://github.com/lvgl/lvgl)
- [SquareLine Studio](https://docs.squareline.io/docs/squareline/)

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

Modified to work with the Squareline Studio Beta 1.1.0 beta1 
(although it may work with the current stable 1.0.5 (with lvgl8 export) as well)

******** NOTE IN ORDER TO GET A SUCESSFUL COMPILE ON PLATFORMIO, YOU MUST DO A FEW THINGS****************************************
  1) copy the lv_conf.h from the src folder into the .pio/libdeps/lvgl folder (you have to do this since the lvgl library is pulled from github)
  2) edit the .pio/libdeps/lvgl/src/misc/lv_conf_internal.h and change the line like so:
       #elif defined(LV_CONF_INCLUDE_SIMPLE)         /*Or simply include lv_conf.h is enabled*/
        #include "lv_conf.h"
    #else
        #include "lv_conf.h"                //(prior to that this line had "../../lv_conf.h" remove the ../../)//
    #endif
 *********************************************************************************************************************************
    
(Somone smarter than me will figure out how to fix this, im not a coding expert!!!)

I have included a basic interface that I am creating to test with . 

If you set your export directory in squareline to the src directory of this porject you can edit your UI and export then rebuild the Platformio project.
Finally uploading to the M5Stack COre2 Device. 

Still a work in progress, but thought it may help a few folks out there looking for a starting point. 

Im hoping that my hours of aggrivation figuring it out will help someone like me that was beating their head up against the wall!!


ORIGINAL TEXT - 


LVGL example for M5Stack Core2, Arduino and platformio

taken from:

https://forum.m5stack.com/topic/3613/how-to-run-lvgl-on-m5stack
https://macsbug.wordpress.com/2021/07/05/co2-monitor-with-m5stack-and-lvgl/
https://macsbug.wordpress.com/2021/07/03/lvgl-with-m5stack-part-2/


# Acknowledgments
- [BlueMagic32](https://github.com/schoolpost/BlueMagic32) 
- [BMPCC_Remote_Esp32](https://github.com/creacominc/BMPCC_Remote_Esp32)
- [m5core2-lvgl8-SquarelineStudio-PlatformIO](https://github.com/OzInFl/m5core2-lvgl8-SquarelineStudio-PlatformIO)