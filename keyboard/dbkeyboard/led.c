#include <avr/io.h>
#include "stdint.h"
#include "led.h"
#import "rgblight.h"


void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
      rgblight_capslock(1);
    } else {
      rgblight_capslock(0);
    }
}
