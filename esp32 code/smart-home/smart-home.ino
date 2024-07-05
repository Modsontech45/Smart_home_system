#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "Heemis";
const char* password = "noMistake145";

// Create an instance of the server
WebServer server(80);

// Assign output variables to GPIO pins
const int output12 = 12;
const int output14 = 14;
const int output21 = 21;
const int output18 = 18;
const int output19 = 19;

// Current output states
String output12State = "off";
String output14State = "off";
String output21State = "off";
String output18State = "off";
String output19State = "off";

// Demo temperature and humidity values
float temperature = 25.0;
float humidity = 50.0;

void setup() {
  Serial.begin(115200);

  // Initialize the output variables as outputs
  pinMode(output12, OUTPUT);
  pinMode(output14, OUTPUT);
  pinMode(output21, OUTPUT);
  pinMode(output18, OUTPUT);
  pinMode(output19, OUTPUT);

  // Set outputs to LOW
  digitalWrite(output12, LOW);
  digitalWrite(output14, LOW);
  digitalWrite(output21, LOW);
  digitalWrite(output18, LOW);
  digitalWrite(output19, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
  }

  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Define HTTP routes
  server.on("/gpio/12/on", []() {
    output12State = "on";
    digitalWrite(output12, HIGH);
    sendCORSResponse(output12State);
  });

  server.on("/gpio/12/off", []() {
    output12State = "off";
    digitalWrite(output12, LOW);
    sendCORSResponse(output12State);
  });

  server.on("/gpio/14/on", []() {
    output14State = "on";
    digitalWrite(output14, HIGH);
    sendCORSResponse(output14State);
  });

  server.on("/gpio/14/off", []() {
    output14State = "off";
    digitalWrite(output14, LOW);
    sendCORSResponse(output14State);
  });

  server.on("/gpio/21/on", []() {
    output21State = "on";
    digitalWrite(output21, HIGH);
    sendCORSResponse(output21State);
  });

  server.on("/gpio/21/off", []() {
    output21State = "off";
    digitalWrite(output21, LOW);
    sendCORSResponse(output21State);
  });

  server.on("/gpio/18/on", []() {
    output18State = "on";
    digitalWrite(output18, HIGH);
    sendCORSResponse(output18State);
  });

  server.on("/gpio/18/off", []() {
    output18State = "off";
    digitalWrite(output18, LOW);
    sendCORSResponse(output18State);
  });

  server.on("/gpio/19/on", []() {
    output19State = "on";
    digitalWrite(output19, HIGH);
    sendCORSResponse(output19State);
  });

  server.on("/gpio/19/off", []() {
    output19State = "off";
    digitalWrite(output19, LOW);
    sendCORSResponse(output19State);
  });

  server.on("/status", []() {
    DynamicJsonDocument doc(1024);
    doc["output12"] = output12State;
    doc["output14"] = output14State;
    doc["output21"] = output21State;
    doc["output18"] = output18State;
    doc["output19"] = output19State;
    doc["temperature"] = temperature;
    doc["humidity"] = humidity;
    String json;
    serializeJson(doc, json);

    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, "application/json", json);
  });

  // Handle CORS preflight request
  server.on("/status", HTTP_OPTIONS, []() {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
    server.send(204);
  });

  // Start server
  server.begin();
}

void loop() {
  server.handleClient();
}

void sendCORSResponse(String response) {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", response);
}
