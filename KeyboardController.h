#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include "MotorController.h"


class KeyboardMotorController : public MotorController {

	public:

		typedef MotorController::signal_type signal_type;

		void read_signal(signal_type signal);
};


#endif