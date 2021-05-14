#ifdef MS_5611

MS5611 ms5611;
 
double referencePressure;

void MS5611_Setup()
{
   while(!ms5611.begin())
    {
     Serial.println("Could not find a valid MS5611 sensor, check wiring!");
     delay(500);
    }
   // Get reference pressure for relative altitude
   referencePressure = ms5611.readPressure();

   Serial.print("Oversampling: ");
   Serial.println(ms5611.getOversampling());
}

float MS5611_Data()
{
  // Read raw values
  uint32_t rawTemp = ms5611.readRawTemperature();
  uint32_t rawPressure = ms5611.readRawPressure();
 
  // Read true temperature & Pressure
  double realTemperature = ms5611.readTemperature();
  long realPressure = ms5611.readPressure();
 
  // Calculate altitude
  float absoluteAltitude = ms5611.getAltitude(realPressure);
  float relativeAltitude = ms5611.getAltitude(realPressure, referencePressure);
 
  Serial.println("MS5611 Sensor:");
 
  Serial.print(" rawTemp = ");
  Serial.println(rawTemp, " *C");
  Serial.print("RealTemp = ");
  Serial.println(realTemperature, " *C");
   
  Serial.print("RawPressure = ");
  Serial.println(rawPressure, " Pa");
  Serial.print("RealPressure = ");
  Serial.println(realPressure, " Pa");
   
  Serial.print("AbsoluteAltitude = ");
  Serial.println(absoluteAltitude, "M");
  Serial.print("RelativeAltitude = ");
  Serial.println(relativeAltitude, "M");

  Serial.println("------------------------------------------------");
 
  return(relativeAltitude,realPressure,realTemperature);
 
  delay(1000);
}


#endif
