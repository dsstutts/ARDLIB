#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <Arduino.h>
#include "Series.h"
#include "Setting.h"
#include "GenericSetting.h"
#include "types.h"

#ifndef NUM_SERIES
#define NUM_SERIES 16
#endif

#ifndef NUM_SETTINGS
#define NUM_SETTINGS 16
#endif

class DataLogger;

extern DataLogger* __dl;

void serialEvent();

class DataLogger
{
  public:
    DataLogger();

    byte addSeries(byte index, char* name);
    byte write(byte series, double value);

    byte addIntSetting(char* name, int* variable);
    byte addFloatSetting(char* name, float* variable);
    
    byte writeSeries();
    byte writeSettings();

  protected:
    //NOTE: may break if provided a non-dynamic setting
    byte addSetting(Setting* setting);

    //TODO: Figure out a non-malloc approach to this, although malloc isn't /terrible/ here.
    Series* series[NUM_SERIES];
    byte series_cnt;

    Setting* settings[NUM_SETTINGS];
    byte settings_cnt;
};

#endif
