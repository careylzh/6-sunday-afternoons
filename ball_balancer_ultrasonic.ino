#include <Servo.h>  
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
//  Serial.print(cm1);
//  Serial.println();
  delay(40);
}
//void loop() { 
// servo.write(79);
//    }
void loop(){ 
//  if (cm1 >= 16 && cm1 <= 17){
//    servo.write(86);
//  }
ultrasonic(); 
if(cm1 >= 37){
  cm1 = 2;
  }
//else if ((cm1-cm2) > 1 || (cm1-cm2) < -1 ){
  else if(cm1 > 19 && cm1 < 36){
    servo.write(90);
    delay(100);
    servo.write(86);  
    Serial.println("more than 16");
  }
  else if(cm1 <= 17 && cm1 >= 1){
    servo.write(64);
    delay(100);
    servo.write(86);
    Serial.println("less than 16");
  }
else{servo.write(86);}
//}
Serial.println(cm1);
cm2 = cm1;
}
