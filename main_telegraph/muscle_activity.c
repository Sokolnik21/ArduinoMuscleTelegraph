#include "muscle_activity.h"
/** pow(), sqrt() */
#include <math.h>
/** abs() */
#include <stdlib.h>   // prototype of abs() is actually in stdlib.h library

/**
 * There can be bug that can be hard to see:
 * if there is too much data from sensors then there is possibility that mean can be wrongly evaluated
 * Why?
 * if values from sensors are small (1 - 10) then:
 * - for small amount of data we've got sum of this calculations: 1 / 10 = 0.1
 * - for large amount of data we've got sum of this calculations: 1 / 10e9 = 10e-9 = 0
 *
 * Cheezy solution is to sum all the data and only then divide the result.
 * However this also have flaws because this approach can lead to an overflow.
 */
double get_mean_value(int* table, int table_size) {
  double mean = 0;
  for(int i = 0; i < table_size; i++)
    mean += (double)table[i] / table_size;
  return mean;
}

double get_standard_deviation(int* table, int table_size, double mean) {
  double deviation = 0;
  for(int i = 0; i < table_size; i++)
    deviation += pow( (double)table[i] - mean, 2 ) / (table_size - 1);
  deviation = sqrt(deviation);
  return deviation;
}
double get_simple_deviation(int* table, int table_size, double mean) {
  double deviation = 0;
  for(int i = 0; i < table_size; i++)
    deviation += abs( (double)table[i] - mean ) / (table_size - 1);
  deviation = sqrt(deviation);
  return deviation;
}

int determine_muscle_state(int deviation) {
  if(deviation > MUSCLE_THRESHOLD)
    return ACTIVE;
  else
    return INACTIVE;
}
