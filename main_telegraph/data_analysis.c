#include "data_analysis.h"

int sensor_read_requirements(double deviation, int *PROGRAM_STATE, int *ACTIVE_MUSCLE_TIME) {
  if(determine_muscle_state(deviation) == 1) {
    *ACTIVE_MUSCLE_TIME = *ACTIVE_MUSCLE_TIME + 1;
  }
  else {
    *ACTIVE_MUSCLE_TIME = 0;
  }
  if(*ACTIVE_MUSCLE_TIME == DOT_CHUNK_DURATION) {
    *PROGRAM_STATE = READ_DATA_DELAY;
    *ACTIVE_MUSCLE_TIME = 0;
    return 1;
  }
  return 0;
}

int sensor_read_delay(int *PROGRAM_STATE, int *MORSE_READ_ACTIVATION_TIME) {
  *MORSE_READ_ACTIVATION_TIME = *MORSE_READ_ACTIVATION_TIME + 1;
  if(*MORSE_READ_ACTIVATION_TIME == DOT_CHUNK_DURATION) {
    *MORSE_READ_ACTIVATION_TIME = 0;
    *PROGRAM_STATE = GATHER_DATA_T;
    return 1;
  }
  return 0;
}

int sensor_read_gather_data(double deviation, int *ACTIVE_MUSCLE_TIME, int *INACTIVE_MUSCLE_TIME) {
  if(determine_muscle_state(deviation) == ACTIVE)
    *ACTIVE_MUSCLE_TIME = *ACTIVE_MUSCLE_TIME + 1;
  else
    *INACTIVE_MUSCLE_TIME = *INACTIVE_MUSCLE_TIME + 1;
  return 0;
}
