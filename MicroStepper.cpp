#include <Arduino.h>
#undef abs	//neutralizes an error with <StandardCPlusplus> caused by a #define abs in <Arduino.h>
			//error looks like: expected ")" before long in cstdlib

#include "MicroStepper.h"

MicroStepper::MicroStepper(PinConfiguration* micro, PinConfiguration* basic, PinConfiguration::name_type s, 
	unsigned int delay_l_h, unsigned int delay_h_l, unsigned short steps, bool initially_locked) : 
basic_pins(basic), micro_pins(micro), name(s), delay_high_to_low(delay_h_l), delay_low_to_high(delay_l_h), number_of_steps(steps), locked(initially_locked) {

	display_name("Starting initial setup\n");
	basic_pins->update_pins();
	micro_pins->update_pins();
	display_name("initial setup finished\n");

}

MicroStepper::~MicroStepper(){

	// cleanup is done by ~MotorCollection()
}

void MicroStepper::set_forward_direction() {

	if (!locked) {
		display_name("direction pin: ");
		basic_pins->set_pin_high("direction");
	}
}

void MicroStepper::set_backward_direction() {
	
	if (!locked) {
		display_name("direction pin: ");
		basic_pins->set_pin_low("direction");
	}
}

void MicroStepper::do_step() {

	if (!locked) {

		for ( unsigned int i =0; i<number_of_steps; ++i ) {
			
			display_name("step pin: ");

			if (basic_pins->is_high("step")) {

				// delayMicroseconds(delay_high_to_low);

				basic_pins->flip_pin_state("step");

				// delayMicroseconds(delay_low_to_high);

				basic_pins->flip_pin_state("step");

			
			} else {

				// delayMicroseconds(delay_low_to_high);

				basic_pins->flip_pin_state("step");

				// delayMicroseconds(delay_high_to_low);

				basic_pins->flip_pin_state("step");

			}

		}
	}
}

void MicroStepper::set_micro_pins(PinConfiguration* pins) {

	if (!locked) {

		display_name("Setting micro pins\n");
		micro_pins = pins;
		micro_pins->update_pins();
		display_name("micro pins set\n");
	}
}

void MicroStepper::display_name(PinConfiguration::name_type s) const {

	Serial.print(s);
}

void MicroStepper::sleep() {

	if (!locked) {
		display_name("sleep pin: ");
		basic_pins->set_pin_low("sleep");
	} else {
		unsleep();
	}
}

void MicroStepper::unsleep() {

	if (!locked) {
		display_name("sleep pin: ");
		basic_pins->set_pin_high("sleep");
	} else {
		sleep();
	}
}

void MicroStepper::lock() {

	if (!locked) {
		display_name("locked\n");
		locked = true;
	} else {
		unlock();
	}
}

void MicroStepper::unlock() {

	if (locked) {
		display_name("unlocked\n");
		locked = false;
	} else {
		lock();
	}
}

bool MicroStepper::is_locked() const {

	return locked;
}

void MicroStepper::set_name( name_type s){

	name = s;
}

void MicroStepper::set_steps( unsigned short steps){

	number_of_steps = steps;
}
