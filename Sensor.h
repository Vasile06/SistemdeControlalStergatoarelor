#pragma once
class Sensor {
protected:
		bool enabled{true};
		float value{ 0.0 };
		virtual void Enable(const bool enable) = 0 ;
		virtual float GetValue() const = 0;
		virtual void SetValue( ) = 0;
		virtual bool IsEnable() const = 0;
		
};