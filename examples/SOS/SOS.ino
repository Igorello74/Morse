#include <Morse.h>

MSer s[] = {DO, PS, DO, PS, DO, PS, DA, PS, DA, PS, DA, PS, DO, PS, DO, PS, DO, WS };

/*
DO	DOt 				1 unit
DA  DAsh				3 unit
PS	PartSpace		1 unit
LS	LetterSpace	3 unit
WS	WordSpace		7 unit
*/

Morse MM (12, 50 );

void setup() {
  Serial.begin(9600);
}

void loop() {
	MM.play(s, sizeof(s));
}