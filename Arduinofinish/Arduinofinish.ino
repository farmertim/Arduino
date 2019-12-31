 int LED=13;
int LED1=12;
int LED2=6;
int isobstaclePin=7;
int isobstaclePin1=8;
int isobstacle=HIGH;
int isobstacle1=HIGH;
int check=0,check1=0;
int buzzerPin=9;


void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(buzzerPin,OUTPUT);
pinMode(isobstaclePin,INPUT);
pinMode(isobstaclePin1,INPUT);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
isobstacle=digitalRead(isobstaclePin);
isobstacle1=digitalRead(isobstaclePin1);

    
    
   

if(isobstacle==LOW){
  Serial.println("obstacle!!,obstacle");
  digitalWrite(LED,HIGH);

  check=1;

  }else{
    Serial.println("clear");
    digitalWrite(LED1,LOW);
     digitalWrite(LED,LOW);
     check=0;
    
  }
  delay(300);
if(isobstacle1==LOW){
  Serial.println("obstacle!!,obstacle");
  digitalWrite(LED1,HIGH);
  check1=1;

  }else{
    Serial.println("clear");
    digitalWrite(LED1,LOW);
     check1=0;
  }

  if(check==1&&check1==1){
  
    digitalWrite(LED2,HIGH);
     digitalWrite(LED,LOW);
      digitalWrite(LED1,LOW);
 digitalWrite(buzzerPin,LOW);
    }
    else{
      if(check==1){

    digitalWrite(buzzerPin,LOW);
      digitalWrite(buzzerPin,HIGH);
    for(int i=0;i<1500;i++){
    tone(buzzerPin,i,10);
    delay(1);
    }
  for(int i=1500;i>120;i--){
    tone(buzzerPin,i,10);
    delay(1);
      }
       //digitalWrite(buzzerPin,LOW);
       digitalWrite(LED2,LOW);
      
 //digitalWrite(buzzerPin,LOW);
      }
    }

}
