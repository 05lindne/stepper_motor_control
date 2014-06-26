
#include "Pin.h"
#include <Arduino.h>

#undef abs	//neutralizes an error with <StandardCPlusplus> caused by a #define abs in <Arduino.h>
			//error looks like: expected ")" before long in cstdlib

Pin::Pin(Pin::id_type new_id, const Pin::name_type s, Pin::value_type new_state, const Pin::value_type initial_high, const Pin::value_type initial_low, const Pin::value_type initial_bad, const Pin::value_type initial_IO ) : 
id(new_id), name(s), state(new_state), high(initial_high), low(initial_low), bad(initial_bad) {

	pinMode(id, initial_IO);

}

Pin::~Pin(){

	// std::cout << "abstract " << name << " pin destroyed\n";
}

void Pin::set_state(Pin::value_type new_state) {

	if (new_state == low || new_state == high) {
		state = new_state;
		set_state();
	}	else
		state = bad;
}

void Pin::set_state() {

	// here is where the actual interaction with arduino should come into play
	// something like this:

	// digital_something_something(id,state);
	digitalWrite(id,state);

	Serial.print("setting pin: ");
	Serial.println(state);

	// if (is_good())
		// std::cout << name << " set to " << state << std::endl;
	// else
		// std::cout << name << ": bad internal state! motor pin cannot be set to " << state << std::endl;
}

void Pin::set_id(Pin::id_type new_id) {

	id = new_id;
}

void Pin::set_high() {
    
	set_state(high);
}

void Pin::set_low() {

	set_state(low);
}

Pin::value_type Pin::get_state() const {

	return state;
}

Pin::id_type Pin::get_id() const {

	return id;
}

void Pin::flip_state(){

	if (is_good())
		if (is_high())
			set_state(low);
		else if (is_low())
			set_state(high);
		else {}
	// std::cout << name <<" flipped to " << state << "\n";
}

bool Pin::is_good(){

	if (is_high() || is_low())
		return true;
	else 
		return false;
}

Pin::name_type Pin::get_name() const {

	return name;
}

bool Pin::is_high() const {

	if (state == high)
		return true;
	else 
		return false;
}

bool Pin::is_low() const {

	return !is_high();
}