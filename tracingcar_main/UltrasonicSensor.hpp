#pragma once
#include "PinConfiguration.hpp"
#include "Condition.hpp"
#include "Data.hpp"

// 3つの超音波センサからの距離を返す
void update_centimeter();
void debug_distance();

namespace __ultrasonic_sensor {
  // トリガーピンにHIGHをかける
  inline void triger_high(const uint8_t& triger_pin);
  // トリガーピンにLOWをかける
  inline void triger_low(const uint8_t& triger_pin);
  // エコーピンがHIGHである時間を得る
  inline float echo_high_duration(const uint8_t& echo_pin);
  // パルス波を出力してそのパルス波を受け取る時間を計算
  void pulse_out_calc_duration(const uint8_t& triger_pin, const uint8_t& echo_pin);
}