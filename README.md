# esphome-components

A collection of custom ESP home components following the [External components](https://esphome.io/components/external_components.html) repository style.

## MPU6050

This MPU6050 component uses the build in motion detection instead off pulling. This makes the sensor a little bit less chatty, since it will only send data when it detects movement.

<details>
    <summary>ESPHome config</summary>

    ```yml
    external_components:
      # use all components from a local folder
      # - source:
      #     type: local
      #     path: my_components
      - source: github://svrooij/esphome-components@dev
        components: [ mpu6050 ]
    
    sensor:
      - platform: mpu6050
        accel_x:
          name: "MPU6050 Accel X"
          id: accel_x_int
          filters:
            - offset: 0.153
        accel_y:
          name: "MPU6050 Accel Y"
          id: accel_y_int
          # filters:
          #   - offset: -2.68
        accel_z:
          name: "MPU6050 Accel Z"
          id: accel_z_int
          filters:
            - offset: -9.989
        gyro_x:
          name: "MPU6050 Gyro X"
          filters:
            - throttle_average: 5s
        gyro_y:
          name: "MPU6050 Gyro Y"
          filters:
            - throttle_average: 5s
        gyro_z:
          name: "MPU6050 Gyro Z"
          filters:
            - throttle_average: 5s
        temperature:
          name: "MPU6050 Temperature"
          filters:
            - throttle_average: 5s
    ```

</details>

See [full example](./example_mpu6050.yml).
