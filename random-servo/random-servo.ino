// Movimientos aleatorios de un servo en pin 9

#include <Servo.h>

Servo servo;
const int pinServo = 9;
int angulo = 0;

void setup()
{
	Serial.begin(9600);
	servo.attach(pinServo);
}

void loop()
{
	Serial.println(angulo);
	servo.write(angulo);
	angulo = random(0, 180);
	delay(500);
}