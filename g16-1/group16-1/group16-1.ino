int motorPin1 = 8;
int motorPin2 = 7;
int inputPin = A1;

int zero = 0;

int sensorValue = 0;
int outputValue = 0;
int targetValue;
int prev = 0;
int diff = 0; int acc = 0;

// PID constants
float kp = 15, kd = 10, ki = 0.01;
int calib = 550;

void setup() 
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  sensorValue = analogRead(inputPin);
  if(sensorValue > calib)
  {
    targetValue = sensorValue - calib;
  }
  else
  {
    targetValue = sensorValue + calib;
  }
    
  prev = targetValue - sensorValue;
  acc = prev;
}

void loop() 
{
  sensorValue = analogRead(inputPin);

 
  int err = targetValue - sensorValue;
  
  acc = acc + err;
  diff = err - prev;
  
  
 outputValue = (int)abs(kp*err + kd*diff + ki*acc); 
 Serial.println(sensorValue);
 if(outputValue<2){
  while(true){
    analogWrite(motorPin1,zero);
    analogWrite(motorPin2, zero);
  }
 }
 if(outputValue > 255)
 {
  outputValue = 255;
 }
 
  if (err<0)
  {
    analogWrite(motorPin1, outputValue);
    analogWrite(motorPin2, zero);

  }
  else
  {
    analogWrite(motorPin2, outputValue);
    analogWrite(motorPin1, zero);

  
  }
  prev = err;
  delay(0.05);
}
