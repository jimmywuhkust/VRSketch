#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Servo.h>

Adafruit_MPU6050 mpu;
Servo servo1;
static const int servoPin = 13;
int servodegree = 0;
float prev_vol = 0;
float current_vol = 0;
float delta_vol = 0;

void setup(void) {
  Serial.begin(115200);
  servo1.attach(servoPin);
  while (!Serial)
    delay(10);  // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  //setupt motion detection
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true);  // Keep it latched.  Will turn off when reinitialized.
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);

  Serial.println("");
  delay(100);
}

void loop() {

    /* Get new sensor events with the readings */
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    /* Print out the values */
    Serial.print("AccelX:");
    Serial.print(a.acceleration.x);
    Serial.print(",");
    Serial.print("AccelY:");
    Serial.print(a.acceleration.y);
    Serial.print(",");
    Serial.print("AccelZ:");
    Serial.print(a.acceleration.z);
    current_vol = sqrt((sq(a.acceleration.x)) + sq(a.acceleration.y) + sq(a.acceleration.z));
    Serial.println();
    Serial.print("Combined Accel:");
    Serial.print(current_vol);
    delta_vol = abs(current_vol - prev_vol);
    Serial.println();
    Serial.print("Change in Accel:");
    Serial.print(delta_vol);
    Serial.println();
    servodegree = delta_vol * 20;
    servo1.write(servodegree+10);
    prev_vol = current_vol;


    delay(100);
}