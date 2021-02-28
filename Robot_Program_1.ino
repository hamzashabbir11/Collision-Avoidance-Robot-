int trig1=12;
int eco1=13;
int trig2=8;
int eco2=2;
int trig3=10;
int eco3=11;
int motor11=9;
int motor12=3;
int motor21=5;
int motor22=6;
int front;
int left;
int right;
void setup()
{
 Serial.begin(9600);
  // put your setup code here, to run once:
  
pinMode(trig1, OUTPUT);
pinMode(eco1, INPUT);
pinMode(trig2, OUTPUT);
pinMode(eco2, INPUT);
pinMode(trig3, OUTPUT);
pinMode(eco3, INPUT);
pinMode(motor11, OUTPUT);
pinMode(motor12, OUTPUT);
pinMode(motor21, OUTPUT);
pinMode(motor22, OUTPUT);
}
int sensor(int trig, int eco){
  int result;
  digitalWrite(trig, LOW);
  delayMicroseconds(1);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  result=pulseIn(eco, HIGH);
  result=result*0.034/2;
  return result;
 }
 void Stop(){
   analogWrite(motor11, 0);
   analogWrite(motor12, 0);
   analogWrite(motor21, 0);
   analogWrite(motor22, 0);
   delay(200);
 }
void loop() {
  // put your main code here, to run repeatedly:
  front=sensor(trig1, eco1);
    left=sensor(trig2, eco2);
  right=sensor(trig3, eco3);
  if ((front>28)){
   analogWrite(motor11, 100);
   analogWrite(motor12, 0);  
   analogWrite(motor21, 107);
   analogWrite(motor22, 0);
  left=sensor(trig2, eco2);
  right=sensor(trig3, eco3);
  while(left<11){
    analogWrite(motor21, 125);
   analogWrite(motor22, 0);
   analogWrite(motor11, 100);
   analogWrite(motor12, 0);
   delay(100);
   break;
   left=11;
  }
   while(right<11){
    analogWrite(motor21, 107);
   analogWrite(motor22, 0);
   analogWrite(motor11, 122);
   analogWrite(motor12, 0);
   delay(100);
   break;
   right=11;
  }
   delay(10); 
  }
  else if((left>right)&&(left>20)){
    Stop();
   analogWrite(motor11, 255);
   analogWrite(motor12, 0);
   analogWrite(motor21, 0);
   analogWrite(motor22, 0);
   delay(460); 
  }
  else if((right>left)&&(right>20)){
    Stop();
   analogWrite(motor11, 0);
   analogWrite(motor12, 0);
   analogWrite(motor21, 255);
   analogWrite(motor22, 0);
   delay(460);
  }
  Serial.print(front);
  Serial.print("      ");
  Serial.print(left);
  Serial.print("      ");
  Serial.print(right);
  Serial.print("       ");
}
