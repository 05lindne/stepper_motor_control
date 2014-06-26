#include <StandardCplusplus.h>
// #include <Arduino.h>
// #include <map>
#include "KeyboardController.h"


const unsigned int baud_rate = 9600;
char sig = 'w';

KeyboardMotorController* controller;


void setup(){

	while (!Serial){;}

	Serial.begin(baud_rate);

	controller = new KeyboardMotorController();

	controller->read_signal('s');
	controller->read_signal('s');
	controller->read_signal('d');

}

void loop(){



	if (Serial.available() > 0 ) {

		sig = Serial.read();
		controller->read_signal(sig);

	}

}

