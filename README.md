# FLUME
## Flow Universal Meter Engine

### Introduction
As part of an engaging project for my YouTube channel, I found myself in need of an efficient and reliable way to interface with a TTL 5V flow meter. However, I could not find a library that fully catered to my needs. That's when FLUME was born - an Arduino library specifically designed for interfacing with any TTL 5V flow meters.

FLUME provides a simple and consistent interface for measuring flow rate and volume. This ease of use doesn't compromise its capabilities, as it includes utilities for counting ticks, calculating flow rate, and managing calibration. Whether you're setting up a small home project or working on a complex automation system, FLUME is here to streamline your experience with flow meters.

Originally calibrated for the 932-9521-b90 model often found in home coffee machines, this library also includes a calibration program, making it adaptable to different flow meters.

### Examples
Two key examples are included with the library:
- **Calibration.ino**: This helps to calibrate the sensors. Although the library comes pre-adjusted for the 932-9521-b90 model, you can use this program to adjust the settings to any other flow meter of your choice.
- **Dosing.ino**: A control system for a DC pump using Pulse Width Modulation (PWM). This program is responsible for dispensing a specific amount of fluid while applying a filling curve to control the fluid's speed, ensuring precision and smooth operation. This example demonstrates a use case where you can leverage the power of FLUME to create a precise and reliable dosing system.

### Installation
FLUME can be easily installed through the Arduino IDE.
1. Download this repository as a ZIP file.
2. In the Arduino IDE, navigate to Sketch -> Include Library -> Add .ZIP Library.
3. At the top of your sketch, include the library using `#include <FLUME.h>`.

### License
FLUME is licensed under the [GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.html). This means you can freely use, modify and distribute the software, as long as you grant the same freedoms to others. For more details, please refer to the license file in this repository.
