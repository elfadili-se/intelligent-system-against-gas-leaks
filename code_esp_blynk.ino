#define BLYNK_TEMPLATE_ID "TMPL2_loV4fpZ"
#define BLYNK_TEMPLATE_NAME "MQ2 detection"
#define BLYNK_AUTH_TOKEN "zzhkhYsSEwlnyHbkEp7UXrR-C-Tf_EqR"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "INPT-Test";  // Type your WiFi name
char pass[] = "**********";   // Type your WiFi password

BlynkTimer timer;

int GasSensor = A0;

#define Green 12   // GPIO12
#define Red 13     // GPIO13
#define Buzzer 14  // GPIO14

int sensorThreshold = 200; // Adjust based on your environment
int disconnectThreshold = 5; // Define a low threshold for sensor disconnection

void sendSensor() {
  int gasValue = analogRead(GasSensor);
  Blynk.virtualWrite(V0, gasValue);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue < disconnectThreshold) {
    // Handle sensor disconnected case
    digitalWrite(Green, LOW);
    digitalWrite(Red, LOW);
    digitalWrite(Buzzer, LOW);
    Serial.println("Sensor Disconnected!");
  } else if (gasValue < sensorThreshold) {
    // Gas level is normal
    digitalWrite(Green, HIGH);
    digitalWrite(Red, LOW);
    digitalWrite(Buzzer, LOW);
    Serial.println("Gas Normal");
  } else {
    // Gas level is high
    digitalWrite(Green, LOW);
    digitalWrite(Red, HIGH);
    digitalWrite(Buzzer, HIGH);
    Blynk.logEvent("gas_alert", "Gas is High");
    Serial.println("Gas is High");
  }
}

void setup() {   
  Serial.begin(115200);

  pinMode(GasSensor, INPUT);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendSensor);

  Serial.println("Gas Level Monitoring Started");
}

void loop() {
  Blynk.run();
  timer.run();
}
