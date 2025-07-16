#include <WiFi.h>
#include <PubSubClient.h>

// Wi-Fi Credentials
const char* ssid = "wifi_name";
const char* password = "password";

// MQTT Broker settings
const char *mqtt_broker = "broker.emqx.io";  // EMQX broker endpoint
const char *mqtt_topic = "emqx/esp8266";     // MQTT topic
const char *mqtt_username = "emqx";  // MQTT username for authentication
const char *mqtt_password = "public";  // MQTT password for authentication
const int mqtt_port = 1883;  // MQTT port (TCP)

// Define GPIO Pins
const int soundSensorPin = 34;  // Potentiometer simulating sound
const int ledPin = 2;           // LED indicator

WiFiClient espClient;
PubSubClient client(espClient);

// Threshold for Cry Detection
const int cryThreshold = 2000;  // Adjust based on testing

void setup() {
    Serial.begin(115200);
    
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    // Connect to Wi-Fi
    Serial.print("Connecting to Wi-Fi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWi-Fi Connected!");

    // Connect to MQTT Broker
    client.setServer(mqtt_broker, mqtt_port);
    while (!client.connected()) {
        Serial.print("Connecting to MQTT...");
        if (client.connect("ESP32Client")) {
            Serial.println("\nConnected to MQTT!");
        } else {
            Serial.print("Failed. Error Code: ");
            Serial.print(client.state());
            delay(2000);
        }
    }
}

void loop() {
    int soundLevel = analogRead(soundSensorPin);  // Read simulated sound level
    Serial.print("Sound Level: ");
    Serial.println(soundLevel);

    if (soundLevel > cryThreshold) {
        digitalWrite(ledPin, HIGH);  // Turn LED ON
        client.publish(mqtt_topic, "Baby Crying!"); // Send MQTT alert
        Serial.println("ALERT SENT: Baby Crying!");
    } else {
        digitalWrite(ledPin, LOW);  // Turn LED OFF
    }

    delay(500);  // Delay before next reading
}
