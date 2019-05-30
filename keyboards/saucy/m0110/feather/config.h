#ifndef FEATHER_CONFIG_H
#define FEATHER_CONFIG_H

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
//TODO: set up row  and cols
#define MATRIX_ROW_PINS {F7, F6, F5, F4, F1}
#define MATRIX_COL_PINS {}
#define UNUSED_PINS

#endif
