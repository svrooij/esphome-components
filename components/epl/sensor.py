import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart, sensor
from esphome.const import (
    CONF_ID,
    STATE_CLASS_MEASUREMENT,
    UNIT_METER_PER_SECOND_SQUARED,
    UNIT_DEGREES,
)

DEPENDENCIES = ["uart"]

CONF_TARGET1_X = "target1_x"
CONF_TARGET1_Y = "target1_y"
CONF_TARGET1_SPEED = "target1_speed"
CONF_TARGET1_ANGLE = "target1_angle"
CONF_TARGET1_DISTANCE = "target1_distance"
CONF_TARGET1_RESOLUTION = "target1_resolution"

CONF_TARGET2_X = "target2_x"
CONF_TARGET2_Y = "target2_y"
CONF_TARGET2_SPEED = "target2_speed"
CONF_TARGET2_ANGLE = "target2_angle"
CONF_TARGET2_DISTANCE = "target2_distance"
CONF_TARGET2_RESOLUTION = "target2_resolution"

CONF_TARGET3_X = "target3_x"
CONF_TARGET3_Y = "target3_y"
CONF_TARGET3_SPEED = "target3_speed"
CONF_TARGET3_ANGLE = "target3_angle"
CONF_TARGET3_DISTANCE = "target3_distance"
CONF_TARGET3_RESOLUTION = "target3_resolution"

UNIT_MILLIMETER = "mm"

epl_ns = cg.esphome_ns.namespace("epl")
EPLComponent = epl_ns.class_(
    "EPLComponent", cg.Component, uart.UARTDevice
)

target_distance_schema = sensor.sensor_schema(
  unit_of_measurement=UNIT_MILLIMETER,
  accuracy_decimals=0,
  state_class=STATE_CLASS_MEASUREMENT,
)

target_speed_schema = sensor.sensor_schema(
  unit_of_measurement=UNIT_METER_PER_SECOND_SQUARED,
  accuracy_decimals=0,
  state_class=STATE_CLASS_MEASUREMENT,
)

target_angle_schema = sensor.sensor_schema(
  unit_of_measurement=UNIT_DEGREES,
  accuracy_decimals=0,
  state_class=STATE_CLASS_MEASUREMENT,
)

CONFIG_SCHEMA = cv.Schema(
    {
      cv.GenerateID(): cv.declare_id(EPLComponent),
      cv.Optional(CONF_TARGET1_X): target_distance_schema,
      cv.Optional(CONF_TARGET1_Y): target_distance_schema,
      cv.Optional(CONF_TARGET1_SPEED): target_speed_schema,
      cv.Optional(CONF_TARGET1_ANGLE): target_angle_schema,
      cv.Optional(CONF_TARGET1_DISTANCE): target_distance_schema,
      cv.Optional(CONF_TARGET1_RESOLUTION): target_distance_schema,

      cv.Optional(CONF_TARGET2_X): target_distance_schema,
      cv.Optional(CONF_TARGET2_Y): target_distance_schema,
      cv.Optional(CONF_TARGET2_SPEED): target_speed_schema,
      cv.Optional(CONF_TARGET2_ANGLE): target_angle_schema,
      cv.Optional(CONF_TARGET2_DISTANCE): target_distance_schema,
      cv.Optional(CONF_TARGET2_RESOLUTION): target_distance_schema,

      cv.Optional(CONF_TARGET3_X): target_distance_schema,
      cv.Optional(CONF_TARGET3_Y): target_distance_schema,
      cv.Optional(CONF_TARGET3_SPEED): target_speed_schema,
      cv.Optional(CONF_TARGET3_ANGLE): target_angle_schema,
      cv.Optional(CONF_TARGET3_DISTANCE): target_distance_schema,
      cv.Optional(CONF_TARGET3_RESOLUTION): target_distance_schema,

    }
  )


async def to_code(config):
  var = cg.new_Pvariable(config[CONF_ID])
  await cg.register_component(var, config)
  await uart.register_uart_device(var, config)

  for targetNumber in ["1", "2", "3"]:
    for sensorName in ["x", "y", "speed", "angle", "distance", "resolution"]:
      key = f"target{targetNumber}_{sensorName}"
      if key in config:
        sens = await sensor.new_sensor(config[key])
        cg.add(getattr(var, f"set_{key}")(sens))
