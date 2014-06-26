#include <Arduino.h>
#undef abs	//neutralizes an error with <StandardCPlusplus> caused by a #define abs in <Arduino.h>
			//error looks like: expected ")" before long in cstdlib


#include "MotorCollection.h"
#include "Configuration.h"
#include <cstring>

MotorCollection::MotorCollection() {

	setup();
}

MotorCollection::~MotorCollection() {

	for ( motor_it = motor.begin(); motor_it != motor.end(); ++motor_it)
		delete motor_it->second;

	for ( config_it = pin_configuration.begin(); config_it != pin_configuration.end(); ++config_it)
		delete config_it->second;
}

void MotorCollection::setup() {

	pin_configuration["full"] = make_full_step_configuration();
	pin_configuration["half"] = make_half_step_configuration();
	pin_configuration["quarter"] = make_quarter_step_configuration();
	pin_configuration["eight"] = make_eight_step_configuration();
	// ... put other possible configurations here

	// these are the basic pins. Every degree of freedom gets its own because the step pin may flip differently for different directions
	
	PinConfiguration* config = make_basic_pin_configuration(); 

	// pin_configuration["basic_x"] = make_basic_pin_configuration();
	// pin_configuration["basic_y"] = make_basic_pin_configuration();
	// pin_configuration["basic_z"] = make_basic_pin_configuration();

	pin_configuration["basic_x"] = config;
	pin_configuration["basic_y"] = config;
	pin_configuration["basic_z"] = config;

	//the next lines determine the starting configurations for the different stepper
	motor["x"] = new MicroStepper( pin_configuration["full"], pin_configuration["basic_x"], "Motor x: " );
	motor["y"] = new MicroStepper( pin_configuration["full"], pin_configuration["basic_y"], "Motor y: " );
	motor["z"] = new MicroStepper( pin_configuration["full"], pin_configuration["basic_z"], "Motor z: " );
}

void MotorCollection::reset() {

	setup();
}

std::map < MotorCollection::name_type, MicroStepper* >::iterator MotorCollection::find( MotorCollection::name_type key ){

	std::map < MotorCollection::name_type, MicroStepper* >::iterator it;

	for (it = motor.begin(); it != motor.end(); ++it) {
		
		if ( strcmp(it->first,key) == 0)
			break;
	}

	return it;
}

void MotorCollection::set_forward( MotorCollection::name_type key ) {
	
	const_motor_it = find(key);

	if ( const_motor_it != motor.end() ) 
		const_motor_it->second->set_forward_direction();
	
}

void MotorCollection::set_backward( MotorCollection::name_type key ) {

	const_motor_it = find(key);

	if ( const_motor_it != motor.end() )
		const_motor_it->second->set_backward_direction();
}

void MotorCollection::do_step( MotorCollection::name_type key ) {
	const_motor_it = find(key);

	if ( const_motor_it != motor.end() ) {

		display_name("MotorCollection: do_step");
		const_motor_it->second->do_step();
	}
}

void MotorCollection::set_pin_configuration( name_type key_motor, name_type key_config ) {

	const_motor_it = find(key_motor);
	config_it = pin_configuration.find(key_config);

	if ( const_motor_it != motor.end() && config_it != pin_configuration.end())
		const_motor_it->second->set_micro_pins( config_it->second );
}

void MotorCollection::set_pin_configuration_all( name_type key_config ) {

	
	config_it = pin_configuration.find(key_config);

	for (const_motor_it = motor.begin(); const_motor_it != motor.end(); ++const_motor_it)

		if ( config_it != pin_configuration.end())
			const_motor_it->second->set_micro_pins( config_it->second );
}

void MotorCollection::sleep( MotorCollection::name_type key ) {

	const_motor_it = find(key);

	if ( const_motor_it != motor.end() )
		const_motor_it->second->sleep();
}

void MotorCollection::unsleep( MotorCollection::name_type key ) {

	const_motor_it = find(key);

	if ( const_motor_it != motor.end() )
		const_motor_it->second->unsleep();
}

void MotorCollection::lock( MotorCollection::name_type key ) {

	const_motor_it = find(key);

	if ( const_motor_it != motor.end() )
		const_motor_it->second->lock();
}

void MotorCollection::unlock( MotorCollection::name_type key ) {

	const_motor_it = find(key);

	if ( const_motor_it != motor.end() )
		const_motor_it->second->unlock();
}

void MotorCollection::lock_all() {

	for ( const_motor_it = motor.begin(); const_motor_it != motor.end(); ++const_motor_it)
		const_motor_it->second->lock();

}

void MotorCollection::unlock_all() {

	for ( const_motor_it = motor.begin(); const_motor_it != motor.end(); ++const_motor_it)
		const_motor_it->second->unlock();
}

void MotorCollection::display_name(MotorCollection::name_type s) const {

	Serial.println(s);
}