#include "epl.h"
#include "esphome/core/log.h"

namespace esphome {
namespace epl {
static const char *const TAG = "epl";

void EPLComponent:setup() {
  ESP_LOGCONFIG(TAG, "Setting up EPL Sensor...");
}

void EPLComponent:loop() {
  ESP_LOGD(TAG, "Looping EPL Sensor...");
  
}

}
}