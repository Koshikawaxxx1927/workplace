#include "UltrasonicSensor.hpp"

void update_centimeter() {
  // accum_num回分超音波センサの値を更新する
  // triger_pinがLOWになっているように確認
  __ultrasonic_sensor::triger_low(pin::left_sensor.triger);
  __ultrasonic_sensor::triger_low(pin::center_sensor.triger);
  __ultrasonic_sensor::triger_low(pin::right_sensor.triger);
  delayMicroseconds(4);

  // HIGHのパルス波を受け取っている時間を計算
  left_sensor.update(constrain(pulse_out_calc_duration(pin::left_sensor.triger, pin::left_sensor.echo), 0, distance::far));
  // 60msの間隔を空けることを推奨
  delayMicroseconds(60000);
  // HIGHのパルス波を受け取っている時間を計算
  center_sensor.update(constrain(pulse_out_calc_duration(pin::center_sensor.triger, pin::center_sensor.echo), 0, distance::far));
  // 60msの間隔を空けることを推奨
  delayMicroseconds(60000);
  // HIGHのパルス波を受け取っている時間を計算
  right_sensor.update(constrain(pulse_out_calc_duration(pin::right_sensor.triger, pin::right_sensor.echo), 0, distance::far));
  // 60msの間隔を空けることを推奨
  delayMicroseconds(60000);

  centimeter.left = left_sensor.average();
  centimeter.center = center_sensor.average();
  centimeter.right = right_sensor.average();
}

// パルス波を出力してそのパルス波を受け取る時間を計算
uint16_t pulse_out_calc_duration(const uint8_t& triger_pin, const uint8_t& echo_pin) {
  constexpr uint16_t data_sheet = 58; // cmにするための値(データシートにあり)
  // triger_pinから10μsのパルス波を出力
  __ultrasonic_sensor::triger_high(triger_pin);
  delayMicroseconds(10);
  __ultrasonic_sensor::triger_low(triger_pin);
  // HIGHのパルス波を受け取っている時間を計算
  return static_cast<uint16_t>(pulseIn(echo_pin, HIGH)) / data_sheet;
}

inline void __ultrasonic_sensor::triger_high(const uint8_t& triger_pin) {
  // triger_pinがLOWになっているように確認
  digitalWrite(triger_pin, HIGH);
}

inline void __ultrasonic_sensor::triger_low(const uint8_t& triger_pin) {
  // triger_pinがLOWになっているように確認
  digitalWrite(triger_pin, LOW);
}

inline float __ultrasonic_sensor::echo_high_duration(const uint8_t& echo_pin) {
  // echo_pinがHIGHになっている時間を計測
  return pulseIn(echo_pin, HIGH);
}

// デバッグ用の関数
void debug_distance() {
  Serial.print("right: ");
  Serial.print(centimeter.right);
  Serial.println("cm");
  Serial.print("center: ");
  Serial.print(centimeter.center);
  Serial.println("cm");
  Serial.print("left: ");
  Serial.print(centimeter.left);
  Serial.println("cm");
}