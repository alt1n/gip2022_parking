#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <LiquidCrystal_I2C.h>

//-------------------------------------------------------LCD

int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
//-------------------------------------------------------Wifi

const char* ssid = "WIFIIICT";
const char* password = "fakatijger";
String serverName = "http://localhost/GIP/parking.php";
unsigned long lastTime = 0;
unsigned long timerDelay = 500;
const long timeoutTime = 2000;

//-------------------------------------------------------Sensors
int reading = 0;
String Sensor1State = "0";
String Sensor2State = "0";
String Sensor3State = "0";
String Sensor4State = "0";
String Sensor5State = "0";
String Sensor6State = "0";
String Sensor7State = "0";
String Sensor8State = "0";

//-------------------------------------------------------Led's

const int PIN_RED = 13; // GIOP23
const int PIN_GREEN = 12; // GIOP22

const int PIN_RED1 = 14; // GIOP23
const int PIN_GREEN1 = 27; // GIOP22

const int PIN_RED2 = 26; // GIOP23
const int PIN_GREEN2 = 25; // GIOP22

const int PIN_RED3 = 33; // GIOP23
const int PIN_GREEN3 = 32; // GIOP22

const int PIN_RED4 = 35; // GIOP23
const int PIN_GREEN4 = 34; // GIOP22

const int PIN_RED5 = 15; // GIOP23
const int PIN_GREEN5 = 2; // GIOP22

const int PIN_RED6 = 4; // GIOP23
const int PIN_GREEN6 = 5; // GIOP22

