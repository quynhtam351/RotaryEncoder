#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>

class RotaryEncoder
{
	private:
		uint8_t _CLK_PIN;
		uint8_t _DT_PIN;
		uint8_t _SW_PIN;
		
		unsigned long _alastTime;
		unsigned long _acurrTime;
		
		bool _ACTIVE;
		
		struct RoData
		{
			int count = 0;
			bool avai = false;
		};
		
	public:
		RotaryEncoder::RoData rotaryData;
		RotaryEncoder(uint8_t SW_PIN, bool ACTIVE = LOW);
		RotaryEncoder(uint8_t CLK_PIN, uint8_t DT_PIN);
		RotaryEncoder(uint8_t CLK_PIN, uint8_t DT_PIN, uint8_t SW_PIN, bool ACTIVE = LOW);
		
		bool isButtonPressed();
		void waitRotary();
		
		void dataGot();
		void resetRotary(bool avai = false, int count = 0);
};
#endif
