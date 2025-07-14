# Project Overview: 
RexP1 Droid with Wheel-Specific RP2040 PCBs —an imaginative reinterpretation of an astro droid—combines modular wheel control with microROS-powered motor coordination. Using RP2040 Zero boards positioned close to each wheel, the design dramatically reduces wiring complexity and enables each module to relay precise rotational data and drive control back to a central Raspberry Pi 5.

# Core Architecture
MicroROS Integration: Each RP2040 runs microROS for real-time motor control and feedback.

Modular Boards: Custom 43×43 mm PCBs (fabricated by PCBWay) for each wheel contain sensors, controllers, and communication interfaces.

## Motor System:

Geared 37D motors with 131:1 ratio deliver 83 RPM at 12V, ideal for slow, deliberate movement (~0.6 m/s).

Encoders with hall-effect sensors provide 2096 ticks per rotation, enabling detailed speed and position tracking.

L298N motor drivers selected for familiarity and consistency across droid designs.

##️ Peripheral & Expansion Capabilities

### Sensor Suite:

Ultrasonic Sensors (HC-SR04): Mounted around rear wheels to mitigate lidar blind spots, particularly in reflective or low-contrast environments.

WS2812B LED Strips: Planned for visual effects and thematic flair, likely mounted vertically alongside the wheels.

I²C Connector: Included for future sensor or device expansions.

Lighting Control: Separate motor controller channels drive bright 12V headlights and taillights for enhanced immersion and potential navigation utility.

Level Shifters: Used to manage 5V logic levels from ultrasonic sensors and WS2812B LEDs.

#️ Board Design Insights
Created in KiCad using modular schematic sections connected via net labels—allowing flexible GPIO reassignment and efficient trace routing.

Consistent mechanical layout across all boards for streamlined mechanical integration and enclosure design.

# Software Strategy
PWM Motor Control: Managed locally on RP2040; algorithms fine-tuned to reflect encoder feedback.

ROS2 Communication: Central Raspberry Pi 5 handles high-level control via twist messages, converting them to joint jog/state ROS messages.

Motion Testing: Remote control mode currently in use to validate board responsiveness and individual wheel behavior.