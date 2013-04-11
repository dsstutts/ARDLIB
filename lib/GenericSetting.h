#ifndef GENERIC_SETTING_H
#define GENERIC_SETTING_H

#include "Setting.h"
#include "types.h"

template<class T>
class GenericSetting: public Setting
{
  public:
    GenericSetting(char* name, T* variable): Setting(name), var(variable) {}
    byte parseData(char* data);

  private:
    T* var;
};

#endif

