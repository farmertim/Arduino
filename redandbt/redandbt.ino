#include <SoftwareSerial.h> 
SoftwareSerial BT(4, 3); // 接收腳, 傳送腳
int LED=13;
int LED1=12;
int LED2=6;
char ch;
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

BT.begin(9600); // 這行主要是設定和藍芽 通訊的速度
pinMode(6, OUTPUT); // 設定腳位5 為輸出模式
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

if (BT.available()) // 檢查手機端是否有訊息來
{
ch = BT.read(); // 若有訊息, 一次讀取一個byte
Serial.println(ch);
if (ch == 'a' ) // 判斷是否為a 的訊息
{
digitalWrite(6, HIGH); // 點亮腳位5 的燈
LED2=HIGH; // 變更LED 狀態為ON
}
else if (ch == 'b' ) 
{
digitalWrite(6, LOW);
LED2=LOW;
}
}
  
}
