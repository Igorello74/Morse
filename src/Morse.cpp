/*
Morse/src/Morse.cpp - the main file of Morse library

v1.0
*/

#include "Morse.h"

Morse::Morse(byte pin, byte unit, MDebug debug = NONE) {
  _pin = pin;
  _unit = unit;
  _debug = debug;
  if (_debug > LED) Serial.begin(9600);
  if (_debug == LED or _debug == SERLED) pinMode(13, OUTPUT);
  pinMode(_pin, OUTPUT);
}

void Morse::play (MSymb ser[], byte num) {
	for (byte i = 0; i < num; i++) {
		switch (ser[i]) {
			case DO:
				_dot();
				break;
			case DA:
				_dash();
				break;
			case PS:
				_pspace();
				break;
			case LS:
				_lspace();
				break;
			case WS:
				_wspace();
				break;
		}
	}
}

void Morse::play (String &ser) {
	for(byte i = 0; i < ser.length(); i++) {
		if (ser[i] == '.' or ser[i] == '*') _dot();
		else if (ser[i] == '-')	_dash();
		else if (ser[i] == ' ')	_lspace();
		else if (ser[i] == '/')	_wspace();

		if ((i != ser.length()-1) and (ser[i+1] != '/') and (ser[i+1] != ' ')
		and (ser[i] != '/') and (ser[i] != ' '))	_pspace();
	}
	
}

void Morse::setUnit (byte unit) {
	if (_debug > LED) Serial.println("Set unit: " + String(_unit) + "-->" \
	+ String(unit));
	_unit=unit;
}

void Morse::_dot() {
	if (_debug > LED) Serial.println("DO");
	if (_debug == LED or _debug == SERLED) digitalWrite(13, HIGH);
	digitalWrite(_pin, HIGH);
	delay(_unit);
	if (_debug == LED or _debug == SERLED) digitalWrite(13, LOW);
	digitalWrite(_pin, LOW);
}

void Morse::_dash() {
	if (_debug > LED) Serial.println("DA");
	if (_debug == LED or _debug == SERLED) digitalWrite(13, HIGH);
	digitalWrite(_pin, HIGH);
	delay(_unit*3);
	if (_debug == LED or _debug == SERLED) digitalWrite(13, LOW);
	digitalWrite(_pin, LOW);
}

void Morse::_pspace() {
	if (_debug > LED) Serial.println("PS");
	if (_debug == LED or _debug == SERLED) digitalWrite(13, LOW);
	digitalWrite(_pin, LOW);
	delay(_unit);
}

void Morse::_lspace() {
	if (_debug > LED) Serial.println("LS");
	if (_debug == LED or _debug == SERLED) digitalWrite(13, LOW);
	digitalWrite(_pin, LOW);
	delay(_unit*3);
}

void Morse::_wspace() {
	if (_debug > LED) Serial.println("WS");
	if (_debug == LED or _debug == SERLED) digitalWrite(13, LOW);
	digitalWrite(_pin, LOW);
	delay(_unit*7);
}
