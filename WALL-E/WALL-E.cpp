#include "WALL-E.h"

#define DefaultSpeed 255

char WALL-E::LSpeed = DefaultSpeed;
char WALL-E::RSpeed = DefaultSpeed;

//  Default Arduino Car pin define
WALL-E::WALL-E()
{
    LMotorSpeedPin = 5;             //Left Motor Speed pin (ENA)
    LMotorForward = 4;             //Motor-L forward (IN1).
    LMotorBackward = 6;            //Motor-L backward (IN2)

    RMotorSpeedPin = 3;             //Right Motor Speed pin (ENB)
    RMotorForward = 7;             //Motor-R forward (IN4)
    RMotorBackward = 2;            //Motor-R backward (IN3)

    pinMode(LMotorSpeedPin,OUTPUT);
    pinMode(LMotorForward,OUTPUT);
    pinMode(LMotorBackward,OUTPUT);

    pinMode(RMotorSpeedPin,OUTPUT);
    pinMode(RMotorForward,OUTPUT);
    pinMode(RMotorBackward,OUTPUT);

}

//WALL-E::WALL-E(int LSpeedPin = 5,int L1 = A0,int L2 = A1 ,int RSpeedPin = 6,int R1 = A3,int R2 = A2)
WALL-E::WALL-E(int LSpeedPin,int L1,int L2,int RSpeedPin,int R1,int R2)
{
    this->LMotorSpeedPin = LSpeedPin;
    this->LMotorForward = L1;
    this->LMotorBackward = L2;

    this->RMotorSpeedPin = RSpeedPin;
    this->RMotorForward = R1;
    this->RMotorBackward = R2;

    pinMode(LMotorSpeedPin,OUTPUT);
    pinMode(LMotorForward,OUTPUT);
    pinMode(LMotorBackward,OUTPUT);

    pinMode(RMotorSpeedPin,OUTPUT);
    pinMode(RMotorForward,OUTPUT);
    pinMode(RMotorBackward,OUTPUT);
}


//drive the left motor run forward
void WALL-E::LeftMotorForward(char inLSpeed = LSpeed)
{
    analogWrite(LMotorSpeedPin,inLSpeed);
    digitalWrite(LMotorForward,HIGH);
    digitalWrite(LMotorBackward,LOW);
}

//drive the left motor run backward
void WALL-E::LeftMotorBackward(char inLSpeed = LSpeed)
{
    analogWrite(LMotorSpeedPin,inLSpeed);
    digitalWrite(LMotorForward,LOW);
    digitalWrite(LMotorBackward,HIGH);
}

//drive the left motor stop
void WALL-E::LeftMotorStop()
{
    digitalWrite(LMotorSpeedPin,LOW);
}

//drive the right motor run forward
void WALL-E::RightMotorForward(char inRSpeed = RSpeed)
{
    analogWrite(RMotorSpeedPin,inRSpeed);
    digitalWrite(RMotorForward,HIGH);
    digitalWrite(RMotorBackward,LOW);
}

//drive the right motor run backward
void WALL-E::RightMotorBackward(char inRSpeed = RSpeed)
{
    analogWrite(RMotorSpeedPin,inRSpeed);
    digitalWrite(RMotorForward,LOW);
    digitalWrite(RMotorBackward,HIGH);
}

bool WALL-E::MotorRun(int LS,int RS)
{
    if(LS >= 0 && LS <= 255)
    {
        LeftMotorForward(LS);
    }
    if(LS < 0 && LS >= -255)
    {
        LeftMotorBackward(abs(LS));
    }

    if(RS >= 0 && RS <= 255)
    {
        RightMotorForward(RS);
    }
    if(RS < 0 && RS >= -255)
    {
        RightMotorBackward(abs(RS));
    }
    if (RS > 255 || RS < -255 || LS > 255 || LS < -255)
    {
        return false;
    }

    return true;
}

//drive the right motor stop
void WALL-E::RightMotorStop()
{
    digitalWrite(RMotorSpeedPin,LOW);
}

//drive the car run forward
void WALL-E::Forward()
{
    LeftMotorForward();
    RightMotorForward();
}

//drive the car run forward
void WALL-E::Forward(unsigned int DelayMS)
{
    Forward();
    delay(DelayMS);
    Brake();
}

//drive the car run backward
void WALL-E::Backward()
{
    LeftMotorBackward();
    RightMotorBackward();
}

void WALL-E::Backward(unsigned int DelayMS)
{
    Backward();
    delay(DelayMS);
    Brake();
}

//drive the car turn left
void WALL-E::Left()
{
    LeftMotorStop();
    RightMotorForward();
}

void WALL-E::Left(unsigned int DelayMS)
{
    Left();
    delay(DelayMS);
    Brake();
}

//drive the car turn right
void WALL-E::Right()
{
    RightMotorStop();
    LeftMotorForward();
}

void WALL-E::Right(unsigned int DelayMS)
{
    Right();
    delay(DelayMS);
    Brake();
}

//drive the car left circle
void WALL-E::LeftCircle()
{
    LeftMotorBackward();
    RightMotorForward();
}

void WALL-E::LeftCircle(unsigned int DelayMS)
{
    LeftCircle();
    delay(DelayMS);
    Brake();
}

//drive the car Right circle
void WALL-E::RightCircle()
{
    LeftMotorForward();
    RightMotorBackward();
}

void WALL-E::RightCircle(unsigned int DelayMS)
{
    RightCircle();
    delay(DelayMS);
    Brake();
}

//drive the car brake
void WALL-E::Brake()
{
    LeftMotorStop();
    RightMotorStop();
}

//reset the speed of the car
void WALL-E::SetSpeed(char LSpeed,char RSpeed)
{
    this->LSpeed = LSpeed;
    this->RSpeed = RSpeed;
    analogWrite(RMotorSpeedPin,RSpeed);
    analogWrite(LMotorSpeedPin,LSpeed);
}

//reset the speed of the car
void WALL-E::SetSpeed(char Speed)
{
    this->LSpeed = Speed;
    this->RSpeed = Speed;
    analogWrite(RMotorSpeedPin,RSpeed);
    analogWrite(LMotorSpeedPin,LSpeed);
}

void WALL-E::SetRSpeed(char Speed)
{
    this->RSpeed = Speed;
    analogWrite(RMotorSpeedPin,RSpeed);
}

void WALL-E::SetLSpeed(char Speed)
{
    this->LSpeed = Speed;
    analogWrite(LMotorSpeedPin,LSpeed);
}


