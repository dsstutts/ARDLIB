#ifndef SETTING_H
#define SETTING_H

#include "types.h"

class Setting
{
  public:
    Setting(char* n, byte t): name(n),type(t) {}

    char* getName();
    byte getType();

    virtual byte parseData(char* data) = 0;

  protected:
    char* name;
    byte type;
};

#endif

