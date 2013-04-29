#include "DataLogger.h"

int iset;
int run = 1;
float fset;
float angle = 0;

DataLogger dl;

void setup()
{
	Serial.begin(115200);
	dl.addSeries(0, "asdf");
	dl.addSeries(1, "intsettingstream");
	dl.addSeries(2, "sine");
	dl.addIntSetting("intsetting", &iset);
	dl.addFloatSetting("floatsetting", &fset);
	dl.addIntSetting("run", &run);
}

void loop() 
{
	if(run)
	{
		dl.write(0, 4.5);
		dl.write(1, iset);
		dl.write(2, sin(angle));
		angle += 0.1;
	}
}

