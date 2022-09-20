uint8_t tringer_pin = 9;
uint8_t deit_pin = 8;
void triget(uint8_t pin)
{
	digitalWrite(pin,HIGH);
	delay(10);
	digitalWrite(pin,LOW);  
}

void setup()
{
	Serial.begin(9600);
	pinMode(deit_pin, INPUT);
	pinMode(tringer_pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{
	triget(tringer_pin);
	int distens = pulseIn(deit_pin, HIGH);
	double dis = distens;
	dis = ( (dis/20000)*340);
	Serial.println(dis);
}
