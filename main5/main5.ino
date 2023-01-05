#include "Motor.hpp"
#include "UltrasonicSensor.hpp"
#include "Data.hpp"

STATE state = STATE::NORMAL; // 前方車までの距離の状態
TARGET target = TARGET::AHEAD; // 前方車の方向
// 進行方向(前方車の方向)を決定
void decide_target();
// 前方車までの距離の状態を決定
void decide_state();
// 走行操作
void run();
// 前方へ走行
void ahead_run();
// 右方へ走行
void right_run();
// 左方へ走行
void left_run();
// 最も障害物までの距離が近いものを求める
uint16_t min_distance();

void setup() {
  constexpr uint8_t right_left_difference = 25;
  Serial.begin(9600);
  pin::Initialize(); // ピンのINPUT/OUTPUTを設定
  forward(150, 150); // 前進!前進!ZENSHIN!
  // do {
  //   // 見失った状態なら
  //   update_centimeter(); // 超音波センサで距離を計測する
  //   decide_state(); // 距離の状態を決定
  // } while (state != STATE::LOST);
}

void loop() {
  // 追従させるための関数
  update_centimeter(); // 超音波センサで距離を計測する
  decide_state(); // 距離の状態を決定
  decide_target(); // 方向の決定
  run(); // 走行

  // デバッグ用の関数
  // debug_distance();
  // SerialTarget();
  // SerialState();
  // delay(1000);
  // Serial.println("loop");
}

// 走行操作
void run() {
  switch (target) {
    case TARGET::AHEAD : ahead_run(); break;
    case TARGET::LEFT : left_run(); break;
    case TARGET::RIGHT : right_run(); break;
  }
}

// 前方へ走行
void ahead_run() {
  // constexpr uint8_t right_left_difference = 25;
  switch (state) {
    case STATE::DANGER : forward(10, 10); break;
    default : forward(200, 200); break;
  }
}
// 右方へ走行
void right_run() {
  // constexpr uint8_t right_left_difference = 50;
  switch (state) {
    case STATE::DANGER : forward(10, 0); break;
    default : forward(200, 10); break;
  }
}
// 左方へ走行
void left_run() {
  // constexpr uint8_t right_left_difference = 50;
  switch (state) {
    case STATE::DANGER : forward(0, 10); break;
    default : forward(10, 200); break;
  }
}

// // 進行方向(前方車の方向)を決定
// void decide_target() {
//   if (centimeter.center < distance::far &&
//       centimeter.right < distance::far &&
//       centimeter.left < distance::far) {
//     target = TARGET::AHEAD;
//   } else if (centimeter.right < distance::far) {
//     target = TARGET::RIGHT;
//   } else if (centimeter.left < distance::far) {
//     target = TARGET::LEFT;
//   } else if (centimeter.center < distance::far) {
//     target = TARGET::AHEAD;
//   }
// }

void decide_target() {
  uint16_t min_distance = distance::far;
  if (centimeter.center < min_distance) {
    target = TARGET::AHEAD;
    min_distance = centimeter.center;
  }
  if (centimeter.right < min_distance) {
    target = TARGET::RIGHT;
    min_distance = centimeter.right;
  }
  if (centimeter.left < min_distance) {
    target = TARGET::LEFT;
    min_distance = centimeter.left;
  }
}

// 前方車までの距離の状態を決定
void decide_state() {
  // 最も近いと判断した超音波センサを基準に状態を決定
  uint16_t min_dist = min_distance();
  if (min_dist < distance::danger) {
    state = STATE::DANGER;
  } else if (min_dist < distance::close) {
    state = STATE::CLOSE;
  } else if (min_dist < distance::normal) {
    state = STATE::NORMAL;
  } else if (min_dist < distance::far) {
    state = STATE::FAR;
  } else {
    state = STATE::LOST;
  }
}

uint16_t min_distance() {
  return min(centimeter.left, centimeter.center) < min(centimeter.right, distance::far) ? min(centimeter.left, centimeter.center) : min(centimeter.right, distance::far);
}

// デバッグ用の関数
void SerialState() {
  Serial.print("State : ");
  switch (state) {
    case STATE::DANGER : Serial.println("Danger"); break;
    case STATE::CLOSE : Serial.println("Close"); break;
    case STATE::NORMAL : Serial.println("Normal"); break;
    case STATE::FAR : Serial.println("Far"); break;
    case STATE::LOST :  Serial.println("Lost"); break;
  }
}

void SerialTarget() {
  Serial.print("Target : ");
  switch (target) {
    case TARGET::AHEAD : Serial.println("Ahead"); break; 
    case TARGET::RIGHT : Serial.println("Right"); break; 
    case TARGET::LEFT : Serial.println("Left"); break;
  }
}