#pragma once
#include <random>
#include "States.h"
class RainSt{
protected:
	RainState rain;
public :
	RainState GetRain() const { return rain; }
	RainSt() {};
	void SetRainLevel(const RainState rain_st) { rain = rain_st; }
};
