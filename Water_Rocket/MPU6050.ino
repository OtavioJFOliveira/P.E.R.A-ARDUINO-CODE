#ifdef MPU6050
 
 const int MPU=0x68; //Endereco I2C do MPU6050 

 int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ; //Variaveis para armazenar valores dos sensores

 float Temperature;


 void MPU_Setup()
 {
    Wire.beginTransmission(MPU);
    Wire.write(0x6B); 
    Wire.write(0);   //Inicializa o MPU-6050
    Wire.endTransmission(true);
 }
 
int MPU_Data()
{
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  //Solicita os dados do sensor
  Wire.requestFrom(MPU,14,true); 

  Serial.println("MPU-6050 Sensor:");
   
  //Read the sensor 
  AcX=Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

   
  //Envia os valores dos eixos do acelerometro
  Serial.print("AcX = "); 
  Serial.print(AcX);
  Serial.print(" | AcY = "); 
  Serial.print(AcY);
  Serial.print(" | AcZ = ");
  Serial.print(AcZ);
  Serial.println("");
  
  //-----------------------------------------------------------------------------------
  Temperature = Tmp/340.00+36.53; //Calcula a temperatura em graus Celsius
  Serial.print("Tmp = ");
  Serial.println(Temperature);
  //-----------------------------------------------------------------------------------

  //Envia os valores dos eixos do girocopio 
  Serial.print("GyX = ");
  Serial.print(GyX);
  Serial.print(" | GyY = ");
  Serial.print(GyY);
  Serial.println(" | GyZ = ");
  Serial.print(GyZ);
  Serial.println("------------------------------------------------");

  return(AcX,AcY,AcZ, Temperature,GyX,GyY,GyZ);

  delay(300); //Aguarda 300 ms e reinicia o processo
}

#endif
