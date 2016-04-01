#include "dbkeyboard.h"
uint8_t ledmap[80][8] = {{77},{78},{79},{80},{81},{82,83},{84},{85},{86},{87},{88},{89},{90},{91},{92,93,94},{95},
															{76},{75,74},{73},{72},{71},{70},{69},{68},{67},{66,65},{64},{63},{62},{61},{60,59},{58},
															{39},{40, 41},{42},{43},{44},{45},{46},{47,48},{49},{50},{51},{52},{53},{54, 55, 56}, {0}, {57},
															 {38}, {37, 36}, {35}, {34, 33}, {33}, {32, 31}, {30}, {29}, {28}, {27}, {26}, {25,24}, {23,22}, {0}, {21}, {20},
															 {1}, {2}, {3,4}, {4,5}, {0}, {0}, {6,7,8,9,10,11,12}, {0}, {0}, {0}, {13,14}, {14,15}, {15,16}, {16,17}, {18}, {19}};

__attribute__ ((weak))
void * matrix_init_user(void) {
	// leave these blank

};

__attribute__ ((weak))
void * matrix_scan_user(void) {
	// leave these blank
};

void * matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	if (matrix_init_user) {
		(*matrix_init_user)();
		rgblight_init();
	}
};

void * matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	if (matrix_scan_user) {
		(*matrix_scan_user)();
	}
};

void * action_key_pressed(keyrecord_t *record) {
	rgblight_effect_localised(ledmap[(record->event.key.row * MATRIX_COLS) + record->event.key.col]);
}
