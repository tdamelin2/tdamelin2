#include <Servo.h>

#include <SoftwareSerial.h>
int rxPin = 7;
int txPin = 8;
int in1 = 5;
int in2 = 3;
int in3 = 10; 
int in4 = 11; 
int survo = 2;
Servo servo;
 //Transmit data to HM-10  (RXD)
SoftwareSerial bluetooth(txPin,rxPin);    //Create an instance of a serial port called bluetooth

char inputChar;             //Control characters from remote device

void setup()
{ 
  Serial.begin(9600);         //Local serial monitor initialization
  bluetooth.begin(9600);
  servo.attach(2);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);//Bluetooth serial communication initialization
  servo.write(0);
}

void Control(){
   if (inputChar == 'f'){
           analogWrite(in1, 255);
          digitalWrite(in2, LOW);   
          analogWrite(in3, 255);
          digitalWrite(in4, LOW);   
          delay(100);
        }
     else if(inputChar == 'b'){
           digitalWrite(in1, LOW);
           analogWrite(in2, 255);
           digitalWrite(in3, LOW);
           analogWrite(in4, 255);
            delay(100);
      }
      else if(inputChar == 'l'){
        analogWrite(in1, 150);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        analogWrite(in4, 150);
        delay(100);         
        }
       else if(inputChar == 'r'){
         analogWrite(in3, 150);
          digitalWrite(in4, LOW); 
          digitalWrite(in1, LOW);
           analogWrite(in2, 150);
          delay(100);  
        }
        
    else if(inputChar == 's'){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      }
      
  }

void loop()
{
    if(bluetooth.available())   //Check for input from remote
    {
      servo.write(180);
      inputChar = bluetooth.read(); //If character has been sent store it
      Serial.print(inputChar);      //Print character to serial monitor
       }
        
       Control();
   
}
