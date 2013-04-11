#include "GenericSetting.h"
#include <stdlib.h>

template<>
byte GenericSetting<int>::parseData(char* data)
{
  *var = atoi(data);
}

template<>
byte GenericSetting<float>::parseData(char* data)
{
  *var = atof(data);
}

template<class T>
byte GenericSetting<T>::parseData(char* data)
{
  return NOT_IMPLEMENTED;
}

