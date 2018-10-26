/**
   Software: Bunoide
   Description: Esse programa move a cabeça e os braços do Bunoide.
   Date: 25/10/2018
   Author: RodrigueFAS
   Email: franciscosouzaacer@gmail.com
   Site: http://rodriguesfas.com.br
*/

// https://github.com/netlabtoolkit/VarSpeedServo
#include <VarSpeedServo.h>

#define BAUND_RATE 9600

VarSpeedServo head, shoulder_left, shoulder_rigth, arm_left, arm_rigth;

int pos_head;
int pos_shoulder_left;
int pos_shoulder_rigth;
int pos_arm_left;
int pos_arm_rigth;

void setup() {
  Serial.begin(BAUND_RATE);

  // Define pin conection servos.
  head.attach(3);
  shoulder_left.attach(5);
  shoulder_rigth.attach(6);
  arm_left.attach(10);
  arm_rigth.attach(11);

  // Define position initial servos.
  head.write(80);
  shoulder_left.write(180);
  shoulder_rigth.write(0);
  arm_left.write(180);
  arm_rigth.write(0);

  delay(1000);
}

void loop() {
  //move_head();
  //bye_bye_left();
  //bye_bye_rigth();
  move_both_arms();
}

void move_head() {

  for (pos_head = 0; pos_head < 90; pos_head++) {
    head.write(pos_head);
    delay(15);
  }

  delay(1000);

  for (pos_head = 90; pos_head >= 0; pos_head--) {
    head.write(pos_head);
    delay(15);
  }

  delay(1000);

}

void move_shoulder_left() {
  for (pos_shoulder_left = 90; pos_shoulder_left >= 0; pos_shoulder_left--) {
    shoulder_left.write(pos_shoulder_left);
    delay(15);
  }
}

void move_arm_left() {}

void move_shoulder_rigth() {}

void move_arm_rigth() {}

void move_both_arms() {
  down_shoulder_left();
  down_shoulder_rigth();

  up_shoulder_left();
  up_shoulder_rigth();
}

void up_shoulder_left() {
  shoulder_left.write(0, 50, true);
}

void up_shoulder_rigth() {
  shoulder_rigth.write(180, 50, true);
}

void down_shoulder_left() {
  shoulder_left.write(180, 50, true);
}

void down_shoulder_rigth() {
  shoulder_rigth.write(0, 50, true);
}

void bye_bye_left() {
  shoulder_left.write(90);
  arm_left.write(90, 50, true);
  arm_left.write(180, 30, true);
}

void bye_bye_rigth() {
  shoulder_rigth.write(90);
  arm_rigth.write(45, 30, true);
  arm_rigth.write(0, 30, true);
}
