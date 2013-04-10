#ifndef SERIES_H
#define SERIES_H

class Series
{
  public:
    Series(char* n): name(n) {}

    char* getName();

  private:
    char* name;
};

#endif
