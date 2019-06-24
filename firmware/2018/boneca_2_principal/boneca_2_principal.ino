//Programa: Codigo para movimentação da boneca 2 (Romeira do meio)
//Alunas: Wytala,  Maria Clara Pereira e Maria Clara Bezerra
//Competição: Torneio Juvenil de Robótica
//Modalidade: On stage

//Inclusão de bibliotecas
#include <Ultrasonic.h>    //Biblioteca do sensor Ultrassônico
#include <VarSpeedServo.h> //Biblioteca dos servos

//Definição da velocidade de comunicação
#define BAUND_RATE 9600

//Criação dos objetos da biblioteca VarSpeedServo
VarSpeedServo cabeca, ombro_L, ombro_R, braco_L, braco_R;

//Criação das variaveis que irá armazenar as posições dos servos
int pos_cabeca;
int pos_ombro_L;
int pos_ombro_R;
int pos_mao_L;
int pos_mao_R;

#define TRIGGER_PIN 8 //Definição do pino Trig que será ligado no pino 8 do Arduino
#define ECHO_PIN 9    //Definição do pino Echo que será ligado no pino 9 do Arduino

float distancia; // Criação de váriavel que armazenar a distância

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN); //Criação de objeto que se referencia a biblioteca

//Função de configuração
void setup()
{
  Serial.begin(BAUND_RATE);
  // Define PIN Servos no Arduino.
  cabeca.attach(2);
  ombro_L.attach(3);
  braco_L.attach(4);
  ombro_R.attach(5);
  braco_R.attach(6);

  // Define posição inicial dos servos.
  cabeca.write(70); // cabeça reta para frente.
  
  ombro_L.write(170);  // braço esquerdo para baixo.
  braco_L.write(150);

  ombro_R.write(10); // braço direito para baixo.
  braco_R.write(20);

  delay(1000);
}

// Função principal.
void loop()
{

  //Função de leitura e conversão da distância
  long microsec = ultrasonic.timing();
  distancia = ultrasonic.convert(microsec, Ultrasonic::CM);

  //Serial.println(distancia);
  //delay(1000);
  //Condição de acionamento da boneca 2
  if (distancia < 10 && distancia > 0)
  { //Se a distância for menor do 5cm
    delay(200);
    funcao1();
    delay(2000);

    funcao2();
    delay(13000);

    funcao3();
    delay(4000);

    funcao4();
    delay(17000);

    funcao5();
    delay(2800);

    funcao6();
    delay(2000);

    funcao7();
    delay(2000);

    /* CHAMADA DE FUNÇÕES PARA TESTES*/
    /*
    levantar_ombros_total_L_R() ;
    delay(1000);
    baixar_ombros_total_L_R();
    delay(1000);
    levantar_ombro_total_L() ;
    delay(1000);
    levantar_ombro_total_R() ;
    delay(1000);
    baixar_ombro_total_L();
    delay(1000);
    baixar_ombro_total_R() ;
    delay(1000);
    levanta_mao_L() ;
    delay(1000);
    levanta_mao_R();
    delay(1000);
    abaixa_mao_L() ;
    delay(1000);
    abaixa_mao_R();
    delay(1000);
    levanta_ombro_metade_L();
    delay(1000);
    levanta_ombro_metade_R();
    delay(1000);
    baixar_ombros_total_L_R();
    delay(1000);
    bye_bye_L();
    bye_bye_R();
  */
  }

}

/*******************MOVIMENTAÇÃO DA CABEÇA****************************************************************************/
//Função de movimentação da cabeça
void move_cabeca()
{
  for (pos_cabeca = 80; pos_cabeca < 160; pos_cabeca++)
  {
    cabeca.write(pos_cabeca);
    delay(15);
  }
  delay(1000);
  for (pos_cabeca = 160; pos_cabeca >= 80; pos_cabeca--)
  {
    cabeca.write(pos_cabeca);
    delay(15);
  }
  delay(1000);
}

