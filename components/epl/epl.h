#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/uart/uart.h"

namespace esphome {
namespace epl {

class EPLComponent : public Component, public uart::UARTDevice {
  public:
    void setup() override;
    void loop() override;

    void set_target1_x(sensor::Sensor *target1_x_sensor) { target1_x_sensor_ = target1_x_sensor; }
    void set_target1_y(sensor::Sensor *target1_y_sensor) { target1_y_sensor_ = target1_y_sensor; }
    void set_target1_speed(sensor::Sensor *target1_speed_sensor) { target1_speed_sensor_ = target1_speed_sensor; }
    void set_target1_angle(sensor::Sensor *target1_angle_sensor) { target1_angle_sensor_ = target1_angle_sensor; }
    void set_target1_distance(sensor::Sensor *target1_distance_sensor) { target1_distance_sensor_ = target1_distance_sensor; }
    void set_target1_resolution(sensor::Sensor *target1_resolution_sensor) { target1_resolution_sensor_ = target1_resolution_sensor; }

    void set_target2_x(sensor::Sensor *target2_x_sensor) { target2_x_sensor_ = target2_x_sensor; }
    void set_target2_y(sensor::Sensor *target2_y_sensor) { target2_y_sensor_ = target2_y_sensor; }
    void set_target2_speed(sensor::Sensor *target2_speed_sensor) { target2_speed_sensor_ = target2_speed_sensor; }
    void set_target2_angle(sensor::Sensor *target2_angle_sensor) { target2_angle_sensor_ = target2_angle_sensor; }
    void set_target2_distance(sensor::Sensor *target2_distance_sensor) { target2_distance_sensor_ = target2_distance_sensor; }
    void set_target2_resolution(sensor::Sensor *target2_resolution_sensor) { target2_resolution_sensor_ = target2_resolution_sensor; }
    
    void set_target3_x(sensor::Sensor *target3_x_sensor) { target3_x_sensor_ = target3_x_sensor; }
    void set_target3_y(sensor::Sensor *target3_y_sensor) { target3_y_sensor_ = target3_y_sensor; }
    void set_target3_speed(sensor::Sensor *target3_speed_sensor) { target3_speed_sensor_ = target3_speed_sensor; }
    void set_target3_angle(sensor::Sensor *target3_angle_sensor) { target3_angle_sensor_ = target3_angle_sensor; }
    void set_target3_distance(sensor::Sensor *target3_distance_sensor) { target3_distance_sensor_ = target3_distance_sensor; }
    void set_target3_resolution(sensor::Sensor *target3_resolution_sensor) { target3_resolution_sensor_ = target3_resolution_sensor; }
  
  protected:
    sensor::Sensor *target1_x_sensor_{nullptr};
    sensor::Sensor *target1_y_sensor_{nullptr};
    sensor::Sensor *target1_speed_sensor_{nullptr};
    sensor::Sensor *target1_angle_sensor_{nullptr};
    sensor::Sensor *target1_distance_sensor_{nullptr};
    sensor::Sensor *target1_resolution_sensor_{nullptr};

    sensor::Sensor *target2_x_sensor_{nullptr};
    sensor::Sensor *target2_y_sensor_{nullptr};
    sensor::Sensor *target2_speed_sensor_{nullptr};
    sensor::Sensor *target2_angle_sensor_{nullptr};
    sensor::Sensor *target2_distance_sensor_{nullptr};
    sensor::Sensor *target2_resolution_sensor_{nullptr};

    sensor::Sensor *target3_x_sensor_{nullptr};
    sensor::Sensor *target3_y_sensor_{nullptr};
    sensor::Sensor *target3_speed_sensor_{nullptr};
    sensor::Sensor *target3_angle_sensor_{nullptr};
    sensor::Sensor *target3_distance_sensor_{nullptr};
    sensor::Sensor *target3_resolution_sensor_{nullptr};
}


}
}