#include "data_analysis.h"
#include "latin_representation.h"

#ifndef MORSE_ALPHABET_DETECTION
#define MORSE_ALPHABET_DETECTION

#define SMALL_INTERVAL      1
#define MEDIUM_INTERVAL     3
#define LONG_INTERVAL       7
#define ERROR_MORSE_CODING  -1
#define ERROR_LATIN_CODING  -2

int handle_down_duration(int DOWN_DURATION, char *TEXT, int *TEXT_ID, node **CURR_NODE, int *PROGRAM_STATE);
int handle_up_duration(int DOWN_DURATION, char *TEXT, int *TEXT_ID, node **CURR_NODE, int *PROGRAM_STATE);

#endif
