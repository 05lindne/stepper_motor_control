
#include "QuarterStepperConfiguration.h"

#include <Arduino.h>


QuarterStepperConfiguration::QuarterStepperConfiguration()	{

	add_pin("micropin1", new Pin(8, "micropin1", LOW, HIGH, LOW, -1, OUTPUT));
	add_pin("micropin2", new Pin(9, "micropin2", HIGH, HIGH, LOW, -1, OUTPUT));
}