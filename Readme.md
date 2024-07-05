# WiFi GPIO Control with Web Server

This project is an Arduino-based web server application that allows you to control GPIO pins on an ESP32 via a web interface. The project also provides a simple RESTful API to get the status of the GPIO pins and some demo sensor values.

## Hardware Requirements

- ESP32 Development Board
- Wi-Fi Network
- LEDs or other output devices connected to the following GPIO pins: 12, 14, 21, 18, 19

## Software Requirements

- Arduino IDE
- ESP32 Board Package for Arduino
- ArduinoJson Library
- WiFi Library
- WebServer Library

## Getting Started

### Installation

1. **Set up the Arduino IDE**:
   - Install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Add the ESP32 board package to the Arduino IDE. Follow [these instructions](https://github.com/espressif/arduino-esp32).

2. **Install required libraries**:
   - Install the `ArduinoJson` library. Go to `Sketch -> Include Library -> Manage Libraries` and search for `ArduinoJson`.
   - The `WiFi` and `WebServer` libraries are included in the ESP32 board package.

### Hardware Setup

- Connect LEDs or other output devices to the following GPIO pins on the ESP32:
  - GPIO 12
  - GPIO 14
  - GPIO 21
  - GPIO 18
  - GPIO 19

### Code

1. **Network Credentials**: Replace `ssid` and `password` with your Wi-Fi network's SSID and password.

```cpp
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";


///////////////////////////////////////////////////////////////////////////
# SOFT LIFE Web Interface

This HTML document provides a user interface for controlling and monitoring various aspects of a smart home system using an ESP32 microcontroller. The interface includes controls for lights and displays for temperature and humidity, along with real-time updates using AJAX.

## Features

- **Sidebar**: Navigation for Control Panel and Settings.
- **Control Panel**: Toggle switches for controlling different lights in the house.
- **Status Display**: Real-time status display for ESP32 connection and sensor data.
- **Charts and Gauges**: Visual representation of humidity and temperature using Chart.js and custom gauges.

## Prerequisites

- ESP32 microcontroller with web server setup.
- Wi-Fi network.
- HTML, CSS, and JavaScript knowledge.

## File Structure

- `index.html`: Main HTML file.
- `style.css`: CSS file for styling the interface.
- `script.js`: JavaScript file for handling AJAX requests and updates.

## Usage

1. **ESP32 Setup**:
   - Ensure your ESP32 is running a web server that handles GPIO controls and status requests.
   - The ESP32 should be connected to the same Wi-Fi network as the device accessing this web interface.

2. **HTML Structure**:
   - The HTML file contains the structure for the sidebar, control panel, status display, and chart containers.

3. **JavaScript Functions**:
   - **controlLED(pin, state)**: Sends a request to the ESP32 to control a specific GPIO pin.
   - **getStatus()**: Fetches the current status from the ESP32 and updates the interface.
   - **updateGauges()**: Randomly updates the gauges and charts for demonstration purposes.
   - **drawGauge(element, value, unit)**: Draws a custom gauge SVG.
   - **updateChart(chart, data, value)**: Updates the chart data.

4. **Libraries Used**:
   - [Chart.js](https://www.chartjs.org/): For creating charts.
   - [Chart.js Gauge Plugin](https://github.com/needle-tools/chartjs-plugin-gauge): For creating gauge charts.
   - [Font Awesome](https://fontawesome.com/): For icons.
   - [Google Fonts](https://fonts.google.com/): For custom fonts.

## Example HTML

```html
<!DOCTYPE html>
<html>
<head>
  <title>SOFT LIFE</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="style.css">
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  <script src="https://kit.fontawesome.com/2bd249f159.js" crossorigin="anonymous"></script>
  <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Audiowide">
</head>
<body>
  <!-- HTML structure as described in the File Structure section -->
  <!-- ... -->
  <script src="script.js"></script>
</body>
</html>

