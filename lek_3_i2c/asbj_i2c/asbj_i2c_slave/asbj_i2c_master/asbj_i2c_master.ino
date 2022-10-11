#include <Wire.h>

char con = 'g';
bool led = 0;
bool led_in = 0;
void setup()
{
	Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
	Wire.begin(111);
  Wire.onReceive(requestReceive);
	Wire.onRequest(requestEvent);
}

void loop()
{
  Serial.print(con);
  delay(100);
}
void requestReceive(int bits)
{
    con = Wire.read(); 
    Serial.println("hej");
}

void requestEvent(int bits)
{
  
  Serial.print(bits);
  Serial.println("   ");
  switch(con)
  {
    case 'l':
      digitalWrite(8,led);
      led = !led;
    case 'i':
      digitalWrite(LED_BUILTIN,led);
      led_in = !led_in;
    default:
      Wire.write(con);
      break;
  }
}
