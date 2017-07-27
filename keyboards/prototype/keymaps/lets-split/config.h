#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

/* Lets split v1 pin out */
#define MATRIX_ROW_PINS { B5, B4, E6, D7 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, F0, F0, F0, F0, F0, F0 }
#define CATERINA_BOOTLOADER

#define BACKLIGHT_PIN B7
/* number of backlight levels */
#define BACKLIGHT_LEVELS 3

/* ws2812 RGB LED */
#define RGB_DI_PIN B2
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12     // Number of LEDs
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define USB_MAX_POWER_CONSUMPTION 100

#define SERIAL_PIN_DDR DDRD
#define SERIAL_PIN_PORT PORTD
#define SERIAL_PIN_INPUT PIND
#define SERIAL_PIN_MASK _BV(PD0)
#define SERIAL_PIN_INTERRUPT INT0_vect

#define USE_SERIAL

#define MASTER_LEFT

#define USE_PRO_MICRO

#endif