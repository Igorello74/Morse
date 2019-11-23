/*
Morse/src/Morse.h - the header file of Morse library

v1.0
*/

#ifndef Morse_h
#define Morse_h
 
#include "Arduino.h"

enum MSymb : byte { DO = 1, DA, PS, LS, WS };
enum MDebug : byte { NONE, LED, SER, SERLED };
 
class Morse	{
  public:
    Morse(byte pin, byte unit, MDebug debug = NONE);
		void play (MSymb ser[], byte num);
		void play (String &ser);
		void setUnit (byte unit);
	private:
		void _dot();
		void _dash();
		void _pspace();
		void _lspace();
		void _wspace();
		
		byte _pin;
		byte _unit;
		
		MDebug _debug;
};
 
#endif