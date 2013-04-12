#include "DataLogger.h"

int iset;
float fset;

DataLogger dl;

void setup()
{
	dl.addSeries(0, "asdf");
	dl.addIntSetting("intsetting", &iset);
	dl.addFloatSetting("floatsetting", &fset);
}

void loop() 
{
	dl.write(0, 4.5);
}

