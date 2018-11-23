#include "../Config.h"
#include "Controle.h"
#include "../objetos/BancoBateria.h"
//Placa de REde
#include <SPI.h>
#include <Ethernet.h>
#include <Arduino.h>
//EEPROM
#include <EEPROM.h>
EthernetClient client;

/**
* Metodo inicialização do modulo
*/
void Controle::inicializaModulo(BancoBateria* bateria){
  _bateria = bateria;
  Serial.begin(velocidade_serial);
  Serial.println("## -- Iniciou Setup -- ##");
  calibraInicio();
  ativaRedeDHCP();
  verificaReferenciaCalculo();
  Serial.println("## -- Fim Setup -- ##");
}

/*
verifica referencias de leitura do calculo
*/
void Controle::verificaReferenciaCalculo(){
  //Inicializa banco de Bateria -> constroi celulas.
  _bateria->inicializaBanco();
  //Inicializa celulas com valores
  for(int i=0; i<_bateria->getQuantidadeCelulas();i++){
    //Verifica se tem referencia registrada na EEprom
    float x;
    EEPROM.get(i, x);
    //Cria Objeto.
    ObjCelula obj;
    obj.setNumeroCelula(i+1);
    obj.setReferencia(x);
    obj.setLeituraTensao(3.98);
    _bateria->setCelula(obj, i);
  }
}

/*
* Ativa rede / DHCP
*/
void Controle::ativaRedeDHCP(){
  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH);
  Serial.println("Ativando DHCP");
  byte mac[] = {
    0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
  };

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Erro ao configurar via DHCP");
    // no point in carrying on, so do nothing forevermore:
    while(true);
  }
  // print your local IP address:
  Serial.print("Endereço IP: ");
  Serial.println(Ethernet.localIP());
  Serial.print("Endereço gateway: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("Endereço DNS: ");
  Serial.println(Ethernet.dnsServerIP());
  Serial.println();
}

/*
* Calibração inicial.
*/
void Controle::calibraInicio(){
  Serial.println("Inicia Calibracao");

  #ifdef aRefS1
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS2
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS3
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS4
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS5
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS6
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS7
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS8
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS9
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);

  #ifdef aRefS10
  _bateria->setQuantidadeCelulas(_bateria->getQuantidadeCelulas()+1);
  Serial.print("Celula ");
  Serial.print(_bateria->getQuantidadeCelulas());
  Serial.println(" configurada...");
  #endif
  delay(300);
  Serial.print("Total de Celulas configuradas = ");
  Serial.println(_bateria->getQuantidadeCelulas());
  delay(300);
  Serial.println("Configura portas de entrada e Saida");
  int porta_digital = 0;
  for(int i =1; i<=_bateria->getQuantidadeCelulas();i++){
    //pinMode(i, INPUT);
    Serial.print("Setando porta analogica A");
    Serial.print(i);
    Serial.println(" entrada.");

    porta_digital = i+30;
    Serial.print("Setando porta Digital ");
    Serial.print(porta_digital);
    Serial.println(" saida nivel baixo(low).");
    pinMode(porta_digital, OUTPUT);
    digitalWrite(porta_digital, LOW);
  }
  delay(1000);
}




/*
verifica referencias de leitura do calculo
*/
void Controle::ciloProcessamento(){
  _bateria->imprimeDados();
  delay(3000);
}
