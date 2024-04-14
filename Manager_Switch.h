#pragma once
#include"WindshildWiper_switch.h"
#include"Rain_Sensor.h"
#include <tuple>
class Manager_Switch
{
	WindshildWiper_switch wswitch;
	Rain_Sensor raintype;
	public:
		float GetValues() {
			return raintype.GetValue();
		}
		void SetWSitch(const SwitchState state) {
			wswitch.SetState(state);
		}
		void Setsensor() 
		{
			raintype.SetValue();
		}
		std::tuple<WiperSpeed, RainState>CalculateRainState() {
			auto rainState = std::make_tuple(WiperSpeed::None, RainState::Norain);
			switch (wswitch.GetState())
			{
			case SwitchState::LowWip:
			{
				rainState = std::make_tuple(WiperSpeed::LowSpeed, RainState::LowRain);
				break;
			}
			case SwitchState::HighWip:
			{
				rainState = std::make_tuple(WiperSpeed::HighSpeed, RainState::HighRain);
				break;
			}
			case SwitchState::Automatic:
			{
				if (raintype.GetValue() > NoRAIN_l && raintype.GetValue() < NoRAIN_H) {
					rainState = std::make_tuple(WiperSpeed::None, RainState::Norain);
				}
				else if (raintype.GetValue() > LOWRAIN_l && raintype.GetValue() < LOWRAIN_h) {
					rainState = std::make_tuple(WiperSpeed::LowSpeed, RainState::LowRain);
				}
				else if (raintype.GetValue() > HIGHRAIN_l && raintype.GetValue() < HIGHRAIN_h) {
					rainState = std::make_tuple(WiperSpeed::HighSpeed, RainState::HighRain);
				}
				else { break; }
				break;
			}
			case SwitchState::Off:
			default:
			{
				rainState = std::make_tuple(WiperSpeed::None, RainState::Norain);
				break;
			}
			}
			return rainState;
		}
};