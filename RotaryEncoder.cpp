#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t SW_PIN, bool ACTIVE)
{
	_SW_PIN = SW_PIN;
	_ACTIVE = ACTIVE;
	pinMode(SW_PIN, INPUT);
}
RotaryEncoder::RotaryEncoder(uint8_t CLK_PIN, uint8_t DT_PIN)
{
	_CLK_PIN = CLK_PIN;
	_DT_PIN = DT_PIN;
	pinMode(CLK_PIN, INPUT);
	pinMode(DT_PIN, INPUT);
	
	_alastTime = 0;
}
RotaryEncoder::RotaryEncoder(uint8_t CLK_PIN, uint8_t DT_PIN, uint8_t SW_PIN, bool ACTIVE)
{
	_CLK_PIN = CLK_PIN;
	_DT_PIN = DT_PIN;
	_SW_PIN = SW_PIN;
	_ACTIVE = ACTIVE;
	pinMode(CLK_PIN, INPUT);
	pinMode(DT_PIN, INPUT);
	pinMode(SW_PIN, INPUT);
	
	_alastTime = 0;
}
		
bool RotaryEncoder::isButtonPressed()
{
	if(digitalRead(_SW_PIN) == _ACTIVE)
	{
		delay(10);
		if(digitalRead(_SW_PIN) == _ACTIVE)
			return true;
	}
	return false;
}
void RotaryEncoder::waitRotary()
{
	_acurrTime = millis();
  if (_acurrTime - _alastTime > 5)
  {
  	if (digitalRead(_DT_PIN) == LOW)
  	{
  	  rotaryData.count ++;
  	}
  	else
  	{
  		rotaryData.count --;
  	}
   rotaryData.avai = true;
  }
  _alastTime = _acurrTime;
}

void RotaryEncoder::dataGot()
{
	rotaryData.avai = false;
}

void RotaryEncoder::resetRotary(bool avai, int count)
{
	rotaryData.avai = false;
	rotaryData.count = 0;
}
