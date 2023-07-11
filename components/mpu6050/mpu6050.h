#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include <Wire.h>
#include <Adafruit_MPU6050.h>


namespace esphome {
namespace mpu6050svr {

class MPU6050Component : public Component {
  public:
    void setup() override;
    void loop() override;
    void load_sensor_data();

    float get_setup_priority() const override;

    void set_accel_x_sensor(sensor::Sensor *accel_x_sensor) { accel_x_sensor_ = accel_x_sensor; }
    void set_accel_y_sensor(sensor::Sensor *accel_y_sensor) { accel_y_sensor_ = accel_y_sensor; }
    void set_accel_z_sensor(sensor::Sensor *accel_z_sensor) { accel_z_sensor_ = accel_z_sensor; }
    void set_temperature_sensor(sensor::Sensor *temperature_sensor) { temperature_sensor_ = temperature_sensor; }
    void set_gyro_x_sensor(sensor::Sensor *gyro_x_sensor) { gyro_x_sensor_ = gyro_x_sensor; }
    void set_gyro_y_sensor(sensor::Sensor *gyro_y_sensor) { gyro_y_sensor_ = gyro_y_sensor; }
    void set_gyro_z_sensor(sensor::Sensor *gyro_z_sensor) { gyro_z_sensor_ = gyro_z_sensor; }

  protected:
   sensor::Sensor *accel_x_sensor_{nullptr};
   sensor::Sensor *accel_y_sensor_{nullptr};
   sensor::Sensor *accel_z_sensor_{nullptr};
   sensor::Sensor *temperature_sensor_{nullptr};
   sensor::Sensor *gyro_x_sensor_{nullptr};
   sensor::Sensor *gyro_y_sensor_{nullptr};
   sensor::Sensor *gyro_z_sensor_{nullptr};
   Adafruit_MPU6050 mpu;
   uint32_t last_update;
};

}
}