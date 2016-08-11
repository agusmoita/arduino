// Emite señal IR
// UNO: pin 3
// MEGA: pin 9

#include <IRremote.h>

IRsend irsend;

void setup()
{
}

void loop() {
	irsend.sendNEC(0x20DF10EF, 32);
	delay(3000);
}