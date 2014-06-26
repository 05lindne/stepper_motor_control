
#ifndef PIN_CONFIGURATION_H
#define PIN_CONFIGURATION_H

#include <Arduino.h>
#undef abs	//neutralizes an error with <StandardCPlusplus> caused by a #define abs in <Arduino.h>
			//error looks like: expected ")" before long in cstdlib

#include <map>

#include "Pin.h"



class PinConfiguration {
	
	public:

		typedef Pin::value_type value_type;
		typedef Pin::id_type id_type;
		typedef Pin::name_type name_type;
		typedef Pin pin_type;
	
	private:
		
		std::map < name_type, pin_type* > pins;
		std::map < name_type, pin_type* >::const_iterator const_it;
		std::map < name_type, pin_type* >::iterator it;

	public:

		~PinConfiguration();

		void add_pin( name_type key, pin_type* const pin);
		void remove_pin( name_type key);
		
		value_type get_pin_state( name_type key);
		void set_pin_state( name_type key, value_type value);
		void set_pin_state( name_type key);
		void set_pin_high( name_type key );
		void set_pin_low( name_type key );
		void flip_pin_state( name_type key );
		bool is_good_pin( name_type key );
		bool is_high( name_type key );
		bool is_low( name_type key );
		void update_pins();
		std::map< name_type, pin_type*>::iterator find( name_type key);

		id_type get_pin_id( name_type key );
		void set_pin_id( name_type key, id_type new_id);
};

#endif