#include "morse_alphabet_detection.h"
/** NULL */
#include <stdlib.h>

int handle_down_duration(int DOWN_DURATION, char *TEXT, int *TEXT_ID, node **CURR_NODE, int *PROGRAM_STATE) {
  switch(DOWN_DURATION) {
    case 0:
      return 0;
    case SMALL_INTERVAL:
      return SMALL_INTERVAL;
    case MEDIUM_INTERVAL:
      TEXT[*TEXT_ID] = (char) ((*CURR_NODE) -> value);
      *CURR_NODE = MORSE;
      *TEXT_ID = *TEXT_ID + 1;
      return MEDIUM_INTERVAL;
    case LONG_INTERVAL:
      TEXT[*TEXT_ID] = (char) ((*CURR_NODE) -> value);
      *CURR_NODE = MORSE;
      *TEXT_ID = *TEXT_ID + 1;
      TEXT[*TEXT_ID] = ' ';
      *TEXT_ID = *TEXT_ID + 1;
      return LONG_INTERVAL;
    default:
      *PROGRAM_STATE = WRITE_TEXT_T;
      return ERROR_MORSE_CODING;
  }
  return 0;
}

int handle_up_duration(int UP_DURATION, char *TEXT, int *TEXT_ID, node **CURR_NODE, int *PROGRAM_STATE) {
  switch(UP_DURATION) {
    case 0:
      return 0;
    case SMALL_INTERVAL:
      if((*CURR_NODE) -> dot != NULL) {
        *CURR_NODE = (*CURR_NODE) -> dot;
        return SMALL_INTERVAL;
      }
      else {
        *CURR_NODE = MORSE;
        *PROGRAM_STATE = WRITE_TEXT_T;
        return ERROR_LATIN_CODING;
      }
    case MEDIUM_INTERVAL:
      if((*CURR_NODE) -> dash != NULL) {
        *CURR_NODE = (*CURR_NODE) -> dash;
        return MEDIUM_INTERVAL;
      }
      else {
        *CURR_NODE = MORSE;
        *PROGRAM_STATE = WRITE_TEXT_T;
        return ERROR_LATIN_CODING;
      }
    default:
      *PROGRAM_STATE = WRITE_TEXT_T;
      return ERROR_MORSE_CODING;
  }
}
