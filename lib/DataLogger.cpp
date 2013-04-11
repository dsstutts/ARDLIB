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
  
  return 0;
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

byte DataLogger::addIntSetting(byte index, char* name, int* variable)
{
  return addSetting(index, new GenericSetting<int>(name, variable));
}

byte DataLogger::addFloatSetting(byte index, char* name, float* variable)
{
  return addSetting(index, new GenericSetting<float>(name, variable));
}

byte DataLogger::addSetting(byte index, Setting* setting)
{
  if(index >= NUM_SETTINGS)
  {
    delete setting; //NOTE: Could be BAD if passed a pointer to a non-dynamic object
    return OUT_OF_RANGE;
  }
  
  if(settings[index] != NULL)
  {
    delete settings[index];
    settings_cnt--;
  }

  settings[index] = setting;
  settings_cnt++;

  return 0;
}

byte DataLogger::writeSeries()
{
  for(byte i = 0; i < NUM_SERIES; i++)
  {
    if(series[i] != NULL)
    {
      Serial.print(i);
      Serial.print(',');
      Serial.println(series[i]->getName());
    }
  }
  return 0;
}

byte DataLogger::writeSettings()
{
  for(byte i = 0; i < NUM_SETTINGS; i++)
  {
    if(settings[i] != NULL)
    {
      Serial.print(i);
      Serial.print(',');
      Serial.println(settings[i]->getName());
    }
  }

  return 0;
}

