#pragma once
typedef enum SwitchState
{
	Off = 0,
	LowWip,
	HighWip,
	Automatic
};

typedef enum WiperSpeed
{
	None = 0,
	LowSpeed,
	HighSpeed
};

typedef enum RainState
{
	Norain = 0,
	LowRain,
	HighRain
};

constexpr float NoRAIN_l{ 0.0};
constexpr float NoRAIN_H{ 1.99 };
constexpr float LOWRAIN_l{ 2.0 };
constexpr float  LOWRAIN_h{ 4.99 };
constexpr float HIGHRAIN_l{ 5.0 };
constexpr float HIGHRAIN_h{ 12.0 };