#ifdef SD_Shield
 
SdFat sdCard;
SdFile meuArquivo;
 
// Pino ligado ao CS do modulo
const int chipSelect = 10;
int aux =1;

void Data_Logger_Setup()
{
  if(!sdCard.begin(chipSelect,SPI_HALF_SPEED))sdCard.initErrorHalt();
   meuArquivo.println("Aceleração Temperatura Altura  Giro");
  
  if (!meuArquivo.open("Data_PERA.txt", O_RDWR | O_CREAT | O_AT_END))  // Abre o arquivo LER_POT.TXT
  {
    sdCard.errorHalt("Erro na abertura do arquivo LER_POT.TXT!");
  }
    
}
 
void Data_Logger(float Data_1,float Data_2,float Data_3)
{
    
  meuArquivo.print(Data_1);
  meuArquivo.print("      ");
  delay(20);
  meuArquivo.print(Data_2);
  meuArquivo.print("      ");
  delay(20);
  meuArquivo.println(Data_3);
  meuArquivo.close();
  
  //delay(1000);
}

#endif
