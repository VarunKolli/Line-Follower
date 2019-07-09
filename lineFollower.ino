
/* 

The motor controller is connected to Pins 6 to 9
pin 6 and 7 for Motor A
pin 8 and 9 for Motor B

*/ 

 
 /*Initialize variables*/

// PWM pins. DO NOT TOUCH
 #define enA 10
 #define enB 11

 const int turn_delay = 100;
 
 int speedSet = 150; // primary speed control variable. Range: 100 to 255.

const int right_sensor_pin =13;
const int left_sensor_pin = 12;

int left_sensor_state;
int right_sensor_state;

int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;

 
 /*Define functions for motor movement*/
void _mBackward()
  {
     digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
     digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW);
     Serial.println("go back!");
  }

void _mForward()
  {
     digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
     digitalWrite(in3,LOW );
     digitalWrite(in4,HIGH);
     Serial.println("go Forward!");   
  }

void _mLeft()
  {
     digitalWrite(in1,LOW);
     digitalWrite(in2,HIGH);
     digitalWrite(in3,HIGH);
     digitalWrite(in4,LOW); 
     Serial.println("go left!");
  }

void _mRight()
  {
     digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
     digitalWrite(in3,LOW);
     digitalWrite(in4,HIGH);
     Serial.println("go right!");
  } 
void _mStop()
  {
     digitalWrite(in1,LOW);
     digitalWrite(in2,LOW);
     digitalWrite(in3,LOW);
     digitalWrite(in4,LOW);
     Serial.println("Stop!");
  } 
 

void setup() 
{ 
  Serial.begin(9600);     
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(right_sensor_state, INPUT);
 // dont really frickin need this piece: pinMode(LED,OUTPUT);
 
  _mStop();
} 

void loop() //main commands to move motor or show brake light
{  

    analogWrite(enA, speedSet);
    analogWrite(enB, speedSet);      
     
   left_sensor_state = digitalRead(left_sensor_pin);
    right_sensor_state = digitalRead(right_sensor_pin);

    

    if(right_sensor_state == LOW && left_sensor_state == HIGH)
    {
      Serial.println("turning left");
     
     _mRight();
      delay(turn_delay);
      
     }
    if(right_sensor_state ==HIGH && left_sensor_state == LOW)
    {
      speedSet = 500;
      _mStop();
      _mLeft();
      delay(1500);
      _mStop();      
    }

    if(right_sensor_state == LOW && left_sensor_state == LOW)
      {
        Serial.println("going forward");
        _mForward();
       delay(turn_delay);      
      }

    if(right_sensor_state == HIGH && left_sensor_state == HIGH)
    { 
      _mStop();           
    }
    else
    {
      _mStop();
    }
                          
}
