#ifndef DATALOGGER_H
#define DATALOGGER_H

/** 
 * The maxiumum number of data streams. 
 * To change, simply define NUM_SERIES before including DataLogger.h.
 */
#ifndef NUM_SERIES
#define NUM_SERIES 8
#endif

/**
 * The maximum number of custom settings
 * To change, simply define NUM_SETTINGS before including DataLogger.h
 */
#ifndef NUM_SETTINGS
#define NUM_SETTINGS 8
#endif

/**
 * Buffer size for serial I/O. 
 */
#ifndef SETTING_BUF_SZ
#define SETTING_BUF_SZ 64
#endif

#include <Arduino.h>
#include "Series.h"
#include "Setting.h"
#include "GenericSetting.h"
#include "constants.h"
#include "types.h"
#include "State.h"

/**
 * serialEvent() is overridden here to do serial I/O for the library.
 * TODO: Find some way to allow user-defined serialEvent()s as well?
 */
void serialEvent();

/**
 * DataLogger
 * The interface to the library. Only one DataLogger can be created.
 * DataLogger handles serial I/O to some logging interface and all
 *  communication that interface performs to the Arduino. Usually
 *  this logging interface is the associated GUI for this library.
 *
 * Terminology:
 * Data Series - A stream of data, usually read from one sensor. 
 * Setting - A variable that can be changed by the logging interface.
 */
class DataLogger
{
  public:
    /**
     * Create a DataLogger. 
     */ 
    DataLogger();

/* DATA SERIES OPERATIONS */    

    /** 
     * Add a new data series. 
     * index: The number (between 0 and NUM_SERIES) to associate with the data stream.
     * name: The name of the data stream.
     * returns: 0 on success, OUT_OF_RANGE if index is greater than or equal to NUM_SERIES.
     */
    byte addSeries(byte index, char* name);

    /**
     * Write a value to a data series.
     * series: The number associated with the series (as chosen when calling addSeries()).
     * value: The value to write, as a double. 
     * returns: 0 on success.
     */
    byte write(byte series, double value);

/* SETTINGS OPERATIONS */

    /**
     * Add an integer setting.
     * name: A name for the setting.
     * variable: The variable that the setting will control.
     * returns: 0 on success, OUT_OF_RANGE if there are more settings than NUM_SETTINGS.
     */
    byte addIntSetting(char* name, int* variable);

    /**
     * Add a float setting. 
     * name: A name for the setting.
     * variable: The varaible that the setting will control.
     * returns: 0 on success, OUT_OF_RANGE if there are more settings than NUM_SETTINGS.
     */
    byte addFloatSetting(char* name, float* variable);

/* SERIAL I/O OPERATIONS */

    /**
     * Set the value of a particular setting.
     * Used by serial I/O. 
     * setting: index of setting to set, between 0 and NUM_SETTINGS.
     * val: Raw serial data to parse setting value from.
     * returns: 0 on success, OUT_OF_RANGE if setting is greater than or equal to NUM_SETTINGS.
     */
    byte setSetting(byte setting, char* val);

    /**
     * Write the metadata for the data series to serial.
     * returns: 0 on success.
     */
    byte writeSeries();

    /**
     * Write the settings metadata to serial.
     * returns: 0 on success.
     */
    byte writeSettings();

    State state;
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
