// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "prototype.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
	#include "audio.h"
#endif
#ifdef BACKLIGHT_ENABLE
	#include "backlight.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
	_QWERTY,
	_COLEMAK,
	_DVORAK,
	_LOWER,
	_RAISE,
	_PLOVER,
	_ADJUST
};

enum planck_keycodes {
	QWERTY = SAFE_RANGE,
	COLEMAK,
	DVORAK,
	PLOVER,
	LOWER,
	RAISE,
	BACKLIT,
	EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty                                                                                 Sidearm
 * ,------------------------------------------------------------------------------------. ,---------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y   |   U  |   I  |   O  |   P  |  =   | | 7 | 8 | 9 | * |
 * |------+------+------+------+------+--------------+------+------+------+------+------| |---+---+---+---|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H   |   J  |   K  |   L  |   ;  |  "   | | 4 | 5 | 6 | / |
 * |------+------+------+------+------+------|-------+------+------+------+------+------| |---+---+---+---|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N   |   M  |   ,  |   .  |   /  |rsft/-| | 1 | 2 | 3 | + |
 * |------+------+------+------+------+------+-------+------+------+------+------+------| |---+---+---+---|
 * | Brite| Ctrl | Alt  | GUI  |Lower | Bksp | Space |Raise | Left | Down |  Up  |Right | | 0 | . | ⏎ | - |
 * `------------------------------------------------------------------------------------' '---+---+---+---'
 */
[_QWERTY] = PLANCK_SIDEARM(
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQUAL,					KC_P7, KC_P8,   KC_P9,   KC_PAST,
	LT(_RAISE, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,		KC_P4, KC_P5,   KC_P6,   KC_PSLS,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_MINS),	KC_P1, KC_P2,   KC_P3,   KC_PPLS,
	MO(_ADJUST), KC_LCTL, KC_LALT, LOWER, KC_LGUI, KC_BSPC, KC_SPC,  LT(_RAISE, KC_ENT),   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,	KC_P0, KC_PDOT, KC_PENT, KC_PMNS
),

/* Colemak 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower | Bksp | Space|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = PLANCK_SIDEARM(
	KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQUAL, _______, _______, _______, _______,
	LT(_RAISE, KC_ESC),  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, _______, _______, _______, _______,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, _______, _______, _______, _______,
	MO(_ADJUST), KC_LCTL, KC_LALT, LOWER, KC_LGUI,   KC_BSPC, KC_SPC,  LT(_RAISE, KC_ENT),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______
),

/* Dvorak 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower | Bksp | Space|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = PLANCK_SIDEARM(
	KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_EQUAL, _______, _______, _______, _______,
	LT(_RAISE, KC_ESC),  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, _______, _______, _______, _______,
	KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______, _______, _______, _______, _______,
	MO(_ADJUST), KC_LCTL, KC_LALT, LOWER, KC_LGUI,   KC_BSPC, KC_SPC,  LT(_RAISE, KC_ENT),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = PLANCK_SIDEARM( //TODO: remove redundant keycodes
	KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC, _______, _______, _______, _______,
	KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______,
	_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.	.---------------.
 * |   `  |   !  |   @  |   {  |   }  | PIPE |   &  |   7  |   8  |   9  |   *  | Bksp |	| ↸ |   | ↖︎ | 🔊|
 * |------+------+------+------+------+-------------+------+------+------+------+------|	|---+---+---+---|
 * |      |   #  |   $  |   (  |   )  |Ctl(b)|   +  |   4  |   5  |   6  |   -  |  \   |	| ⇲ | ↑ | ↘︎ | 🔉|
 * |------+------+------+------+------+------|------+------+------+------+------+------|	|---+---+---+---|
 * |      |   %  |   ^  |   [  |   ]  |   _  | CAPS |   1  |   2  |   3  |   0  | Enter|	| ← | ↓ | → | 🔇|
 * |------+------+------+------+------+------+------+------+------+------+------+------|	|---+---+---+---|
 * |      |      |Ctl(L)|Ctl(R)|      |      |      |Raise | Home | PGDN | PGUP |  End |	|LCK| ⇤ | ► | ⇥ |
 * `-----------------------------------------------------------------------------------'	'---+---+---+---'
 */
[_RAISE] = PLANCK_SIDEARM(
	KC_GRV,  KC_EXLM, KC_AT,         KC_LCBR,       KC_RCBR, KC_PIPE,    KC_AMPR, KC_7,    KC_8,    KC_9,   KC_ASTR, KC_DEL, KC_HOME, _______, KC_END,  KC_VOLU,
	_______, KC_HASH, KC_DLR,        KC_LPRN,       KC_RPRN, LCTL(KC_B), KC_PLUS, KC_4,    KC_5,    KC_6,   KC_MINS, KC_BSLS, KC_PGUP, KC_UP,   KC_PGDN, KC_VOLD,
	_______, KC_PERC, KC_CIRC,       KC_LBRC,       KC_RBRC, KC_UNDS,    KC_CAPS, KC_1,    KC_2,    KC_3,   KC_0,    KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE,
	_______, _______, LCTL(KC_LEFT), LCTL(KC_RGHT), _______, _______,    _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP,  KC_END, LCAG(KC_Q), KC_MPRV, KC_MPLY, KC_MNXT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = PLANCK_SIDEARM(
	_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL , _______, _______, _______, _______,
	_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______, _______, _______, _______, _______,
	_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, BACKLIT, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______
)


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
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
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case RAISE:
			if (record->event.pressed) {
				layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case BACKLIT:
			if (record->event.pressed) {
				register_code(KC_RSFT);
				#ifdef BACKLIGHT_ENABLE
					backlight_step();
				#endif
			} else {
				unregister_code(KC_RSFT);
			}
			return false;
			break;
		case PLOVER:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					stop_all_notes();
					PLAY_NOTE_ARRAY(tone_plover, false, 0);
				#endif
				layer_off(_RAISE);
				layer_off(_LOWER);
				layer_off(_ADJUST);
				layer_on(_PLOVER);
				if (!eeconfig_is_enabled()) {
						eeconfig_init();
				}
				keymap_config.raw = eeconfig_read_keymap();
				keymap_config.nkro = 1;
				eeconfig_update_keymap(keymap_config.raw);
			}
			return false;
			break;
		case EXT_PLV:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
				#endif
				layer_off(_PLOVER);
			}
			return false;
			break;
	}
	return true;
}

void matrix_init_user(void) {
		#ifdef AUDIO_ENABLE
				startup_user();
		#endif
}

#ifdef AUDIO_ENABLE

void startup_user() {
		_delay_ms(20); // gets rid of tick
		PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user(){
		PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
		_delay_ms(150);
		stop_all_notes();
}

void music_on_user(void)
{
		music_scale_user();
}

void music_scale_user(void)
{
		PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
			switch(id) {
				case 0:
					if (record->event.pressed) {
						register_code(KC_RSFT);
						#ifdef BACKLIGHT_ENABLE
							backlight_step();
						#endif
					} else {
						unregister_code(KC_RSFT);
					}
				break;
			}
		return MACRO_NONE;
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {
	
	}
}