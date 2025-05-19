//對應圖號E-07

#include <IRremote.h>

int RECV_PIN = 11;
const int motorIn1 = 6;
const int motorIn2 = 5;
int sensorPin = A0;
int sensorValue = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);

  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");

  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
  if(results.value == 0xFFA25D){
  analogWrite(motorIn1,170);//反轉
  analogWrite(motorIn2,0);//正轉    
  }
  if(results.value == 0xFFE21D){
  analogWrite(motorIn1,0);//反轉
  analogWrite(motorIn2,170);//正轉    
  }
  if(results.value == 0xFF6897){
  analogWrite(motorIn1,0);//反轉
  analogWrite(motorIn2,0);//正轉    
  }
  if(results.value == 0xFF906F){
  sensorValue = analogRead(sensorPin);   //讀取類比輸入的值會得到0~1023
  sensorValue = map(sensorValue,0,1023,0,255);
  analogWrite(motorIn1,0);//反轉
  analogWrite(motorIn2,sensorValue);//正轉 
  Serial.println(sensorValue); 
  }
}
