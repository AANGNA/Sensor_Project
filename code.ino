float RTH = 0;
float B =3435;
float T0 = 298.15;
float Td = 0;
float Tk = 0;
float R0=10000;

void setup() {
  
  Serial.begin(9600);
}


void loop() {
  float sensorValue = analogRead(A0);
  //Serial.println(sensorValue);
  RTH=(10000*1024.0/sensorValue-(float)10000);
  Tk = 1/(log(RTH/R0)/B+1/T0);
  Td = Tk-273.15;
  Serial.println(Td);
  delay(1);        // delay in between reads for stability
}
