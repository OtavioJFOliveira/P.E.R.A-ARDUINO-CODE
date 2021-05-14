#ifdef BMP180 // Esse é p pior entre os medidores de altitude e pressão
 
Adafruit_BMP085 bmp180;
 
int BMP_Temperature;
int BMP_Pressure;
int BMP_Altitude;
   
void BMP_Setup()
{
  if (!bmp180.begin()) 
   {
    Serial.println("Sensor nao encontrado !!");
    while (1) {}
   }
}

int BMP180_Data() 
{   
   BMP_Temperature = bmp180.readTemperature();
   BMP_Pressure = bmp180.readPressure();
   BMP_Altitude = bmp180.readAltitude();

   Serial.println("BMP180 Sensor:");

   Serial.print("Temperatura : ");
   Serial.println(BMP_Temperature);
   Serial.print(" | Pressao : ");
   Serial.println(BMP_Pressure);
   Serial.print(" | Altitude : ");
   Serial.println(BMP_Altitude);
   Serial.println("------------------------------------------------");

   return(BMP_Temperature,BMP_Pressure,BMP_Altitude);   

   delay(3000);
}

#endif
