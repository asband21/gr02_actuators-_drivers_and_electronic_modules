#include <Wire.h>

char con = '\0';
void setup()
{
	Serial.begin(9600);
	Wire.begin(111);
	Wire.onRequest(requestEvent);
}

void loop()
{
	Serial.println("hej");

}

void requestEvent()
{
	con = Wire.read();	
	switch(con)
	{
		case 'a':
			Serial.println("hej");
			break;
		default:
			Serial.println("ikke genkend komando");
			break;
	}
	Wire.write(0x42);
}
