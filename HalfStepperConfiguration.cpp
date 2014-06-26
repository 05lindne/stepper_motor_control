
#include "HalfStepperConfiguration.h"

#include <Arduino.h>


HalfStepperConfiguration::HalfStepperConfiguration()	{

	add_pin("micropin1", new Pin(8, "micropin1", HIGH, HIGH, LOW, -1, OUTPUT));
	add_pin("micropin2", new Pin(9, "micropin2", LOW, HIGH, LOW, -1, OUTPUT));
}
