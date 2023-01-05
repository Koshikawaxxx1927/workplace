#include "PinConfiguration.hpp"

void pin::Initialize() {
  // モーターの回転の向きを制御するピン
  pinMode(pin::left_motor.motor1, OUTPUT);
  pinMode(pin::left_motor.motor2, OUTPUT);
  pinMode(pin::right_motor.motor2, OUTPUT);
  pinMode(pin::right_motor.motor1, OUTPUT);
  // モーターの回転速度を制御するピン
  pinMode(pin::left_motor.pwm, OUTPUT);
  pinMode(pin::right_motor.pwm, OUTPUT);

  // 超音波センサのトリガーピンとエコーピン
  // 左側
  pinMode(pin::left_sensor.triger, OUTPUT);
  pinMode(pin::left_sensor.echo, INPUT);
  // 中央
  pinMode(pin::center_sensor.triger, OUTPUT);
  pinMode(pin::center_sensor.echo, INPUT);
  // 右側
  pinMode(pin::right_sensor.triger, OUTPUT);
  pinMode(pin::right_sensor.echo, INPUT);

  // 赤外線センサ用の入力ピン
  attachInterrupt(pin::ir-2, detected_obstacle, LOW);
}