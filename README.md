# Morse
> Arduino library for convinient Morse-code playing

## Goals
The library is intended to easily play Morse code at a pin of Arduino. You can just type needed sentence (using dots and dashes) and it will be played with required speed. Also, the library allows debugging.

# Methods
## Constructor
```cpp
Morse(byte pin, byte unit, MDebug debug = NONE);
```
- byte **pin** — the pin to which the executing device is connected
- byte **unit** — duration of one unit (*see below*) in *ms* (milliseconds)
- MDebug **debug** — see below ([Debugging](#debugging))

## Playing
There are two ways to set a morse sequence — with an array of `MSymb` or with a `String`.

|Morse char                       |Array notation|String notation       |Duration in *units*|
|:--------------------------------|:------------:|:--------------------:|------------------:|
|dot                              |`DO`          |`.` or `*`            |1                  |
|dash                             |`DA`          |`-`                   |3                  |
|space between parts of one letter|`PS`          |*played automatically*|1                  |
|space between letters            |`LS`          |*space*               |3                  |
|space between words              |`WS`          |`/`                   |7                  |

Whatever way you choose, you need to use the `play` function:
- `void play (MSymb ser[], byte num)`
  - **Comment:** *num* is the number of characters presented (lenght of the array).
  - **Possible sequence:** `MSymb sos[] = {DO, LS, DO, LS, DO, LS, DA, LS, DA, LS, DA, LS, DO, LS, DO, LS, DO};`
- `void play (String &ser)`
  - **Possible sequence:** `String sos = "***---***";`

## setUnit
```cpp
void setUnit(byte unit);
```
If you suddenly want to alter the unit duration after creating an instance, you can use the `setUnit` function, the unit of the unit (pardon for tautology) is milliseconds, as well.


# <a name="debugging"/> Debugging
As you have already seen, there is the *debug* variable in the constructor. It can take the following values:

|Debug value|Description
|:---------:|----------------------------------------------------------------
|`NONE`     |no debugging used
|`LED`      |pulses the built-in led according to the morse signal
|`SER`      |sends messages into Serial in the Array notation (*see above*)
|`SERLED`   |combines two previous modes

# License
The library is published under the ***MIT License***, for more details, see [LICENSE](LICENSE).

# Contact
Pull-requests and other contributing are welcome!
