//對應圖號E-04 & E-05

const int motorIn1 = 5;
const int motorIn2 = 6;

/*
int sensorPin = A0;
int sensorValue = 0;
*/

void setup()
{
  Serial.begin(9600);

  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);

}

void loop() {

  analogWrite(motorIn1,150);//正轉 
  analogWrite(motorIn2,0);//正轉 
  delay(3000);
  analogWrite(motorIn1,0);//正轉 
  analogWrite(motorIn2,0);//正轉 
  delay(500);
  analogWrite(motorIn1,0);//正轉 
  analogWrite(motorIn2,150);//正轉 
  delay(3000);

/*
  sensorValue = analogRead(sensorPin);   //讀取類比輸入的值會得到0~1023
  sensorValue = map(sensorValue,0,1023,0,255);
  analogWrite(motorIn1,sensorValue);//正轉 
  Serial.println(sensorValue); 
*/  
}
