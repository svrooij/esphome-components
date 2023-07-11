#include "mpu6050.h"
#include "esphome/core/log.h"

namespace esphome {
namespace mpu6050svr {

static const char *const TAG = "mpu6050";

void MPU6050Component::setup() {
    ESP_LOGCONFIG(TAG, "Setting up MPU6050 Sensor...");
    this->mpu.begin();
    this->mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
    this->mpu.setMotionDetectionThreshold(1);
    this->mpu.setMotionDetectionDuration(1);
    // this->mpu.setInterruptPinLatch(true);	// Keep it latched.  Will turn off when reinitialized.
    // this->mpu.setInterruptPinPolarity(true);
    this->mpu.setMotionInterrupt(true);
    this->mpu.setAccelerometerRange(MPU6050_RANGE_2_G); // Default
    this->mpu.setGyroRange(MPU6050_RANGE_250_DEG); // Default
    this->load_sensor_data();
}

void MPU6050Component::loop() {
    if(this->mpu.getMotionInterruptStatus()) {
        this->load_sensor_data();
    } else if ((millis() - this->last_update) > 5000) {
        ESP_LOGD(TAG, "Emitting update because of no movement");

        this->load_sensor_data();
    }
}

void MPU6050Component::load_sensor_data() {
    sensors_event_t a, g, temp;
    this->mpu.getEvent(&a, &g, &temp);
    ESP_LOGD(TAG, "New reading: AccelX: %f AccelY: %f Accel Z: $f", a.acceleration.x, a.acceleration.y, a.acceleration.z);
    
    if (this->accel_x_sensor_ != nullptr) 
        this->accel_x_sensor_->publish_state(a.acceleration.x);

    if (this->accel_y_sensor_ != nullptr)
        this->accel_y_sensor_->publish_state(a.acceleration.y);
    
    if (this->accel_z_sensor_ != nullptr) 
        this->accel_z_sensor_->publish_state(a.acceleration.z);
    
    if (this->gyro_x_sensor_ != nullptr)
        this->gyro_x_sensor_->publish_state(g.gyro.x);
    
    if (this->gyro_y_sensor_ != nullptr)
        this->gyro_y_sensor_->publish_state(g.gyro.y);
    
    if (this->gyro_z_sensor_ != nullptr)
        this->gyro_z_sensor_->publish_state(g.gyro.z);

    if (this->temperature_sensor_ != nullptr)
        this->temperature_sensor_->publish_state(temp.temperature);

    this->last_update = millis();
}

float MPU6050Component::get_setup_priority() const { return setup_priority::DATA; }

} // namespace mpu6050svr
} // namespace esphome