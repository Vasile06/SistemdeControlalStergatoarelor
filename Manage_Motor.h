#pragma once
#include"rainst.h"
#include"WiperMotor.h"
#include "Manager_Switch.h"
class Manager_Motor {
private:
	WiperMotor wipst;
	RainSt rain;
	Manager_Switch sensor_results;   
public:
	
	Manager_Motor(const Manager_Switch& sensorResults) :  sensor_results(sensorResults) {}

	
	void ReadManagerSwitch(const Manager_Switch& sensorResult)
	{
		sensor_results = sensorResult;
	}
	void SetWiperMotor() {
		wipst.SetWiperSpeed(std::get<0>(sensor_results.CalculateRainState()));
	}
	void SetRain() {
		rain.SetRainLevel(std::get<1>(sensor_results.CalculateRainState()));
	}
	WiperMotor GetWipst() const {
		return wipst;
	}
	RainSt GetRain() const {
		return rain;
	}
};

