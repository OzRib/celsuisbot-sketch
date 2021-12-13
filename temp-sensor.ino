#define sensibility 8
int lastTemp = -32768;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned int sensorValue = analogRead(A0);
  int temp = sensorValue/sensibility - 42;
  
  int tempDiff = temp - lastTemp;
  if(tempDiff < 0)
    tempDiff = tempDiff * (-1);
  
  if(tempDiff >= 1)
    Serial.println(temp);

  lastTemp = temp;
}
