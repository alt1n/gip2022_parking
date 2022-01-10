#include <Wire.h>

    void setup()
    {
      Wire.begin();               
      Serial.begin(9600);          
    }

    int reading = 0;
    int Sensor1Afstand = 0;
    int Sensor2Afstand = 0;
    int Sensor3Afstand = 0;
    

    void loop()
    {
      // ---------------------------------------------------------- Sensor #1
      
      Wire.beginTransmission(112);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();

      delay(70);                  
      Wire.beginTransmission(112);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(112, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        Sensor1Afstand = reading;
      }

      delay(250);

      // ---------------------------------------------------------- Sensor #2

      Wire.beginTransmission(123);
      Wire.write(byte(0x00));
      Wire.write(byte(0x51));
      Wire.endTransmission();

      delay(70);                  
      Wire.beginTransmission(123);
      Wire.write(byte(0x02));
      Wire.endTransmission();      
      Wire.requestFrom(123, 2);   
      
      if (2 <= Wire.available())
      {
        reading = Wire.read();
        reading = reading << 8;
        reading |= Wire.read();
        Sensor2Afstand = reading;
      }

      delay(250);

      // ---------------------------------------------------------- Sensor #3

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
        Sensor3Afstand = reading;
      }

      delay(250);


      Serial.println("   Sensor 1:   Sensor 2:   Sensor 3:");
      Serial.print("    ");
      Serial.print(Sensor1Afstand);
      Serial.print("cm        ");
      Serial.print(Sensor2Afstand);
      Serial.print("cm        ");
      Serial.print(Sensor3Afstand);
      Serial.println("cm");
    }
