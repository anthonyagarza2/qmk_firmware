#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

/* ws2812 RGB LED */
#define RGB_DI_PIN B2
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12     // Number of LEDs
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define BACKLIGHT_BREATHING

#define USB_MAX_POWER_CONSUMPTION 100

#endif