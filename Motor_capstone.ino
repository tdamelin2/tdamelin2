#include <Stepper.h>
int button = 2; 
int laser = 12;
int flag = 0;
int STEPS = 200;
Stepper stepper(STEPS, 8, 9, 10, 11);
Stepper stepper1(STEPS, 4, 5, 6, 7);

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(laser, OUTPUT);
  Serial.begin(9600);
  stepper.setSpeed(60);
  stepper1.setSpeed(60);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(laser, HIGH);
 int reading = digitalRead(button);
  
  Serial.print(reading);
  if (reading == HIGH){
    if (flag == 0){
      flag = 1;
      stepper.setSpeed(150);
      stepper1.setSpeed(150);
  
      for(int s=0; s<STEPS; s++){
        stepper.step(1);
        stepper1.step(-1);
      }
    }
    
    else{
        flag = 0;
        Serial.print(reading);
  }
  }
}

  
         
