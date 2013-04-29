#ifndef STATE_H
#define STATE_H

#include "types.h"

struct State
{
  State() : state(COMMAND), sz(0) {}

  typedef enum {COMMAND, INDEX, VALUE} states;
  states state; 

  byte sz;
  char buf[SETTING_BUF_SZ];

  byte index;
};

#endif

