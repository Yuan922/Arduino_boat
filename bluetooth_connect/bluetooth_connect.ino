#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10,11);//RX TX

void setup() {
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT command:");
  BTSerial.begin(38400);//HC-05原始的AT指令傳輸速度
}

void loop() {
  if(BTSerial.available())
    Serial.write(BTSerial.read());

  if(Serial.available())
    BTSerial.write(Serial.read());
}
