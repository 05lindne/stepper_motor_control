#ifndef MOTORCOLLECTION_H
#define MOTORCOLLECTION_H

#include <map>

#include "MicroStepper.h"

class MotorCollection {

	public:

		typedef MicroStepper::value_type value_type;
		typedef MicroStepper::id_type id_type;
		typedef MicroStepper::name_type name_type;
		typedef MicroStepper::pin_type pin_type;
		typedef MicroStepper::pin_configuration_type pin_configuration_type;

	private:

		std::map < name_type, pin_configuration_type* > pin_configuration;
		std::map < name_type, MicroStepper* > motor;

		std::map < name_type, pin_configuration_type* >::iterator config_it;
		std::map < name_type, MicroStepper* >::const_iterator const_motor_it;
		std::map < name_type, MicroStepper* >::iterator motor_it;


	public:

		MotorCollection();
		~MotorCollection();

		void set_forward( name_type key );
		void set_backward( name_type key );
		void do_step( name_type key );
		void set_pin_configuration( name_type key_motor, name_type key_config );
		void set_pin_configuration_all( name_type key_config );
		void sleep( name_type key );
		void unsleep( name_type key );
		void lock( name_type key );
		void unlock( name_type key );
		void lock_all();
		void unlock_all();
		void reset();
		void display_name(name_type s) const; 
		std::map < name_type, MicroStepper* >::iterator find( name_type key );

	private:

		void setup();
};

#endif