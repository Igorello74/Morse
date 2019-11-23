/*
In this example we will play a morse sequence written as a String, it's more convenient than using the array method.
*/

#include <Morse.h>

String seq = "***---***"; // create a sequence to play

Morse morser(12, 50); 
// create an instance of the Morse class, 12 is the pin to which executing device is connected, 50 is the duration of a unit (in ms)

void setup() {
  // we don't need to call pinMode, all setting are done in the constructor
  }

void loop() {
  morser.play(seq); // play the morse sequnce we saved above. We just give it a String in the special format and don't care anymore!
}
