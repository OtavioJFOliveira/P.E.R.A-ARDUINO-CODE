#ifdef DHT11

#define dht_dpin 5 //Pino DATA do Sensor ligado na porta Analogica A1
dht DHT; //Inicializa o sensor

int Humidity;
int Temperature;
 
int DHT_Data()
{
    DHT.read11(dht_dpin); //Lê as informações do sensor  
    Humidity = DHT.humidity;
    Temperature = DHT.temperature;
    
    Serial.print("Umidade " + Humidity);
    Serial.print(" %");
    Serial.print("Temperatura " + Temperature);
    Serial.print(" °C");
    Serial.println("------------------------------------------------");

    return(Temperature,Humidity);   
  
    delay(2000);//Não diminuir o valor abaixo. O ideal é a leitura a cada 2 segundos  delay(2000);
}

#endif