const int PIN_RED7 = 19; // GIOP23
const int PIN_GREEN7 = 18; // GIOP22
void setup()
{
  lcd.init();                     
  lcd.backlight();
  Wire.begin();               
  Serial.begin(115200);
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
   pinMode(PIN_RED1,   OUTPUT);
  pinMode(PIN_GREEN1, OUTPUT);
   pinMode(PIN_RED2,   OUTPUT);
  pinMode(PIN_GREEN2, OUTPUT);
   pinMode(PIN_RED3,   OUTPUT);
  pinMode(PIN_GREEN3, OUTPUT);
   pinMode(PIN_RED4,   OUTPUT);
  pinMode(PIN_GREEN4, OUTPUT);
   pinMode(PIN_RED5,   OUTPUT);
  pinMode(PIN_GREEN5, OUTPUT);
   pinMode(PIN_RED6,   OUTPUT);
  pinMode(PIN_GREEN6, OUTPUT);
   pinMode(PIN_RED7,   OUTPUT);
  pinMode(PIN_GREEN7, OUTPUT);   

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

    
    

void loop()
    {

      //-------------------------------------------------------DATA VIA WIFI

  
       if ((millis() - lastTime) > timerDelay) {
        if(WiFi.status()== WL_CONNECTED){
          HTTPClient http;
          String serverPath = serverName +"?" + "par1=" + Sensor1State + "&" + "par2=" + Sensor2State + "&" + "par3=" + Sensor3State + "&" + "par4=" + Sensor4State + "&" + "par5=" + Sensor5State + "&" + "par6=" + Sensor6State + "&" + "par7=" + Sensor7State + "&" + "par8=" + Sensor8State;
          Serial.println(serverPath);
          
          http.begin(serverPath.c_str());
          
          int httpResponseCode = http.GET();
          if (httpResponseCode>0) {
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
          }
          else {
            Serial.print("Error code: ");
            Serial.println(httpResponseCode);
          }
          
          http.end();
         }else {
            Serial.println("WiFi Disconnected");
         }
          lastTime = millis();
       }  


      
      Serial.println("   Parking 1:   Parking 2:   Parking 3:   Parking 4:   Parking 5:   Parking 6:   Parking 7:   Parking 8:");
      lcd.setCursor(0, 0);
      
      // ---------------------------------------------------------- Sensor #1
      
      Wire.beginTransmission(122);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();
  
      Wire.beginTransmission(122);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(122, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        if (reading <= 24){
          Serial.print("      1      ");
          lcd.print("P1:1");
          digitalWrite(PIN_RED, HIGH);
          digitalWrite(PIN_GREEN, LOW);
          Sensor1State = "1";
        }else{
          Serial.print("      0      ");
          lcd.print("P1:0");
          digitalWrite(PIN_RED, LOW);
          digitalWrite(PIN_GREEN, HIGH);
          Sensor1State = "0";
        }
      }


      // ---------------------------------------------------------- Sensor #2

      Wire.beginTransmission(124);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();

      delay(70);                  
      Wire.beginTransmission(124);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(124, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        if (reading <= 24){
          lcd.print("P2:1");
          Serial.print("      1      ");
          digitalWrite(PIN_RED1, HIGH);
          digitalWrite(PIN_GREEN1, LOW);
          Sensor2State = "1";
        }else{
          lcd.print("P2:0");
          Serial.print("      0      ");
          digitalWrite(PIN_RED1, LOW);
          digitalWrite(PIN_GREEN1, HIGH);
          Sensor2State = "0";
        }
      }

      // ---------------------------------------------------------- Sensor #3

      Wire.beginTransmission(123);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();
           
      Wire.beginTransmission(123);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(123, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        if (reading <= 24){
          lcd.print("P3:1");
          Serial.print("      1      ");
          digitalWrite(PIN_RED2, HIGH);
          digitalWrite(PIN_GREEN2, LOW);
          Sensor3State = "1";
        }else{
          lcd.print("P3:0");
          Serial.print("      0      ");
          digitalWrite(PIN_RED2, LOW);
          digitalWrite(PIN_GREEN2, HIGH);
          Sensor3State = "0";
        }
      }

      // ---------------------------------------------------------- Sensor #4

      Wire.beginTransmission(112);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();
      
      Wire.beginTransmission(112);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(112, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        if (reading <= 24){
          lcd.print("P4:1");
          Serial.print("      1      ");
          digitalWrite(PIN_RED3, HIGH);
          digitalWrite(PIN_GREEN3, LOW);
          Sensor4State = "1";
        }else{
          lcd.print("P4:0");
          Serial.print("      0      ");
          digitalWrite(PIN_RED3, LOW);
          digitalWrite(PIN_GREEN3, HIGH);
          Sensor4State = "0";
        }
      }

      lcd.setCursor(0,1);


      // ---------------------------------------------------------- Sensor #5

      Wire.beginTransmission(113);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();
            
      Wire.beginTransmission(113);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(113, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        if (reading <= 24){
          lcd.print("P5:1");
          Serial.print("      1      ");
          digitalWrite(PIN_RED4, HIGH);
          digitalWrite(PIN_GREEN4, LOW);
          Sensor5State = "1";
        }else{
          lcd.print("P5:0");
          Serial.print("      0      ");
          digitalWrite(PIN_RED4, LOW);
          digitalWrite(PIN_GREEN4, HIGH);
          Sensor5State = "0";
        }
      }


      // ---------------------------------------------------------- Sensor #6

      Wire.beginTransmission(114);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();
        
      Wire.beginTransmission(114);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(114, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        if (reading <= 24){
          lcd.print("P6:1");
          Serial.print("      1      ");
          digitalWrite(PIN_RED5, HIGH);
          digitalWrite(PIN_GREEN5, LOW);
          Sensor6State = "1";
        }else{
          lcd.print("P6:0");
          Serial.print("      0      ");
          digitalWrite(PIN_RED5, LOW);
          digitalWrite(PIN_GREEN5, HIGH);
          Sensor6State = "0";
        }
      }

      // ---------------------------------------------------------- Sensor #7

      Wire.beginTransmission(120);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();
            
      Wire.beginTransmission(120);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(120, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        if (reading <= 24){
          lcd.print("P7:1");
          Serial.print("      1      ");
          digitalWrite(PIN_RED6, HIGH);
          digitalWrite(PIN_GREEN6, LOW);
          Sensor7State = "1";
        }else{
          lcd.print("P7:0");
          Serial.print("      0      ");
          digitalWrite(PIN_RED6, LOW);
          digitalWrite(PIN_GREEN6, HIGH);
          Sensor7State = "0";
        }
      }

      // ---------------------------------------------------------- Sensor #8

      Wire.beginTransmission(121);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();
             
      Wire.beginTransmission(121);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(121, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        if (reading <= 24){
          lcd.print("P8:1");
          Serial.print("      1      ");
          digitalWrite(PIN_RED7, HIGH);
          digitalWrite(PIN_GREEN7, LOW);
          Sensor8State = "1";
        }else{
          lcd.print("P8:0");
          Serial.print("      0      ");
          digitalWrite(PIN_RED7, LOW);
          digitalWrite(PIN_GREEN7, HIGH);
          Sensor8State = "0";
        }
      }
  delay(100);
  lcd.clear(); 
  Serial.println("");
}
