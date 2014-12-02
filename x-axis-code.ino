#include <Stepper.h>
#define STEPS 200  //定義步進馬達每圈的步數
Stepper stepper(STEPS, 1, 5, 7, 10);

void setup() {
  stepper.setSpeed(140);     // 將馬達的速度設定成140RPM 最大  150~160
}

void loop() {
  for (int i =100 ;i<=650;i=i+50 ){
    stepper.step(i);//正半圈
    delay(500);
    stepper.step(-i);//反半圈
    delay(500);
  }
}
