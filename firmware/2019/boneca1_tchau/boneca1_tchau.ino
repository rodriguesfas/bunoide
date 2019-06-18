/**
 * Programa: boneca1_tchau.ino
 * Descrição: Movimentação da boneca 2 (Romeira do canto).
 * Autor(es): Professores: Alexsandro Ferreira e Francisco de Assis.
 *            Alunas Wytala, Maria Clara Pereira e Maria Clara Bezerra.
 * Competição: Robocup jr
 * Modalidade: On stage
 * Data: 03/006/2019 
 */

// Inclue bibliotecas
#include <Servo.h>
#include <Ultrasonic.h>
#include <DMPH.h>

// Configura taxa de transmição do monitor serial.
#define BAUND_RATE 9600

// Configura sensor ultrasonic.
#define TRIGGER_PIN 22
#define ECHO_PIN 23
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

// Configura pinos da Ponte H.
#define N1 12
#define N2 11
#define ENA 13

#define N3 10
#define N4 9
#define ENB 8

// Cria objetos motor esquerdo e direito.
DMPH motor_L(N1, N2, ENA);
DMPH motor_R(N3, N4, ENB);

// Cria objetos servos motores.
Servo cabeca, ombro_L, ombro_R, braco_L, braco_R;

// variaveis que irá armazenar as posições dos servos.
int pos_cabeca;
int pos_ombro_L;
int pos_ombro_R;
int pos_braco_L;
int pos_braco_R;

void setup()
{
  Serial.begin(BAUND_RATE);

  // Define PIN Servos no Arduino.
  cabeca.attach(2);
  ombro_L.attach(3);
  braco_L.attach(5);
  ombro_R.attach(4);
  braco_R.attach(6);

  // Define posição inicial dos membros.
  cabeca.write(70);
  ombro_L.write(1);
  braco_L.write(10);
  ombro_R.write(160);
  braco_R.write(140);

  delay(1000);
}

void loop()
{
  sonar();

  //move_cabeca_para_esquerda();
  //move_cabeca_para_direita();

  //levanta_bracos_L_R();

  //bye_bye_L();
  //bye_bye_R();

  //frente();
  //tras();
  //esquerda();
  //direita();
}

void move_cabeca_para_esquerda()
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

void move_cabeca_para_direita()
{

  for (pos_cabeca = 80; pos_cabeca > 10; pos_cabeca--)
  {
    cabeca.write(pos_cabeca);
    delay(10);
  }

  delay(1000);

  for (pos_cabeca = 10; pos_cabeca <= 80; pos_cabeca++)
  {
    cabeca.write(pos_cabeca);
    delay(10);
  }

  delay(1000);
}

void levanta_bracos_L_R()
{
  levantar_ombro_L();
  levantar_ombro_R();
}

void baixa_bracos_L_R()
{
  baixar_ombro_L();
  baixar_ombro_R();
}

void levantar_ombro_L()
{
  ombro_L.write(160);
}

void levantar_ombro_R()
{
  ombro_R.write(1);
}

void baixar_ombro_L()
{
  ombro_L.write(180);
}

void baixar_ombro_R()
{
  ombro_R.write(0);
}

void bye_bye_L()
{
  cabeca.write(120);
  ombro_L.write(120);

  int x;

  for (x = 90; x > 0; x--)
  {
    braco_L.write(x);
    delay(6);
  }

  for (x = 0; x <= 90; x++)
  {
    braco_L.write(x);
    delay(6);
  }
}

void bye_bye_LS()
{
  ombro_L.write(10);
  braco_L.write(90);
  braco_L.write(180);
}

void bye_bye_R()
{
  cabeca.write(10);
  ombro_R.write(20);

  int x;

  for (x = 90; x < 180; x++)
  {
    braco_R.write(x);
    delay(6);
  }

  for (x = 180; x > 90; x--)
  {
    braco_R.write(x);
    delay(6);
  }
}

void bye_bye_RS()
{
  ombro_R.write(130);
  braco_R.write(45);
  braco_R.write(0);
}

void sonar()
{
  float distancia;
  long microsec = ultrasonic.timing();
  distancia = ultrasonic.convert(microsec, Ultrasonic::CM);

  if (distancia < 10 && distancia > 0)
  {
    direita();
    delay(900);
    frente();
    delay(2500);
    esquerda();
    delay(900);
    parar();
    delay(10000000);
  }
}

void frente()
{
  motor_L.move(130);
  motor_R.move(130);
}

void tras()
{
  motor_L.move(-255);
  motor_R.move(-255);
}

void esquerda()
{
  motor_L.move(-200);
  motor_R.move(200);
}

void direita()
{
  motor_L.move(200);
  motor_R.move(-200);
}

void parar()
{
  motor_L.move(0);
  motor_R.move(0);
}
