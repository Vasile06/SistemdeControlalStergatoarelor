#pragma once
#include "States.h"
class WiperMotor {
protected:
	WiperSpeed wipspeed;
public:
	WiperMotor() {};
	WiperSpeed GetWiperSpeed() const { return wipspeed; }
	void SetWiperSpeed(const WiperSpeed speed_state) { wipspeed = speed_state; }

};