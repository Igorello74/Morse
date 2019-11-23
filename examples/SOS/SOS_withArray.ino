/*
In this example we will play a morse sequence written as an array of MSers, it's not as convenient as the String method, it's legacy.
*/

#include <Morse.h>

MSer seq[] = {DO, PS, DO, PS, DO, PS, DA, PS, DA, PS, DA, PS, DO, PS, DO, PS, DO, WS}; // create a sequence to play

Morse morser(12, 50); 
// create an instance of the Morse class, 12 is the pin to which executing device is connected, 50 is the duration of a unit (in ms)

void setup() {
  // we don't need to call pinMode, all setting are done in the constructor
  }

void loop() {
  morser.play(seq, sizeof(seq)); // play the morse sequnce we saved above. The second argument is the number of members in the array
}
