#include "DataLogger.h"

byte addSeries(byte index, char* name);
byte write(byte series, double value);

byte addIntSetting(byte index, char* name, int* variable);
byte addFloatSetting(byte index, char* name, float* variable);

byte writeSeries();
byte writeSettings();


