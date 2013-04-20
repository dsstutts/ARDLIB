#include "DataLogger.h"

DataLogger* __dl = NULL;

void serialEvent()
{
  Serial.println("WOOOOOOOO");
}

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

  __dl = this;
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
  Serial.print(',');
  Serial.print(millis());
  Serial.print(',');
  Serial.println(value);

  return 0;
}

byte DataLogger::addIntSetting(char* name, int* variable)
{
  return addSetting(new GenericSetting<int>(name, T_INT, variable));
}

byte DataLogger::addFloatSetting(char* name, float* variable)
{
  return addSetting(new GenericSetting<float>(name, T_FLOAT, variable));
}

byte DataLogger::addSetting(Setting* setting)
{
  if(settings_cnt++ >= NUM_SETTINGS)
  {
    delete setting; //NOTE: Could be BAD if passed a pointer to a non-dynamic object
    settings_cnt--;
    return OUT_OF_RANGE;
  }
 
  settings[settings_cnt] = setting;

  return 0;
}

byte DataLogger::setSetting(byte setting, char* val)
{
  if(setting > NUM_SETTINGS || settings[setting] == NULL)
  {
    return OUT_OF_RANGE;
  }

  return settings[setting]->parseData(val);
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
      Serial.print(settings[i]->getName());
      Serial.print(',');
      Serial.println(settings[i]->getType());
    }
  }

  return 0;
}

