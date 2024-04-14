#pragma once
#include"pch.h"
class WiperTestFixture :public ::testing::Test
{
	Manager_Switch man_sw;
	std::tuple<WiperSpeed, RainState>man_sw_result {};
public:
	WiperTestFixture();
	void SetUp();
	void SetSwitchInmaanger(SwitchState sws);
	float GetRainSensor();
	std::tuple<WiperSpeed, RainState> GetmanswResult() const;
	Manager_Switch  Getmansw() const ;
	void CalculateRainState();
};