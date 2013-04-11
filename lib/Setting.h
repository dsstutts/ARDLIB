#ifndef SETTING_H
#define SETTING_H

#include "types.h"

class Setting
{
  public:
    Setting(char* n): name(n) {}

    char* getName();

    virtual byte parseData(char* data) = 0;

  private:
    char* name;
};

#endif

