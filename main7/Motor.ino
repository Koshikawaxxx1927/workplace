#include "Motor.hpp"
#include "PinConfiguration.hpp"

// PWM値を与えて前進する関数
void forward(uint8_t left_pwm, uint8_t right_pwm) {
  // 後進中だったら前進に切り替え
  if (!__motor::is_forward) {
    __motor::forward_rotation(pin::left_motor.motor1, pin::left_motor.motor2);
    __motor::forward_rotation(pin::right_motor.motor1, pin::right_motor.motor2);
    __motor::is_forward = true;
  }
  // PWM値を更新
  __motor::pwm_update(pin::left_motor.pwm, left_pwm);
  __motor::pwm_update(pin::right_motor.pwm, right_pwm);
}
// PWM値を与えて後進する関数
void backward(uint8_t left_pwm, uint8_t right_pwm) {
  // 後進中だったら前進に切り替え
  if (__motor::is_forward) {
    __motor::backward_rotation(pin::left_motor.motor1, pin::left_motor.motor2);
    __motor::backward_rotation(pin::right_motor.motor1, pin::right_motor.motor2);
    __motor::is_forward = false;
  }
  // PWM値を更新
  __motor::pwm_update(pin::left_motor.pwm, left_pwm);
  __motor::pwm_update(pin::right_motor.pwm, right_pwm);
}

// 前回転
void __motor::forward_rotation(const uint8_t& motor_pin1, const uint8_t& motor_pin2) {
  digitalWrite(motor_pin1, HIGH);
  digitalWrite(motor_pin2, LOW);
}
// 後ろ回転
void __motor::backward_rotation(const uint8_t& motor_pin1, const uint8_t& motor_pin2) {
  digitalWrite(motor_pin1, LOW);
  digitalWrite(motor_pin2, HIGH);
}
// PWM制御で回転速度を調節
void __motor::pwm_update(const uint8_t& pwm_pin, uint8_t pwm) {
  analogWrite(pwm_pin, constrain(pwm, 0, 255));
}