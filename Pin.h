#ifndef PIN_H
#define PIN_H

// #include <string>

class Pin {
	
	public:

		typedef short value_type;			
		typedef unsigned short id_type;
		typedef const char* name_type;

		Pin( id_type id, const name_type s, value_type initial_state, const value_type initial_high, const value_type initial_low, const value_type initial_bad, const value_type initial_IO);
		~Pin();

		value_type get_state() const;
		void set_state(value_type new_state);
		void set_state();
		void flip_state();
    	bool is_good();
    	bool is_high() const;
    	bool is_low() const;
    	void set_high();
    	void set_low();

		id_type get_id() const;
		name_type get_name() const;
		void set_id(id_type new_id);
    	
	private:

	id_type id;
	const name_type name;
	value_type state;

	const value_type high;
	const value_type low;
	const value_type bad;

};

#endif