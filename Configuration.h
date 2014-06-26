#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "BasicPinConfiguration.h"
#include "FullStepperConfiguration.h"
#include "HalfStepperConfiguration.h"
#include "QuarterStepperConfiguration.h"
#include "EightStepperConfiguration.h"

PinConfiguration* make_full_step_configuration() {

	return new FullStepperConfiguration();
}

PinConfiguration* make_half_step_configuration() {

	return new HalfStepperConfiguration();
}

PinConfiguration* make_quarter_step_configuration() {

	return new QuarterStepperConfiguration();
}

PinConfiguration* make_eight_step_configuration() {

	return new EightStepperConfiguration();
}

PinConfiguration* make_basic_pin_configuration() {

	return new BasicPinConfiguration();
}

#endif