#include <Servo.h>
int IN1 = 13;
int IN2 = 12;
int IN3 = 11;
int IN4 = 10;
Servo chakra;
char val;
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  chakra.attach(9);
  chakra.writeMicroseconds(1500); 
  Serial.begin(9600);
}
void loop()
{
  while (Serial.available() > 0)
  {
    val = Serial.read();
    Serial.println(val);
  }

  // BLDC motor control
  if (val == 'W') {
    chakra.writeMicroseconds(2000); // Set maximum throttle
  } else if (val == 'w') {
    chakra.writeMicroseconds(1000); // Set minimum throttle or stop
  }
  

  if ( val == 'F') // Forward
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else if (val == 'B') // Backward
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digit alWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  else if (val == 'L') //Left
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  else if (val == 'R') //Right
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  else if (val == 'S') //Stop
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else if (val == 'I') //Forward Right
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else if (val == 'J') //Backward Right
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else if (val == 'G') //Forward Left
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else if (val == 'H') //Backward Left
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}

//Nuwan Tech Bro Official 