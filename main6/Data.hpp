#pragma once
constexpr uint8_t accum_num = 5;

// 検出した距離を記録
volatile typedef struct {
  uint16_t right;
  uint16_t center;
  uint16_t left;
} DetectedDistance;

// データを読み取って平均を返すことのできる構造体
// 呼び出して良いのはget,update,average関数のみ
typedef struct {
  uint8_t head=0, tail=0;
  uint16_t Q[accum_num] = {0};
  // ゲッター
  uint16_t get(const uint8_t idx) const { return Q[idx]; }
  // データをアップデート
  inline void update(const uint16_t a);
  // 今貯めている平均を返す
  uint16_t average();
} Queue;

Queue right_sensor; // 右側のセンサからのデータのキュー
Queue center_sensor; // 中央のセンサからのデータのキュー
Queue left_sensor;  // 左側のセンサからのデータのキュー
DetectedDistance centimeter = {0};
uint8_t ir_data = HIGH; // 赤外線センサから読み取った値