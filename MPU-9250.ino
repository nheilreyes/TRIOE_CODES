#include <Wire.h>
#include <MPU9250_WE.h>  // Library for MPU9250

#define MPU_ADDR 0x68  // Change to 0x69 if needed

MPU9250_WE myMPU9250 = MPU9250_WE(MPU_ADDR);

void setup() {
    Serial.begin(115200);
    Wire.begin(4, 5);  // SDA=21, SCL=22 (ESP32)

    if (!myMPU9250.init()) {  
        Serial.println("MPU9250 not detected!");
        while (1);
    }
    Serial.println("MPU9250 Connected!");

    myMPU9250.setAccRange(MPU9250_ACC_RANGE_8G);
    myMPU9250.setGyrRange(MPU9250_GYRO_RANGE_500);
    myMPU9250.enableGyrDLPF();
    myMPU9250.setGyrDLPF(MPU9250_DLPF_5);

    // Initialize Magnetometer
    if (!myMPU9250.initMagnetometer()) {
        Serial.println("Magnetometer not detected!");
        while (1);
    }
    Serial.println("Magnetometer Initialized!");
}

void loop() {
    xyzFloat acc = myMPU9250.getGValues();
    xyzFloat gyr = myMPU9250.getGyrValues();
    xyzFloat mag = myMPU9250.getMagValues();
    float temp = myMPU9250.getTemperature();

    Serial.print("Acc X: "); Serial.print(acc.x);
    Serial.print(" | Y: "); Serial.print(acc.y);
    Serial.print(" | Z: "); Serial.println(acc.z);

    Serial.print("Gyr X: "); Serial.print(gyr.x);
    Serial.print(" | Y: "); Serial.print(gyr.y);
    Serial.print(" | Z: "); Serial.println(gyr.z);

    Serial.print("Mag X: "); Serial.print(mag.x);
    Serial.print(" | Y: "); Serial.print(mag.y);
    Serial.print(" | Z: "); Serial.println(mag.z);

    Serial.print("Temperature: "); Serial.print(temp); Serial.println(" °C");
    Serial.println("--------------------");

    delay(500);
}