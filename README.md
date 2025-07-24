#Autonomous Rover for Weed Detection

An ESP32-powered rover system designed for precision agriculture. Real-time orientation, manual control, and visual feedback combine with modular, reusable components to create a robust platform for detection and navigation.

##Features

- **ESP-NOW Wireless Link**\
  Low-latency, peer-to-peer communication between a handheld transmitter and the rover—no router needed.
- **3-Axis IMU Feedback**\
  MPU9250 provides stable yaw, pitch, and roll measurements, streamed continuously to the rover and optionally displayed on an OLED.
- **Dual-Joystick & Button Controls**\
  Manual override or fine-tuning via two analog joysticks and push-buttons.
- **FastLED Animations**\
  64-LED addressable strip for colorful status indicators and debugging patterns.
- **OLED Status Display**\
  SSD1306 shows real-time IMU data or incoming command feedback for immediate operator awareness.
- **4-Motor Drive with Encoders**\
  H-bridge control for four DC motors, each with quadrature encoder feedback for precise motion control.
- **Battery Management**\
  Li-ion voltage sampling averaged over multiple readings for accurate battery-percentage reporting and failsafe triggers.
- **Modular C++ Headers**\
  Reusable components (IMUData.h, ButtonData.h, flashLED.h, motor.h, batteryManagement.h, OLEDdisplay.h, wifi\_TX.h, wifi\_RX.h) decouple functionality for easy customization and maintenance.

![Remote](docs/Remote.jpg)
![Rover](docs/Rover.jpg)

##Getting Started

1. **Clone the Code**

   git clone https://github.com/raviteja091/Autonomous-Rover-for-Weed-Detection.git/
   cd autonomous-rover-weed-detection

1. **Open & Upload Transmitter**
   1. Launch transmitter/transmitter.ino in the Arduino IDE.
   1. Install these libraries via Library Manager if missing:
      1. FastLED
      1. Adafruit\_SSD1306 & Adafruit\_GFX
      1. MPU9250
   1. Select your ESP32 board and upload.
1. **Open & Upload Receiver**
   1. Launch receiver/receiver.ino.
   1. Verify motor-control pin definitions in motor.h.
   1. Compile and upload to the rover’s ESP32.
1. **Power & Connect**
   1. Transmitter: USB power.
   1. Rover: Li-ion battery pack wired through the battery-management circuit.
1. **Monitor & Operate**
   1. Open Serial Monitor (115200 baud) on both boards.
   1. On the transmitter, press joysticks or buttons and watch the rover’s OLED update with orientation or incoming signals.
   1. Use transmitter Serial commands:
      1. o → show outgoing IMU/button data
      1. i → show incoming rover data
      1. s → silence both displays

##Usage Tips

- **LED Patterns**: Call flashLED\_run() opportunistically for visual status; comment out in final run for performance.
- **Battery Reads**: Use BatteryMeasure() frequently to avoid unexpected shutdown.
- **Encoder Calibration**: Tune delays in motor.h (e.g., moveForward() delay) for precise travel distances.
- **IMU Stability**: Ensure 25 ms update interval in updateMPUValues() to balance freshness and noise reduction.

**License**

This project is released under the **MIT License**.\
© 2025 RaviTeja.
