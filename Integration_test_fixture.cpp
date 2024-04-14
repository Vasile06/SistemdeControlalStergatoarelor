#include"pch.h"
WiperTestFixture::WiperTestFixture()
{
	man_sw = Manager_Switch();
}


void WiperTestFixture::SetUp()
{
	man_sw.SetWSitch(SwitchState::Automatic);
	man_sw.Setsensor();
}

void WiperTestFixture::SetSwitchInmaanger(SwitchState ss)
{
	man_sw.SetWSitch(ss);
}

float WiperTestFixture::GetRainSensor()
{
	return man_sw.GetValues();
}
std::tuple<WiperSpeed, RainState> WiperTestFixture::GetmanswResult() const
{
	return man_sw_result;
}
Manager_Switch  WiperTestFixture::Getmansw() const
{
	return man_sw;
}
void WiperTestFixture::CalculateRainState()
{
	man_sw_result = man_sw.CalculateRainState();
}