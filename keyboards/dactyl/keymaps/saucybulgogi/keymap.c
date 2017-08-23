#include "dactyl.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _ADJUST 16

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	COLEMAK,
	DVORAK,
	LOWER,
	ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------,                           ,-------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |                           |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | lower  |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |   ;  |  ' "   |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |                           |   N  |   M  |   ,  |   .  |  /   | RShift |
 * |--------+------+------+------+------+------|                           `------+------+------+------+------+--------|
 * |Adjust  |  `~  | Lalt | Ctrl + Left | Ctrl + Right|                                         |  Up  | Down |   [  |   ]  | Adjust |
 * `------------------------------------'                                         `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MNXT | Ctrl |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  Tab |       | PLY  |        |      |
 *                                 | lGui |Backsp|------|       |------|  Space | Enter|
 *                                 |      |ace   |  DEL |       |Lower |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_QWERTY] = DACTYL( \
	KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, \
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSLS, \
	LOWER,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
	ADJUST,  KC_GRV,  KC_LALT, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_LCTL, KC_ESC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, ADJUST,  \
	GUI_T(KC_TAB), KC_BSPC, KC_DEL,   KC_TAB, KC_MNXT, KC_NO,   KC_NO,   KC_LALT, KC_MPLY, LOWER,   KC_SPC,  KC_ENT \
),

 /* Keymap 0: Colemak layer
 *
 * ,-------------------------------------------,                           ,-------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |                           |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
 * | tab    |   Q  |   W  |   F  |   P  |   G  |                           |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | LGui   |   A  |   R  |   S  |   T  |   D  |                           |   H  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |                           |   K  |   M  |   ,  |   .  |   /  | RShift |
 * |--------+------+------+------+------+------|                           `------+------+------+------+------+--------|
 * |Grv/L1  |  `~  | Lalt | Left | Right|                                         |  Up  | Down |   [  |   ]  | ~L1    |
 * `------------------------------------'                                         `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MNXT | Ctrl |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  {   |       | PLY  |        |      |
 *                                 | Tab  |Backsp|------|       |------|  Enter | Space|
 *                                 |      |ace   |  DEL |       |Lower |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_COLEMAK] = DACTYL( \
	KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
	KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
	LOWER,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
	ADJUST,  KC_GRV,  KC_LALT, KC_LEFT, KC_RGHT, KC_MNXT, KC_ESC,  KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, ADJUST,  \
	GUI_T(KC_TAB), KC_BSPC, KC_DEL,  KC_LALT, KC_LCTL, KC_NO,   KC_NO,   KC_LALT, KC_MPLY, LOWER,   KC_SPC,  KC_ENT \
),

 /* Keymap 0: Dvorak layer
 *
 * ,-------------------------------------------,                           ,-------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |                           |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
 * | Del    |   "  |   ,  |   .  |   P  |   Y  |                           |   F  |   G  |   C  |   R  |   L  |   \    |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | LGui   |   A  |   O  |   E  |   U  |   I  |                           |   D  |   H  |   T  |   N  |   S  |  esc   |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |                           |   B  |   M  |   W  |   V  |   Z  | RShift |
 * |--------+------+------+------+------+------|                           `------+------+------+------+------+--------|
 * | Adjsut |  `~  | Lalt | Left | Right|                                         |  Up  | Down |   [  |   ]  | Adjust |
 * `------------------------------------'                                         `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MNXT | Ctrl |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  {   |       | PLY  |        |      |
 *                                 | Tab  |Backsp|------|       |------|  Space | Enter|
 *                                 |      |ace   |  DEL |       |Lower |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_DVORAK] = DACTYL( \
	KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
	KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS, \
	LOWER,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ESC,  \
	KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
	ADJUST,  KC_GRV,  KC_LALT, KC_LEFT, KC_RGHT, KC_MNXT, KC_ESC,  KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, ADJUST,  \
	GUI_T(KC_TAB), KC_BSPC, KC_DEL,  KC_LALT, KC_LCTL, KC_NO,   KC_NO,   KC_LALT, KC_MPLY, LOWER,   KC_SPC,  KC_ENT \
),

 /* Keymap 0: Lower layer
 *
 * ,-------------------------------------------,                           ,-------------------------------------------.
 * |        |  F1  |   F2 |  F3  |  F4  |  F5  |                           |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                           | VOLU | home |  Up  | End  |      |   F12  |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                           | VOLD | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * |        |      |      | CAPS |      |      |                           |      | MPRV | MPLY | MNXT |      |        |
 * |--------+------+------+------+------+------|                           `------+------+------+------+------+--------|
 * |        |      |      |      |      |                                         |      |      |      |      |        |
 * `------------------------------------'                                         `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Tab  |Backsp|------|       |------|  space | enter|
 *                                 |      |ace   |Lower |       |Lower |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_LOWER] = DACTYL( \
	_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
	_______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_VOLU, KC_7,    KC_8,    KC_9,    KC_PAST, KC_F12, \
	_______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_VOLD, KC_4,    KC_5,    KC_6,    KC_PLUS, _______, \
	_______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_CAPS, KC_1,    KC_2,    KC_3,    KC_0,    _______, \
	_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, \
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

 /* Keymap 0: Adjust layer */
[_ADJUST] =  DACTYL( \
	_______, RESET,   _______, _______, _______, _______, _______, _______,    _______,    _______, _______, KC_DEL, \
	_______, QWERTY,  _______, AU_ON,   AU_OFF,  AG_NORM, _______, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  _______, _______, \
	_______, _______, _______, DVORAK,  _______, AG_SWAP, _______, KC_MS_LEFT,	KC_MS_DOWN, KC_MS_RIGHT, _______, _______, \
	_______, _______, _______, COLEMAK, _______, _______, _______, _______,	   _______,    _______, _______, _______, \
	_______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, \
	_______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
				#endif
				persistant_default_layer_set(1UL<<_QWERTY);
			}
			return false;
			break;
		case COLEMAK:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_NOTE_ARRAY(tone_colemak, false, 0);
				#endif
				persistant_default_layer_set(1UL<<_COLEMAK);
			}
			return false;
			break;
		case DVORAK:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
				#endif
				persistant_default_layer_set(1UL<<_DVORAK);
			}
			return false;
			break;
		case LOWER:
			if (record->event.pressed) {
				layer_on(_LOWER);
			} else {
				layer_off(_LOWER);
			}
			return false;
			break;
		case ADJUST:
			if (record->event.pressed) {
				layer_on(_ADJUST);
			} else {
				layer_off(_ADJUST);
			}
			return false;
			break;
	}
	return true;
}