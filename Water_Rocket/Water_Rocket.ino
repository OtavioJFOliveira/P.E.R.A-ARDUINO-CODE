// LIBRARIES
//-------------------------------------------------------------------------------------------
#include<Wire.h> // Biblioteca utilizada para comunicação I2C
//#include <dht.h> // Biblioteca utilizada para Sensor DHT11
#include <Adafruit_BMP085.h> // Biblioteca utilizada para o sensor MP085
#include <MS5611.h> // Biblioteca utilizada para o sensor MS5611
#include <SdFat.h> //
#include <Servo.h>
//-------------------------------------------------------------------------------------------
// Definiçoes de permissão para execussão do codigo
#define BMP180
//#define DHT11
#define MPU6050
#define MS_5611
#define SD_Shield
#define ServoMotor
//-------------------------------------------------------------------------------------------
/* I2C Address
  

//-------------------------------------------------------------------------------------------
//Pins (See in each function)
  Servo_Pin = 6
  chipSelect = 4
  ISP pins for the SD_Card
//-------------------------------------------------------------------------------------------*/


void setup() 
{
  Serial.begin(115200);

  Data_Logger_Setup();
  Servo_Setup();
  Wire.begin();
  MPU_Setup();
  BMP_Setup();
  MS5611_Setup();

}

void loop() 
{
  Data_Logger(1,5,6);
  //MS5611_Data();
  //MPU_Data();
  //BMP180_Data();
  delay(1000);

}
