#include "DHT.h"  // DHT(온도) 라이브러리
#include <LiquidCrystal.h> // LCD 라이브라리 
#include <command.h> // 명령어를 입력받아 처리하는 라이브러리
#include<SoftwareSerial.h> // 블루투스 통신을 위한 라이브러리

LiquidCrystal lcd(12,11,6,5,4,3);
String lcdString = "";
#define DHTPIN 2        // SDA 핀의 설정
#define DHTTYPE DHT11   // DHT22 센서종류 설정
int relay = 10;         //릴레이단자
byte right1[8]={B01110,B10001,B10001,B10001,B10001,B10001,B01110,B00000}; // ㅇ
byte right2[8]={B00001,B00101,B00101,B11101,B00101,B00101,B00001,B00000}; // ㅔ
byte right3[8]={B01110,B10001,B10001,B10001,B10001,B10001,B01110,B00000}; // ㅇ
byte right4[8]={B00010,B00010,B00010,B11110,B00010,B00010,B00010,B00000}; // ㅓ
byte right5[8]={B01110,B00010,B01110,B00010,B00100,B11111,B01000,B01110}; // 콘
DHT dht(DHTPIN, DHTTYPE);
char val;  // 입력받을 명령어
 
void setup() {
  Serial.begin(9600); 
  dht.begin();
  lcd.begin(16,2);
  lcd.createChar(1,right1); // ㅇ
  lcd.createChar(2,right2); // ㅔ
  lcd.createChar(3,right3); // ㅇ
  lcd.createChar(4,right4); // ㅓ
  lcd.createChar(5,right5); // 콘
}

void loop() {
    /*  명령어 입력 */
    if(Serial.available()){
      val = Serial.read();

     /*  명령어 판단 함수 호출*/
      command(val);
    } 
    float temp = dht.readTemperature(); // 온도 센서에서 온도값 읽어오기
    lcd.print("Temp: "); 
    lcd.print(temp);
    lcd.print(" *C");
    /*조건에 따라 에어콘 On/Off를 출력*/
    if(temp>=26)
    {
      lcd.setCursor(0,1);
      lcd.write(1);
      lcd.write(2);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
      lcd.print("On ");
    }
    else if(temp<=25)
    {
      lcd.setCursor(0,1);
      lcd.write(1);
      lcd.write(2);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
      lcd.print("Off");
    }
     lcd.setCursor(0,0);
}
