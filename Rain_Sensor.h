#pragma once
#include "Sensor.h"
#include <random>
#include"iostream"
class Rain_Sensor :public Sensor
{
public:
	void Enable(bool enable) override {}
	float GetValue() const override { return value; }
	void SetValue()  override { 
		std::random_device rand;
		std::mt19937 gen(rand());
		float low = -2;
		float max = 14;
		std::uniform_real_distribution<float>rainintensity(low, max);
		value = rainintensity(gen);
		std::cout << "valoarea atribuita aleatoriu: " << value << std::endl;
	//	value = 8;
	}
	//bool IsEnable() const override { return true; }
};