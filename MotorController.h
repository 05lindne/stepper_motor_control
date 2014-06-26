#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "MotorCollection.h"

class MotorController {

	protected:

		MotorCollection motor;

	public:

		typedef char signal_type;

		virtual void read_signal(signal_type signal) = 0;


};


#endif