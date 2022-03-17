#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>

#include <ESP32Servo.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

Servo Servo1;
Servo Servo2;

int stateMotor1;
int stateMotor2;

const char* ssid = "WIFIIICT";
const char* password = "fakatijger";
String serverName = "http://10.3.41.36//parking.php";
unsigned long lastTime = 0;
unsigned long timerDelay = 500;
const long timeoutTime = 2000;
WiFiServer  server(80);


String Sensor1State = "0";
String Sensor2State = "0";
String Sensor3State = "0";
String Sensor4State = "0";
String Sensor5State = "0";
String Sensor6State = "0";

//sensoren 34 35
//motoren 32 33


const int PIN_RED6 = 13;
const int PIN_GREEN6 = 12;

const int PIN_RED5 = 14; 
const int PIN_GREEN5 = 27; 

const int PIN_RED4 = 26; 
const int PIN_GREEN4 = 25; 

const int PIN_RED3 = 2; 
const int PIN_GREEN3 = 15; 

const int PIN_RED2 = 4; 
const int PIN_GREEN2 = 5; 

const int PIN_RED1 = 19; 
const int PIN_GREEN1 = 18;


int reading = 0;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{

  lcd.init();                   
  lcd.backlight();
  
  Servo1.attach(32);
  pinMode(34, INPUT);

  Servo2.attach(33);
  pinMode(35, INPUT);
  
  Wire.begin();               
  Serial.begin(115200);

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

int vrijePlaatsen = 0; 
    

void loop(){

  vrijePlaatsen = 0;
  

  //--------------------------------------------------------------------------------------------Sensor 1

    Wire.beginTransmission(122);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
    delay(70);  
    Wire.beginTransmission(122);
    Wire.write(byte(0x02));
    Wire.endTransmission();      
    Wire.requestFrom(122, 2);   
    
    if (2 <= Wire.available()) { 
      reading = Wire.read();  
      reading = reading << 8;    
      reading |= Wire.read(); 
      
      Serial.print("Sensor 1: ");  
      Serial.print(reading);  
      Serial.print(" | ");

      if (reading > 30){
          Sensor1State = "0";
          digitalWrite(PIN_RED1, HIGH);
          digitalWrite(PIN_GREEN1, LOW);
          vrijePlaatsen = vrijePlaatsen + 1;
      }else{
          Sensor1State = "1";
          digitalWrite(PIN_RED1, LOW);
          digitalWrite(PIN_GREEN1, HIGH);
      }
    }


     //--------------------------------------------------------------------------------------------Sensor 2

    Wire.beginTransmission(112);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
    delay(70);  
    Wire.beginTransmission(112);
    Wire.write(byte(0x02));
    Wire.endTransmission();      
    Wire.requestFrom(112, 2);   
    
    if (2 <= Wire.available()) { 
      reading = Wire.read();  
      reading = reading << 8;    
      reading |= Wire.read(); 
      Serial.print("Sensor 2: ");  
      Serial.print(reading);  
      Serial.print(" | ");   

      if (reading > 30){
          Sensor2State = "0";
          digitalWrite(PIN_RED2, HIGH);
          digitalWrite(PIN_GREEN2, LOW);
          vrijePlaatsen = vrijePlaatsen + 1;
      }else{
          Sensor2State = "1";
          digitalWrite(PIN_RED2, LOW);
          digitalWrite(PIN_GREEN2, HIGH);
      }
    }

     //--------------------------------------------------------------------------------------------Sensor 3

    Wire.beginTransmission(123);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
    delay(70);  
    Wire.beginTransmission(123);
    Wire.write(byte(0x02));
    Wire.endTransmission();      
    Wire.requestFrom(123, 2);   
    
    if (2 <= Wire.available()) { 
      reading = Wire.read();  
      reading = reading << 8;    
      reading |= Wire.read(); 
      
      Serial.print("Sensor 3: ");  
      Serial.print(reading);  
      Serial.print(" | ");  

      if (reading > 30){
          Sensor3State = "0";
          digitalWrite(PIN_RED3, HIGH);
          digitalWrite(PIN_GREEN3, LOW);
          vrijePlaatsen = vrijePlaatsen + 1;
      }else{
          Sensor3State = "1";
          digitalWrite(PIN_RED3, LOW);
          digitalWrite(PIN_GREEN3, HIGH);
      }
    }

     //--------------------------------------------------------------------------------------------Sensor 4

    Wire.beginTransmission(114);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
    delay(70);  
    Wire.beginTransmission(114);
    Wire.write(byte(0x02));
    Wire.endTransmission();      
    Wire.requestFrom(114, 2);   
    
    if (2 <= Wire.available()) { 
      reading = Wire.read();  
      reading = reading << 8;    
      reading |= Wire.read(); 
      
      Serial.print("Sensor 4: ");  
      Serial.print(reading);  
      Serial.print(" | "); 

      if (reading > 30){
          Sensor4State = "0";
          digitalWrite(PIN_RED4, HIGH);
          digitalWrite(PIN_GREEN4, LOW);
          vrijePlaatsen = vrijePlaatsen + 1;
      }else{
          Sensor4State = "1";
          digitalWrite(PIN_RED4, LOW);
          digitalWrite(PIN_GREEN4, HIGH);
      }
    }
     //--------------------------------------------------------------------------------------------Sensor 5

    Wire.beginTransmission(120);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
    delay(70);  
    Wire.beginTransmission(120);
    Wire.write(byte(0x02));
    Wire.endTransmission();      
    Wire.requestFrom(120, 2);   
    
    if (2 <= Wire.available()) { 
      reading = Wire.read();  
      reading = reading << 8;    
      reading |= Wire.read(); 
      
      Serial.print("Sensor 5: ");  
      Serial.print(reading);  
      Serial.print(" | ");   

      if (reading > 30){
          Sensor5State = "0";
          digitalWrite(PIN_RED5, HIGH);
          digitalWrite(PIN_GREEN5, LOW);
          vrijePlaatsen = vrijePlaatsen + 1;
      }else{
          Sensor5State = "1";
          digitalWrite(PIN_RED5, LOW);
          digitalWrite(PIN_GREEN5, HIGH);
      }
    }
     //--------------------------------------------------------------------------------------------Sensor 6

    Wire.beginTransmission(121);
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
    delay(70);  
    Wire.beginTransmission(121);
    Wire.write(byte(0x02));
    Wire.endTransmission();      
    Wire.requestFrom(121, 2);   
    
    if (2 <= Wire.available()) { 
      reading = Wire.read();  
      reading = reading << 8;    
      reading |= Wire.read(); 
      
      Serial.print("Sensor 6: ");  
      Serial.print(reading);  
      Serial.print(" | "); 

      if (reading > 30){
          Sensor6State = "0";
          digitalWrite(PIN_RED6, HIGH);
          digitalWrite(PIN_GREEN6, LOW);
          vrijePlaatsen = vrijePlaatsen + 1;
      }else{
          Sensor6State = "1";
          digitalWrite(PIN_RED6, LOW);
          digitalWrite(PIN_GREEN6, HIGH);
      }
    }
    Serial.println("");  

    //--------------------------------------------------------------------------------------------Motor: Poort binnen


    stateMotor1 = digitalRead(34);
      if (stateMotor1 == 0){
        if (Sensor1State == "1" and Sensor2State == "1" and Sensor3State == "1" and Sensor4State == "1" and Sensor5State == "1" and Sensor6State == "1"){
          Serial.println("Alle plaatsen volzet");
        }else{
          Servo1.write(15);
          delay(3000);
        }
          
        
      }else if (stateMotor1 == 1){
        
        Servo1.write(178);
      }
      
    //--------------------------------------------------------------------------------------------Motor: Poort buiten
    
    stateMotor2 = digitalRead(35);
      if (stateMotor2 == 0){
        Servo2.write(15);
        delay(3000);
      }else if (stateMotor2 == 1){
        
        Servo2.write(178);
      }

      //--------------------------------------------------------------------------------------------LCD 20x4

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ingang Smart Parking");
      lcd.setCursor(0,1);
      lcd.print("Vrije plaatsen:  ");
      lcd.print(vrijePlaatsen);
      lcd.setCursor(0,2);
      lcd.print("   Gemaakt door :");
      lcd.setCursor(0,3);
      lcd.print("   Altin en Kenji");
     //-------------------------------------------------------DATA VIA WIFI

  
       if ((millis() - lastTime) > timerDelay) {
        if(WiFi.status()== WL_CONNECTED){
          HTTPClient http;
          String serverPath = serverName +"?" + "par1=" + Sensor1State + "&" + "par2=" + Sensor2State + "&" + "par3=" + Sensor3State + "&" + "par4=" + Sensor4State + "&" + "par5=" + Sensor5State + "&" + "par6=" + Sensor6State;
          Serial.println(serverPath);
          
          http.begin(serverPath);
          
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
       
                  
}
