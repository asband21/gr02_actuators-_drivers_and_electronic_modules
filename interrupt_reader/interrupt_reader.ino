const byte interruptPin = 2;
volatile byte state = LOW;
int location = 0;
int deltatid = 0;
int gammeltid = 0;
int hastighed = 0;
int acceleration = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleEncoder, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(acceleration);
  Serial.print("  ");
  Serial.print(deltatid);
  Serial.print("  ");
  Serial.println(location);
  delay(10);
}

void handleEncoder() {
  int tid = 0;
  tid = millis();
  location++;
  deltatid = tid - gammeltid;
  acceleration = deltatid - hastighed;
  hastighed = deltatid;
  gammeltid = tid;
}
