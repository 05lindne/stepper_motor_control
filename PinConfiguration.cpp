
#include "PinConfiguration.h"

// #include <iostream>

PinConfiguration::~PinConfiguration(){

	for(it = pins.begin(); it != pins.end(); ++it)
		delete it->second;
}

std::map< PinConfiguration::name_type, PinConfiguration::pin_type*>::iterator PinConfiguration::find( Pin::name_type key){

	std::map < PinConfiguration::name_type, PinConfiguration::pin_type* >::iterator it;

	for (it = pins.begin(); it != pins.end(); ++it) {
		
		if ( strcmp(it->first,key) == 0)
			break;
	}

	return it;
}

void PinConfiguration::add_pin( Pin::name_type key, Pin* const pin) {

	pins[key] = pin;
}

void PinConfiguration::remove_pin( Pin::name_type key) {

	pins.erase(key);
}

Pin::value_type PinConfiguration::get_pin_state( Pin::name_type key){

	const_it = find(key);

	if ( const_it != pins.end() )
		return const_it->second->get_state();
	else 
		return -1;
}

void PinConfiguration::set_pin_state( Pin::name_type key, Pin::value_type value){

	it = find(key);

	if ( it != pins.end() )
		it->second->set_state(value);
}

void PinConfiguration::set_pin_state( Pin::name_type key){

	it = find(key);

	if ( it != pins.end() )
		it->second->set_state();
}

void PinConfiguration::set_pin_high( Pin::name_type key ) {

	it = find(key);

	if ( it != pins.end() ) 
		it->second->set_high();
}

void PinConfiguration::set_pin_low( Pin::name_type key ) {

	it = find(key);

	if ( it != pins.end() )
		it->second->set_low();
}

void PinConfiguration::flip_pin_state( Pin::name_type key) {

	it = find(key);

	if ( it != pins.end() ) 
		it->second->flip_state();
	
}

bool PinConfiguration::is_good_pin( Pin::name_type key) {

	it = find(key);

	if ( it != pins.end() )
		return it->second->is_good();
	else
		return false;
}

Pin::id_type PinConfiguration::get_pin_id( Pin::name_type key ){

	const_it = find(key);

	if ( const_it != pins.end() )
		return const_it->second->get_id();	
}

void PinConfiguration::set_pin_id( Pin::name_type key, Pin::id_type new_id) {

	it = find(key);

	if ( it != pins.end() )
		it->second->set_id(new_id);	
}

void PinConfiguration::update_pins(){

	for(it = pins.begin(); it != pins.end(); ++it)	{

		it->second->set_state();
	}
}

bool PinConfiguration::is_high( Pin::name_type key) {

	const_it = find(key);

	if ( const_it != pins.end() )
		return const_it->second->is_high();
	else
		return false;
}

bool PinConfiguration::is_low( Pin::name_type key) {

	const_it = find(key);

	if ( const_it != pins.end() )
		return const_it->second->is_low();
	else
		return false;
}






