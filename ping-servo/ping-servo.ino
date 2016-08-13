#include <Servo.h>

Servo servo; 
const int pinServo = 9;

const int trigPin1 = 26;
const int echoPin1 = 30;

const int trigPin2 = 38;
const int echoPin2 = 42;

int angulo = 90;

void setup()
{
	Serial.begin(9600);
	servo.attach(pinServo);
	servo.write(angulo);
}

void loop()
{
	long durationLeft, durationRight, cmLeft, cmRight;

	pinMode(trigPin1, OUTPUT);
	digitalWrite(trigPin1, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin1, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin1, LOW);
	pinMode(echoPin1, INPUT);
  	durationRight = pulseIn(echoPin1, HIGH);

	pinMode(trigPin2, OUTPUT);
	digitalWrite(trigPin2, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin2, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin2, LOW);
	pinMode(echoPin2, INPUT);
  	durationLeft = pulseIn(echoPin2, HIGH);

  	cmRight = microsecondsToCentimeters(durationRight);
  	cmLeft = microsecondsToCentimeters(durationLeft);

  	Serial.println(cmLeft);
  	Serial.println(cmRight);
  	Serial.println("");

  	if(cmRight > cmLeft){
    	servo.write(179);
  	}
  	else if(cmLeft > cmRight){
    	servo.write(1);
  	}
  	else {
  		servo.write(angulo);
  	}

  	delay(500);
}

int microsecondsToCentimeters(int microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}