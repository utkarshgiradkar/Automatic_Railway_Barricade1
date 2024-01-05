#include <Servo.h>

Servo myservo;  
int pos = 0; 
#define trigPin 2
#define echoPin 3
#define led 4
#define led2 5
int IRpin = 7;
int a=0;

#define buzzer 6



void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(buzzer, OUTPUT);

    myservo.attach(9);  
    myservo.write(0);  
}

void loop() {

  a= digitalRead(IRpin);

  long duration, distance;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.017);

  Serial.println(distance);

  if (distance <= 10 && distance > 0 ) {
    digitalWrite(led2, HIGH);
     digitalWrite(led, LOW);
    myservo.write(90); 
    delay(10);            

    digitalWrite(buzzer, HIGH);
    delay(10);
     digitalWrite(buzzer, LOW);
  
}
  if (distance > 10  ){
        digitalWrite(led, HIGH);
        digitalWrite(led2, LOW);
  

  }

   if (a==1){                   
  digitalWrite(led, HIGH);
  } 
  if (a==0){
    delay(100);
    myservo.write(0);              
                 
  }
  
}