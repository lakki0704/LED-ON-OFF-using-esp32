#include "BluetoothSerial.h"

BluetoothSerial BT;
int received;// received value 
char Value;// ASCii char of the value received

const char ON ='x';
const char OFF ='y';
const int LEDpin = 23;

void setup() {
  Serial.begin(115200);
  BT.begin("Lakshmi Sathyan"); //Bluetooth device name
  Serial.println("Pairing with bluetooth...");
  
  pinMode(LEDpin, OUTPUT);
 
}

void loop() {
    Value =(char)BT.read();

  if (Serial.available()) {
    BT.write(Serial.read());
  
  }
  if (BT.available()) {
    
    BT.println("Received:");
    BT.println(Value);     
    Serial.println("Received:");//print on serial monitor
    Serial.println(Value);//print on serial monitor    
    
    if(Value==ON) //ON =x
    {
      BT.println("LED ON ");
     Serial.println("LED is turned ON");//write on serial monitor
     digitalWrite(LEDpin, HIGH);// turn the LED ON
       
    }
    if(Value==OFF) //OFF =y
    {
      BT.println("LED OFF");
     Serial.println("LED is turned OFF:");//write on serial monitor
      digitalWrite(LEDpin, LOW);// turn the LED off 
    }    
     
  

  }
  delay(20);
}
