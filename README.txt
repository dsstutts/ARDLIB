The DS18x20_Temperature directory contains an Arduino sketch from the DS18x20 
Library Examples located at: http://playground.arduino.cc/Learning/OneWire.
The DS18B20Simple directory contains a stripped-down version of the example
from the DS18x20_Temperature sketch which only, under normal circumstances, sends
the temperature in Fahrenheit to the USB-tethered host once a second in order to test 
the host-based Processing sketch, GraphEx2.pde

========
Arduino Library
========
Using Arduino-Makefile https://github.com/mjoldfield/Arduino-Makefile
Apparently it is available in the ubuntu repositories, but we'll add it as a submodule
	and also add a nifty script to make sure everything is happy. 
