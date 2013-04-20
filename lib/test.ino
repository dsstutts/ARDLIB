#include "DataLogger.h"

int iset;
float fset;

DataLogger dl;

void setup()
{
	Serial.begin(115200);
	dl.addSeries(0, "asdf");
	dl.addIntSetting("intsetting", &iset);
	dl.addFloatSetting("floatsetting", &fset);
}

void loop() 
{
	static int x = 0;
	x++;
	//dl.write(0, 4.5);
}

