#pragma once

enum class TARGET {
  AHEAD, // 追従すべきものが前方にある
  RIGHT, // 追従すべきものが右側にある
  LEFT // 追従すべきものが左側にある
};

namespace speed {
  // スピードを定義
  // 上から順に速いスピードとなる
  constexpr uint8_t top = 180;
  constexpr uint8_t high = 120;
  constexpr uint8_t ahead_normal = 90;
  constexpr uint8_t ahead_low = 50;
  constexpr uint8_t normal = 80;
  constexpr uint8_t low = 50;
  constexpr uint8_t slow = 10;
}

enum class STATE {
  DANGER, // 衝突寸前
  CLOSE, // 間隔が近い状態
  NORMAL, // ほど良い間隔の状態
  FAR, // 間隔が広くなっている状態
  LOST // 前方に何も観測されていない状態
};

namespace distance {
  constexpr uint16_t danger = 6; // 衝突寸前
  constexpr uint16_t close = 10; // 間隔が近い状態
  constexpr uint16_t normal = 20; // ほど良い間隔の状態
  constexpr uint16_t far = 30; // 間隔が広くなっている状態
}