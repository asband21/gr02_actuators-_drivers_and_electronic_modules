void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

void loop() {
int tid = millis();
float a=sin((float)tid/100);
  if(a>0){
    digitalWrite(2,HIGH);
    Serial.println(1);
  }
  else{
    digitalWrite(2,LOW);
    Serial.println(0);
  }
}
