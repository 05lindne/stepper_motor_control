#ifndef MICRO_STEPPER_H
#define MICRO_STEPPER_H

#include "PinConfiguration.h"

class MicroStepper {
	
	public:

		typedef PinConfiguration::value_type value_type;
		typedef PinConfiguration::id_type id_type;
		typedef PinConfiguration::name_type name_type;
		typedef PinConfiguration::pin_type pin_type;
		typedef PinConfiguration pin_configuration_type;

	private:
		
		unsigned int delay_high_to_low;
		unsigned int delay_low_to_high;
		bool locked;
		name_type name;
		unsigned short number_of_steps;
		PinConfiguration* basic_pins;
		PinConfiguration* micro_pins;
		
	public:

		MicroStepper(PinConfiguration* micro, PinConfiguration* basic, name_type s = "", unsigned int delay_l_h = 0, unsigned int delay_h_l = 0, unsigned short steps = 1, bool initially_locked = false);
		~MicroStepper();

		void set_forward_direction();
		void set_backward_direction();
		void do_step();
		void set_micro_pins(PinConfiguration* pins);

		void sleep();
		void unsleep();

		void lock();
		void unlock();
		bool is_locked() const;

		void set_name(name_type s);
		void display_name(name_type s = "") const;
		void set_steps(unsigned short steps = 1);
};

#endif