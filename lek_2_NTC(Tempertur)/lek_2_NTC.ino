void setup() {
  Serial.begin(9600);  
  pinMode(A0,INPUT); 
}

void loop() {  
 int tempReading = analogRead(A0);
    // This is OK
     double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
     tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK ); //  Temp Kelvin
     float tempC =   tempK-273.15;   // Convert Kelvin to Celcius
  Serial.print("This is kelvin: ");
  Serial.print(tempK); 
  Serial.println(); 
  Serial.print("This is celcius: "); 
  Serial.print(tempC);
  Serial.println();
}
