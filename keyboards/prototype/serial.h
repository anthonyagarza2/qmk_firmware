#ifndef MY_SERIAL_H
#define MY_SERIAL_H

#include "config.h"
#include <stdbool.h>
#include "matrix.h"

#define SERIAL_SLAVE_BUFFER_LENGTH MATRIX_ROWS/2
#define SERIAL_MASTER_BUFFER_LENGTH 1

// Buffers for master - slave communication
extern volatile matrix_row_t serial_slave_buffer[SERIAL_SLAVE_BUFFER_LENGTH];
extern volatile matrix_row_t serial_master_buffer[SERIAL_MASTER_BUFFER_LENGTH];

void serial_master_init(void);
void serial_slave_init(void);
int serial_update_buffers(void);
bool serial_slave_data_corrupt(void);

#endif
