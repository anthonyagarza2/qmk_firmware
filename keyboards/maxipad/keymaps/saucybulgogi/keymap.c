#include "maxipad.h"

#define _BASE 0
#define _FN 1
#define _RGB 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = KEYMAP( /* Base */
  KC_ESC,  KC_1,    KC_2,  KC_3,  KC_4,  KC_5, \
  KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R,  KC_T, \
  KC_LGUI,   KC_A,    KC_S,  KC_D,  KC_F,  KC_G, \
  KC_LSFT, KC_Z,    KC_X,  KC_C,  KC_V,  KC_B, \
  MO(_RGB), KC_LCTL, KC_LALT, KC_ENT,KC_NO,LT(_FN, KC_SPC) \
),
[_FN] = KEYMAP(
  KC_GRV,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, \
  KC_TRNS, KC_TRNS, KC_PGUP, KC_UP, KC_PGDN, KC_VOLU, \
  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_VOLD, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS   \
),
[_RGB] = KEYMAP(
  RGB_TOG,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
  KC_NO,  KC_NO, KC_NO, RGB_VAI, RGB_SAI, RGB_HUI, \
  KC_NO,  KC_NO, KC_NO, RGB_VAD, RGB_SAD, RGB_HUD, \
  KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
  KC_NO,  KC_NO, MO(_RGB), KC_NO, KC_NO, RGB_MOD \
)
};
 
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // MACRODOWN only works in this function
{
  return MACRO_NONE;
};

const uint16_t PROGMEM fn_actions[] = {
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
  }
}