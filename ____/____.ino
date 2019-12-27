#include <SoftwareSerial.h> 
SoftwareSerial BT(8, 9); // 接收腳, 傳送腳
char ch;
int LED=0; // 儲存LED 目前狀態
void setup()
{
Serial.begin(9600); // 這行主要是設定和電腦的COM 通訊的

BT.begin(9600); // 這行主要是設定和藍芽 通訊的速度
pinMode(5, OUTPUT); // 設定腳位5 為輸出模式
Serial.println("BT Ready");
}

void loop()
{
if (BT.available()) // 檢查手機端是否有訊息來
{
ch = BT.read(); // 若有訊息, 一次讀取一個byte
Serial.println(ch);
if (ch == 'a' ) // 判斷是否為a 的訊息
{
digitalWrite(5, HIGH); // 點亮腳位5 的燈
LED=HIGH; // 變更LED 狀態為ON
}
else if (ch == 'b' ) 
{
digitalWrite(5, LOW);
LED=LOW;
}
}
}