///////////////********************CRIAÇÃO DAS FUNÇÕES DE MOVIMENTAÇÕES DOS SERVOS ********************///////////////
/*************************LEVATAR OS DOIS BRAÇOS TOTAL**********************************************************************/
//Função para levantar os braços esquerdo e direito
void levantar_ombros_total_L_R()
{
  levantar_ombro_total_L();
  levantar_ombro_total_R();
}
/***************************ABAIXA OS DOIS BRAÇOS TOTAL*****************************************************************/
//Função para abaixar os o braços esquerdo e direito
void baixar_ombros_total_L_R()
{
  baixar_ombro_total_L();
  baixar_ombro_total_R();
}
/*****************************LEVANTA O BRAÇO ESQUERDO TOTAL*************************************************************/
void levantar_ombro_total_L()
{
  ombro_L.write(0, 100, true);
}
/*****************************LEVANTA O BRAÇO DIREITO TOTAL*************************************************************/
void levantar_ombro_total_R()
{
  //cabeca.write(20,30, true);
  ombro_R.write(180, 100, true);
}
/*****************************ABAIXA O BRAÇO ESQUERDO TOTAL*************************************************************/
void baixar_ombro_total_L()
{
  ombro_L.write(180, 100, true);
}
/****************************ABAIXA O BRAÇO DIREITO TOTAL**************************************************************/
void baixar_ombro_total_R()
{
  ombro_R.write(0, 100, true);
  delay(1000);
}
/****************************LEVANTA A MÃO ESQUERDA*******************************************************************/
void levanta_mao_L()
{ //Lado esquerdo
  braco_L.write(70, 50, true);
}
/****************************LEVANTA A MÃO DIREITA*******************************************************************/
void levanta_mao_R()
{ //Lado direito
  braco_R.write(75, 50, true);
}
/****************************ABAIXA A MÃO ESQUERDA*******************************************************************/
void abaixa_mao_L()
{ //Lado esquerdo
  braco_L.write(180, 30, true);
}
/****************************ABAIXA A MÃO DIREITA*******************************************************************/
void abaixa_mao_R()
{ //Lado direito
  braco_R.write(0, 30, true);
}
/****************************LEVANTA O BRAÇO ESQUERDO PARCIAL********************************************************/
void levanta_ombro_metade_L()
{
  ombro_L.write(90, 30, true);
}
/****************************ALEVANTA O BRAÇO DIREITO PARCIAL*********************************************************/
void levanta_ombro_metade_R()
{
  ombro_R.write(90, 30, true);
}
/*************************************BYE BYE MÃO ESQUERDA************************************************************/
void bye_bye_L()
{
  cabeca_giro_L();
  levanta_ombro_metade_L();
  levanta_mao_L();
  abaixa_mao_L();
}
/*************************************BYE BYE MÃO DIREITA************************************************************/
void bye_bye_R()
{
  cabeca_giro_R();
  levanta_ombro_metade_R();
  levanta_mao_R();
  abaixa_mao_R();
}
/*************************************GIRO DA CABEÇA PARA DIREITA****************************************************/
void cabeca_giro_R()
{
  cabeca.write(20, 30, true);
}
/*************************************GIRO DA CABEÇA PARA ESQUERDA***************************************************/
void cabeca_giro_L()
{
  cabeca.write(120, 30, true);
}
/**********FUNÇÃO 1 - LEVANTA OS DOIS BRAÇOS UM DA CADA VEZ E MOVIMENTA A CABEÇA PARA OS DOIS LADOS ******************/
void funcao1()
{
  cabeca_giro_R();          //Movimenta acabeça para direita
  levantar_ombro_total_R(); //Levantar o braço direito total
  delay(7000);              //Tempo entre um braço e outro
  cabeca_giro_L();          //Movimenta acabeça para esquerda
  levantar_ombro_total_L(); //Levantar o braço esquerdo total
  cabeca.write(80);         //Retorna a cabeça para o centro
}
/**********FUNÇÃO 2 - LEVANTA OS DOIS BRAÇOS ATÉ A METADE DEPOIS LEVANTA AS MÃOS ******************/
void funcao2()
{
  levanta_ombro_metade_L();
  levanta_ombro_metade_R();
  levanta_mao_L();
  levanta_mao_R();
}
/**********FUNÇÃO 3 - MATÉM AS MÃOS LEVANTADAS E ABAIXA OS DOIS BRAÇOS  ********************************/
void funcao3()
{
  baixar_ombro_total_L();
  baixar_ombro_total_R();
}
/*************************************FUNÇÃO 4 - LEVANTA OS BRAÇOS ATÉ A METADE **************************************/
void funcao4()
{
  levanta_ombro_metade_L();
  levanta_ombro_metade_R();
}
/*************************************FUNÇÃO 5 - LEVANTA OS BRAÇOS ATÉ A METADE **************************************/
void funcao5()
{
  baixar_ombro_total_L();
  abaixa_mao_R();
  levantar_ombro_total_R();
}

void funcao6()
{
  cabeca_giro_R();
  levanta_mao_R();
  abaixa_mao_R();
}

void funcao7()
{
  cabeca_giro_L();
  levanta_ombro_metade_L();
  levanta_mao_L();
  abaixa_mao_L();
}
