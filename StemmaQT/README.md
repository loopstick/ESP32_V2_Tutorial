### Hands-on ESP32v2 Stemma QT Tutorial for MDes Prototyping

**This tutorial created by Sudhu Tewari 2026**

#### Tutorial overview
The tutorial will focus on using [Stemma QT](https://learn.adafruit.com/introducing-adafruit-stemma-qt/what-is-stemma) sensor and output modules with your [Adafruit ESP32 Feather v2](https://www.adafruit.com/product/5400) and the Arduino IDE.

Stemma QT connectors allow us to quickly connect different modules without having to worry about wiring electrical circuits correctly or having to solder! Stemma QT modules use the I2C communication protocol but allow us to get systems working without knowing exactly how I2C works.

more info:
- Adafruit [Working with I2C devices](https://learn.adafruit.com/working-with-i2c-devices/overview)
- Sparkfun [I2C](https://learn.sparkfun.com/tutorials/i2c/all)


Where is the Stemma QT connector?
![Stemma QT connector](/images/ESP32V2_StemmaQT.jpg)

What do we use to connect Stemma QT modules?
<!--![Stemma QT cable](https://cdn-shop.adafruit.com/970x728/4399-00.jpg) -->
<img src="https://cdn-shop.adafruit.com/970x728/4399-00.jpg" width="800">


### Stemma QT modules

#### Adafruit LSM9DS1 Accelerometer + Gyro + Magnetometer 9-DOF Breakout - [tutorial](https://learn.adafruit.com/adafruit-lsm9ds1-accelerometer-plus-gyro-plus-magnetometer-9-dof-breakout)
- accelerometer which can tell you which direction is down towards the Earth (by measuring gravity) or how fast the board is accelerating in 3D space
- gyroscope that can measure spin and twist
- magenetometer that can sense where the strongest magnetic force is coming from, generally used to detect magnetic north
- all in one tiny module!!!

<!--![LSM9DS1](/StemmaQT/images/LSM9DS1.jpg) -->
<img src="/StemmaQT/images/LSM9DS1.jpg" width="600">
<!-- ![LSM9DS1](https://cdn-learn.adafruit.com/assets/assets/000/092/391/large1024/sensors_qt_short_P4636Front.jpg?1592501321) -->

#### Adafruit DRV2605L Haptic Controller Breakout (+ vibration motor already soldered in place (thanks Romy!)) - [tutorial](https://learn.adafruit.com/adafruit-drv2605-haptic-controller-breakout/)
- allows us to control a tiny vibration motor with our ESP32v2
- the breakout/driver and the associated library handle the electrical specifics of making the motor move in a variety of ways

<img src="/StemmaQT/images/HapticMotorDriver.jpg" width="600">

With these two modules we can make a Human Augmentation system that senses movement (or direction) and outputs vibration (tactile feedback).

Before we get into designing (and implementing) our super cool system, let's first make sure we can get the individual components working.
- always RTFM! Read about the device, preferably in the manufacturer's documentation
- we like using Adafruit products because they have GREAT tutorials!!
  - [DRV2605L Haptic Controller Breakout](https://learn.adafruit.com/adafruit-drv2605-haptic-controller-breakout/) tutorial
  - [LSM9DS1 Accelerometer + Gyro + Magnetometer 9-DOF Breakout](https://learn.adafruit.com/adafruit-lsm9ds1-accelerometer-plus-gyro-plus-magnetometer-9-dof-breakout) tutorial
- Once you have some information about the device, plug it in and test it
  - run the most basic example code to test


Step-by-Step for Any/Every Sensor/Actuator
- RTFM
- install Library
  - _Tools -> Manage Libraries_
  - _Sketch -> Include Library -> Manage Libraries_
      - search for library name
      - install latest version
- upload and run library example code
  - _Examples -> *library -> *example_





*=*=*=*==*=*=*=*=*===*=*=*=*=*=*=*=*=*=*=*=*==*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
