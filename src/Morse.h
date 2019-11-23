/*
Morse/src/Morse.h - the header file of Morse library

v1.0
*/

#ifndef Morse_h
#define Morse_h
 
#include "Arduino.h"

enum MSymb : byte {DO = 1, DA, PS, LS, WS};
// morse characters. DO=DOt, DA=DAsh, PS=Space between Parts of one letter, LS=Letter Space, WS=Word Space

enum MDebug : byte {NONE, LED, SER, SERLED};
/* debug modes, NONE — no debug used, LED — pulls the built-in led according to the Morse code,
  SER — sends messages (DO, DA, etc.), SERLED — combines two previous modes. */

// The main (and only) class of the library
class Morse {
  public:
    Morse(byte pin, byte unit, MDebug debug = NONE); // constructor, unit is the duration of one unit (equals to a dot)
		void play (MSymb ser[], byte num); // plays an array of MSymbs (look above)
		void play (String &ser); //plays a String consisting of [*], [-], [
		void setUnit (byte unit); // changes the unit to the presented
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
