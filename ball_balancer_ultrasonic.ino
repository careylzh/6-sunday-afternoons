#include <Servo.h>  
#include <PID_v1.h>
int servoPin = 6;
Servo servo;  
int angle = 0;   // servo position in degrees 
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long t1, t2, cm1 ,cm2, speed, inches; 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(servoPin); 
  servo.write(90);        
} 

void ultrasonic(){
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  t1 = pulseIn(echoPin, HIGH);
  cm1 = (t1/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  Serial.print(cm1);
  Serial.println();
  delay(100);
}
//void loop() { 
// servo.write(85);
//    }
void loop(){ 
  servo.write(86);
//  ultrasonic(); 
//  if(cm1 > 16){
//    for (int i = 0; i < 16; i++){     
//      if(90 + 3*i <96){
//      servo.write(90+3*i);
//      Serial.print("distance in cm: ");Serial.print(cm1);
//      Serial.print(" angle:");Serial.println(90+3*i);
//      delay(100);
//      }
//    }
//  }
//  else if(cm1 < 16){
//    for (int i = 0; i < 16; i++){     
//      if (90 - 3*i <86){
//      servo.write(90-3*i); Serial.print(cm1);
//      Serial.print(" angle:");Serial.println(90-3*i);
//      delay(100);
//      }
//    }
//  }
//  else{
//    delay(100);  
//  }
}
