// Recibe IR en pin 11 e imprime en monitor serial

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
	Serial.begin(9600);
	irrecv.enableIRIn();
}

void loop()
{
	if(irrecv.decode(&results)){
		switch (results.decode_type) {
		    case NEC:
				Serial.print("NEC: ");
		      	break;
		    case SONY:
				Serial.print("SONY: ");
		      	break;
		    case RC5:
				Serial.print("RC5: ");
		    	break;
		    case RC6:
				Serial.print("RC6: ");
		    	break;
		    default:
				Serial.print("UNKNOWN: ");
		}
		Serial.println(results.value, HEX);
		irrecv.resume();
	}
	delay(100);
}