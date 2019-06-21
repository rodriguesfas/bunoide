/**
 * Programa: boneca1_tchau.ino
 * Descrição: Movimentação da boneca 2 (Romeira do canto).
 * Autor(es): Professores: Alexsandro Ferreira e Francisco de Assis.
 *            Alunas Wytala, Maria Clara Pereira e Maria Clara Bezerra.
 * Competição: Robocup jr
 * Modalidade: On stage
 * Data: 03/006/2019 
 */

// Inclusão de biblioteca.
#include <VarSpeedServo.h> // Biblioteca dos servos.

//Definição da velocidade de comunicação
#define BAUND_RATE 9600

// Criação dos objetos da biblioteca VarSpeedServo
VarSpeedServo cabeca, ombro_L, ombro_R, braco_L, braco_R;

// Criação das variaveis que irá armazenar as posições dos servos
int pos_cabeca;
int pos_ombro_L; // L = Left = Esquerdo
int pos_ombro_R; // R = Right = Direito
int pos_mao_L;
int pos_mao_R;

// Função de configuração.
void setup()
{
  Serial.begin(BAUND_RATE);

  // Define PIN Servos no Arduino.
  cabeca.attach(2);
  ombro_L.attach(3);
  braco_L.attach(5);
  ombro_R.attach(4);
  braco_R.attach(6);

  // Define posição inicial dos servos.
  cabeca.write(70);   // cabeça reta para frente.
  ombro_L.write(1); // braço esquerdo para baixo.
  braco_L.write(10);
  ombro_R.write(160);   // braço direito para baixo.
  braco_R.write(140);

  delay(1000);
}

// Função principal.
void loop()
{
  delay(200); // Aguarda 200 mili segundos
  bye_bye_LS();
  bye_bye_LS();
  bye_bye_LS();
  baixar_ombro_L();
  bye_bye_R();
  bye_bye_R();
  bye_bye_R();
  bye_bye_R();
  cabeca.write(80); //Retorno da cabeça a possição central
  baixar_ombro_R();
  bye_bye_L();
  bye_bye_L();
  bye_bye_L();
  bye_bye_L();
  cabeca.write(80); //Retorno da cabeça a possição central
  baixar_ombro_L();
  bye_bye_RS();
  bye_bye_RS();
  bye_bye_RS();
  cabeca.write(80);
  baixar_ombro_R();
}

/**
 * Função de movimentação da cabeça.
 */
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

/**
 * Função para levantar os braços esquerdo e direito.
 */
void levanta_bracos_L_R()
{
  levantar_ombro_L();
  levantar_ombro_R();
}

/**
 * Função para abaixar os o braços esquerdo e direito.
 */
void baixa_bracos_L_R()
{
  baixar_ombro_L();
  baixar_ombro_R();
}

void levantar_ombro_L()
{
  // grau | velocidade do moveimento, True ou False (esperar o movimento terminar para fazer o outro)
  ombro_L.write(0, 100, true);
}

void levantar_ombro_R()
{
  ombro_R.write(180, 100, true);
}

void baixar_ombro_L()
{
  ombro_L.write(180, 100, true);
}

void baixar_ombro_R()
{
  ombro_R.write(0, 100, true);
}

void bye_bye_L()
{
  cabeca.write(120, 30, true);
  ombro_L.write(10, 30, true);
  braco_L.write(90, 60, true);
  braco_L.write(180, 50, true);
}

void bye_bye_LS()
{
  ombro_L.write(10, 30, true);
  braco_L.write(90, 60, true);
  braco_L.write(180, 50, true);
}

void bye_bye_R()
{
  cabeca.write(20, 30, true);
  ombro_R.write(130, 30, true);
  braco_R.write(45, 60, true);
  braco_R.write(0, 50, true);
}

void bye_bye_RS()
{
  ombro_R.write(130, 30, true);
  braco_R.write(45, 60, true);
  braco_R.write(0, 50, true);
}

void move_cabeca1()
{

  for (pos_cabeca = 80; pos_cabeca > 20; pos_cabeca--)
  {
    cabeca.write(pos_cabeca);
    delay(15);
  }

  delay(1000);

  for (pos_cabeca = 20; pos_cabeca <= 80; pos_cabeca++)
  {
    cabeca.write(pos_cabeca);
    delay(15);
  }

  delay(1000);
}
