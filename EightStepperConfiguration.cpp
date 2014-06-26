
#include "EightStepperConfiguration.h"

#include <Arduino.h>


EightStepperConfiguration::EightStepperConfiguration()	{

	add_pin("micropin1", new Pin(8, "micropin1", HIGH, HIGH, LOW, -1, OUTPUT));
	add_pin("micropin2", new Pin(9, "micropin2", HIGH, HIGH, LOW, -1, OUTPUT));
}