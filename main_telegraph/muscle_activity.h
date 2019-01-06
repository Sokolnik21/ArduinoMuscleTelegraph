#ifndef MUSCLE_ACTIVITY
#define MUSCLE_ACTIVITY

/**
 * multiplication of PROBING_DELAY and PROBING_CYCLE must be the divisor of 1000
 *
 * Each 200 miliseconds program can tell whether the muscle is active or not
 * time needed to estimate muscle state = PROBING_DELAY * PROBING_CHUNK
 */
#define PROBING_DELAY 5     // delay between reading data from sensor (in miliseconds)
#define PROBING_CYCLE 40    // quantity of data taken into consideration to determine the state of a muscle

#define ACTIVE    1
#define INACTIVE  0

#define MUSCLE_THRESHOLD 70

int NO_OF_CURR_SAMP_CYCLE;
int VALUES[PROBING_CYCLE];

int ACTIVE_MUSCLE_TIME;
int INACTIVE_MUSCLE_TIME;

double get_mean_value(int* table, int table_size);
double get_standard_deviation(int* table, int table_size, double mean);
double get_simple_deviation(int* table, int table_size, double mean);

int determine_muscle_state(int deviation);

#endif
