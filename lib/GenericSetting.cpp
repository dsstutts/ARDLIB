#include "GenericSetting.h"

template<>
byte GenericSetting<int>::parseData(char* data)
{
}

template<class T>
byte GenericSetting<T>::parseData(char* data)
{
  return -1;
}
