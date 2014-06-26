
#include "BasicPinConfiguration.h"

#include <Arduino.h>

BasicPinConfiguration::BasicPinConfiguration()	{

	add_pin("direction", new Pin(10, "direction", LOW, HIGH, LOW, -1, OUTPUT));
	add_pin("step", new Pin(11, "step", LOW, HIGH, LOW, -1, OUTPUT));
	add_pin("sleep", new Pin(12, "sleep", HIGH, HIGH, LOW, -1, OUTPUT));

}