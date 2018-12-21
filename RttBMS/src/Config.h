/*
 _____    _     _     ____    __  __    _____
|  __ \  | |   | |   |  _ \  |  \/  |  / ____|
| |__) | | |_  | |_  | |_) | | \  / | | (___
|  _  /  | __| | __| |  _ <  | |\/| |  \___ \
| | \ \  | |_  | |_  | |_) | | |  | |  ____) |
|_|  \_\  \__|  \__| |____/  |_|  |_| |_____/

Projeto desenvolvido por Samuel Rettore
email -> rettore@gmail.com

Baseado no projeto BMSDuino @autor Claudio - Solar Souzam
Canal -> https://www.youtube.com/watch?v=0L6wfxrfS9M&t=1s

Definicao de Quantos S(QUANTIDADE_CELULAS) ...ou celulas tem o Sistema
Por exemplo um Projeto de 2S(duas celulas) segue o seguinte mapeamento
A8 para leitura de tensao e 31 para controle da celulas:
A8 - > 31
A9 - > 33
......

Define tensao inicial(leitura multimetro) das celulas do banco usado para calculo, referencia da leitura
SE VOCE DEFINIR 2 CELULAS o sistema entendera que seu banco terá duas celulas,
se definir 7 usará mesma logica.

Ex 3S ou 3 CELULAS

#define QUANTIDADE_CELULAS 3

O sistema ira definir a porta A8 para o leitor de tensão da celula 1 e o 31 aciona sistema de resistor para equalizar celula
O sistema ira definir a porta A9 para o leitor de tensão da celula 2 e o 33 aciona sistema de resistor para equalizar celula
O sistema ira definir a porta A10 para o leitor de tensão da celula 3 e o 35 aciona sistema de resistor para equalizar celula

Ex 7S ou 7 CELULAS

#define QUANTIDADE_CELULAS 7

O sistema ira definir a porta A8 para o leitor de tensão da celula 1 e o 31 aciona sistema de resistor para equalizar celula
O sistema ira definir a porta A9 para o leitor de tensão da celula 2 e o 33 aciona sistema de resistor para equalizar celula
O sistema ira definir a porta A10 para o leitor de tensão da celula 3 e o 35 aciona sistema de resistor para equalizar celula
O sistema ira definir a porta A11 para o leitor de tensão da celula 4 e o 37 aciona sistema de resistor para equalizar celula
O sistema ira definir a porta A12 para o leitor de tensão da celula 5 e o 39 aciona sistema de resistor para equalizar celula
O sistema ira definir a porta A13 para o leitor de tensão da celula 6 e o 41 aciona sistema de resistor para equalizar celula
O sistema ira definir a porta A14 para o leitor de tensão da celula 7 e o 43 aciona sistema de resistor para equalizar celula

Abaixo pré definido sistema de 7S ou 7 celulas
*/
//Aqui define o tamanho do seu banco em celulas ou S
#define QUANTIDADE_CELULAS 1

//Calculo Baseado no resistor
//Tensao Referencia porta analogica Arduino
#define TENSAO_REFERENCIA 5.03

//Configuracao do alor referncial que a bms trabalha em mV
#define BMS 0.060
//Tensao Minima BMS para de atuar
#define MIN_VOLTAGE 23.1
//Tensao Minima por celula
#define MIN_VOLTAGE_CELL 3.30
//Tensao Minima por celula
#define MAX_VOLTAGE_CELL 4.10

//Porta controla rele contatora inversor
#define CONTATORA_INVERSOR 30
/*
  Dados de leitura com divisor de tensao
*/
#define AMOSTRAS 2000
#define RELACAO 18.18500 //11.86
//#define RELACAO 17.72637 //4.2
/*
Dados MQTT
*/
//#define BROKER_MQTT "iot.eclipse.org"
#define BROKER_MQTT "dev.serhmatica.com.br"
#define BROKER_PORT 1883
#define MQTT_QOS 1
#define ID_MQTT "ArduinoMQTT"
#define MQTT_VERSION MQTT_VERSION_3_1_1

//Esta Chave deve ser criada peloAPP RTTHome e atualizada aqui para comunicação.
#define MQTT_TOPIC "asdkabsdaisyudtas5a76sd"

/*
  Outros dados
*/
//Configuracoes placa de rede.
#define W5100_CS  10
#define SDCARD_CS 4
//Velocidade Serial Arduino
#define VELOCIDADE_SERIAL_ARDUINO 115200
