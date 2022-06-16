#define RightMotorReverse 3
#define RightMotorForward 5
#define LeftMotorReverse 6
#define LeftMotorForward 9
#define leftIR A0
#define rightIR A1

void setup() {
  pinMode(RightMotorReverse,OUTPUT);
  pinMode(RightMotorForward,OUTPUT);
  pinMode(LeftMotorReverse,OUTPUT);
  pinMode(LeftMotorForward,OUTPUT);
  pinMode(rightIR ,INPUT);
  pinMode(leftIR,INPUT);

  Serial.begin(9600);
}

void loop() {
  if (analogRead(rightIR) < 500 && analogRead(leftIR) >= 500 )  //RIGHT
  {
    analogWrite(LeftMotorForward, 130);
    analogWrite(RightMotorForward, LOW);
  }
  else if (analogRead(rightIR) >= 500 && analogRead(leftIR) < 500 )  //LEFT
  {
    analogWrite(LeftMotorForward, LOW);
    analogWrite(RightMotorForward,130);
  }
  else if (analogRead(rightIR) >= 500 && analogRead(leftIR) >= 500 )  //STOP
  {
    analogWrite(LeftMotorForward,LOW);
    analogWrite(RightMotorForward,LOW);
  }
  else if (analogRead(rightIR)  < 500 && analogRead(leftIR) < 500 )  //FORWARD
  {
    analogWrite(LeftMotorForward,150);
    analogWrite(RightMotorForward,150);
  }
  delay(1);

}
