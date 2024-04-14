#pragma once
#include "States.h"
class WindshildWiper_switch {
	protected :
		SwitchState state;
	public:
		SwitchState GetState() const { return state;}
		void SetState(const SwitchState actualstate) { state = actualstate; }
			
};