int LED=13;
int LED1=12;
int LED2=6;
int isobstaclePin=7;
int isobstaclePin1=8;
int isobstacle=HIGH;
int isobstacle1=HIGH;
int check=0,check1=0;

void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(isobstaclePin,INPUT);
pinMode(isobstaclePin1,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
isobstacle=digitalRead(isobstaclePin);
isobstacle1=digitalRead(isobstaclePin1);

if(isobstacle1==LOW){
  Serial.println("obstacle!!,obstacle");
  digitalWrite(LED1,HIGH);
  check=1;
  //int x=digitalRead(isobstaclePin);
  //Serial.println(x);
  }else{
    Serial.println("clear");
    digitalWrite(LED1,LOW);
     check=0;
  }

if(isobstacle==LOW){
  Serial.println("obstacle!!,obstacle");
  digitalWrite(LED,HIGH);
  check1=1;
  
  }else{
    Serial.println("clear");
    digitalWrite(LED,LOW);
    check1=0;
  }
  if(check==1&&check1==1){
    digitalWrite(LED2,HIGH);
     digitalWrite(LED,LOW);
      digitalWrite(LED1,LOW);
    
    }
    else{
       digitalWrite(LED2,LOW);
      }
  delay(200);
}
