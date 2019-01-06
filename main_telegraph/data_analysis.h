#include "muscle_activity.h"

#ifndef DATA_ANALYSIS
#define DATA_ANALYSIS

#define ONE_SECOND 1000
#define DOT_CHUNK_DURATION (2 * (ONE_SECOND / (PROBING_DELAY * PROBING_CYCLE))) // 2 seconds duration

/** program states */
#define IDLE_T            0
#define GATHER_DATA_T     1
#define WRITE_TEXT_T      2
#define READ_DATA_DELAY   3

int MORSE_READ_ACTIVATION_TIME;
int PROGRAM_STATE;

int UP_DURATION;
int DOWN_DURATION;

int sensor_read_requirements(double deviation, int *PROGRAM_STATE, int *ACTIVE_MUSCLE_TIME);
int sensor_read_delay(int *PROGRAM_STATE, int *ACTIVE_MUSCLE_TIME);
int sensor_read_gather_data(double deviation, int *ACTIVE_MUSCLE_TIME, int *INACTIVE_MUSCLE_TIME);

#endif
