// Parpadeo del LED del pin 13

const int pinLed = 13;

void setup()
{
	pinMode(pinLed, OUTPUT);
}

void loop()
{
	digitalWrite(pinLed, HIGH);
	delay(500);
	digitalWrite(pinLed, LOW);
	delay(500);
}