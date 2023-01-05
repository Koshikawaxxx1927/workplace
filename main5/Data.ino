#include "Data.hpp"

// データをアップデート
inline void Queue::update(const uint16_t data){
  Q[tail] = data;
  tail = (tail + 1) % accum_num;
}

// 今貯めている平均を返す
uint16_t Queue::average() {
    uint16_t sum = 0;
    for (uint16_t i = 0; i < accum_num; ++i) {
        sum += Q[i];
    }
    return static_cast<uint16_t>(sum) / accum_num;
}