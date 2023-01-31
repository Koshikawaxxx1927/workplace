#pragma once

namespace pin {
  void Initialize(); // ピンの入力/出力を初期化
  // モーターに対するピン
  typedef struct {
    // motor_pin1とmotor_pin2でモータの向きを制御
    uint8_t motor1;
    uint8_t motor2;
    // モーターの強さを制御するPWMのピン
    uint8_t pwm;
  } Motor;

  constexpr Motor right_motor = { 5, 4, 6 }; // 右側のモーター
  constexpr Motor left_motor = { 7, 4, 3 }; // 左側のモーター

  // 超音波センサに対するピン
  typedef struct {
    uint8_t triger; // トリガーピン(出力)
    uint8_t echo; // エコーピン(入力
  } UltrasonicSensor;

  constexpr UltrasonicSensor right_sensor = { 9, 8 }; // 右側の超音波センサ
  constexpr UltrasonicSensor center_sensor = { 11, 10 }; // 真ん中の超音波センサ
  constexpr UltrasonicSensor left_sensor = { 13, 12 }; // 左側の超音波センサ
  
  // 赤外線センサのピン
  constexpr uint8_t ir = 2;  // 入力ピン
}