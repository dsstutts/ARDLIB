#include "DataLogger.h"

DataLogger::DataLogger(): series_cnt(0), settings_cnt(0) 
{
  for(byte i = 0; i < NUM_SERIES; i++)
  {
    series[i] = NULL;
  }

  for(byte i = 0; i < NUM_SETTINGS; i++)
  {
    settings[i] = NULL;
  }
}

byte DataLogger::addSeries(byte index, char* name)
{
  if(index >= NUM_SERIES)
  {
    return OUT_OF_RANGE;
  }

  if(series[index] != NULL)
  {
    delete series[index];
    series_cnt--;
  }

  series[index] = new Series(name);
  series_cnt++;
}

byte DataLogger::write(byte series, double value)
{
  Serial.print(series);
  Serial.print(",");
  Serial.print(millis());
  Serial.print(",");
  Serial.println(value);

  return 0;
}

byte addIntSetting(byte index, char* name, int* variable);
byte addFloatSetting(byte index, char* name, float* variable);

byte writeSeries();
byte writeSettings();


