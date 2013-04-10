#ifndef DATALOGGER_H
#define DATALOGGER_H

#ifndef NUM_SERIES
#define NUM_SERIES 16
#endif

#ifndef NUM_SETTINGS
#define NUM_SETTINGS 16
#endif

typedef unsigned char byte;

class DataLogger
{
  public:
    DataLogger() : series_cnt(0), settings_cnt(0) {}

    byte addSeries(byte index, char* name);
    byte write(byte series, double value);

    byte addIntSetting(byte index, char* name, int* variable);
    byte addFloatSetting(byte index, char* name, float* variable);
    
    byte writeSeries();
    byte writeSettings();

  protected:
    Series series[NUM_SERIES];
    byte series_cnt;

    Setting settings[NUM_SETTINGS];
    byte settings_cnt;
};

#endif
