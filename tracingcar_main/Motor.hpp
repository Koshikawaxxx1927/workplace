#pragma once
#include "PinConfiguration.hpp"

// PWM値を与えて前進する関数
void forward(uint8_t left_pwm, uint8_t right_pwm);
// PWM値を与えて後進する関数
void backward(uint8_t left_pwm, uint8_t right_pwm);

namespace __motor {
  // 前回転
  void forward_rotation(const uint8_t& motor_pin1, const uint8_t& motor_pin2);
  // 後ろ回転
  void backward_rotation(const uint8_t& motor_pin1, const uint8_t& motor_pin2);
  // PWM制御で回転速度を調節
  void pwm_update(const uint8_t& pwm_pin, uint8_t pwm);
  // 前進中かどうか
  bool is_forward = false;
};