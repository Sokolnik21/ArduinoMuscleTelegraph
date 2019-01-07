extern "C" {
  #include "latin_representation.h"
  #include "muscle_activity.h"
  #include "morse_alphabet_detection.h"
  #include "data_analysis.h"
}

#define SENSOR_PIN A0
#define TEXT_SIZE 100

/** TABLE TO STORE RESULT STRING */
char  TEXT[TEXT_SIZE];
int   TEXT_ID = 0;

/** main function */
void setup() {
  Serial.begin(9600);

  MORSE = create_morse_tree();
  CURR_NODE = MORSE;

  MORSE_READ_ACTIVATION_TIME = 0;
  PROGRAM_STATE = IDLE_T;

  NO_OF_CURR_SAMP_CYCLE = 0;
  ACTIVE_MUSCLE_TIME = 0;
  INACTIVE_MUSCLE_TIME = 0;
  
  UP_DURATION = 0;
  DOWN_DURATION = 0;
  
  for(int i = 0; i < TEXT_SIZE; i++)
    TEXT[i] = '\0';
}
    
void loop() {  
  /** Read value from sensor */
  int sensor_value = analogRead(SENSOR_PIN);
  double deviation;

  if(NO_OF_CURR_SAMP_CYCLE == PROBING_CYCLE) {
    double mean = get_mean_value(VALUES, PROBING_CYCLE);
    deviation = get_standard_deviation(VALUES, PROBING_CYCLE, mean);

//    /** To test deviation and tell the difference between active and inactive state */
//    Serial.println(deviation);

    /** Analyse data (deviation) */  
    switch(PROGRAM_STATE) {
      case IDLE_T:
        /** after a duration of DOT_CHUNK_DURATION of muscle activity a program state will change to READ_DATA_DELAY */
        if(sensor_read_requirements(deviation, &PROGRAM_STATE, &ACTIVE_MUSCLE_TIME) == 1)
          Serial.println("Data will be read after 2 seconds...");
        break;
      case READ_DATA_DELAY:
        /** after a duration of DOT_CHUNK_DURATION a program state will change to GATHER_DATA_T */
        if(sensor_read_delay(&PROGRAM_STATE, &MORSE_READ_ACTIVATION_TIME) == 1)
          Serial.println("Reading data from sensor...");
        break;
      case GATHER_DATA_T:
        sensor_read_gather_data(deviation, &ACTIVE_MUSCLE_TIME, &INACTIVE_MUSCLE_TIME);
        if(ACTIVE_MUSCLE_TIME + INACTIVE_MUSCLE_TIME == DOT_CHUNK_DURATION) {
          if(ACTIVE_MUSCLE_TIME > INACTIVE_MUSCLE_TIME) {
            Serial.println("ACTIVE");
            switch(handle_down_duration(DOWN_DURATION, TEXT, &TEXT_ID, &CURR_NODE, &PROGRAM_STATE)) {
              case ERROR_MORSE_CODING:
                Serial.println("Wrong representation of morse sign");
                UP_DURATION = 0;
                break;
              default:
                UP_DURATION++;
            }
            DOWN_DURATION = 0;
          }
          else {
            Serial.println("inactive");
            switch(handle_up_duration(UP_DURATION, TEXT, &TEXT_ID, &CURR_NODE, &PROGRAM_STATE)) {
              case ERROR_LATIN_CODING:
                Serial.println("Wrong representation of latin sign");
                DOWN_DURATION = 0;
                break;
              case ERROR_MORSE_CODING:
                Serial.println("Wrong representation of morse sign");
                DOWN_DURATION = 0;
                break;
              default:
                DOWN_DURATION++;
            }
            UP_DURATION = 0;
          }
          ACTIVE_MUSCLE_TIME = 0;
          INACTIVE_MUSCLE_TIME = 0;
        }
        break;
      case WRITE_TEXT_T:
        Serial.print("RESULT: ");
        Serial.println(TEXT);
        
        for(int i = 0; i < TEXT_SIZE; i++)
          TEXT[i] = '\0';
        TEXT_ID = 0;
        PROGRAM_STATE = IDLE_T;
    }
    
    NO_OF_CURR_SAMP_CYCLE = 0;
  }
  else {
    VALUES[NO_OF_CURR_SAMP_CYCLE] = sensor_value;
    NO_OF_CURR_SAMP_CYCLE++;
  }
  
  delay(PROBING_DELAY);
}
