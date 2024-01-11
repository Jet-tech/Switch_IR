#define IR_SENSOR_1_PIN D2
#define IR_SENSOR_2_PIN D3
#define IR_SENSOR_3_PIN D1

#define RELAY_1_PIN D6
#define RELAY_2_PIN D7
#define RELAY_3_PIN D5

bool isObstacle1 = false;
bool isObstacle2 = false;
bool isObstacle3 = false;

void setup() {
  pinMode(IR_SENSOR_1_PIN, INPUT);
  pinMode(IR_SENSOR_2_PIN, INPUT);
  pinMode(IR_SENSOR_3_PIN, INPUT);

  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  pinMode(RELAY_3_PIN, OUTPUT);

  digitalWrite(RELAY_1_PIN, LOW);
  digitalWrite(RELAY_2_PIN, LOW);
  digitalWrite(RELAY_3_PIN, LOW);

  Serial.begin(115200);
}

void loop() {
  // Check IR sensor 1
  if (digitalRead(IR_SENSOR_1_PIN) == LOW) {
    // Obstacle detected, toggle relay 1
    isObstacle1 = !isObstacle1;
    digitalWrite(RELAY_1_PIN, isObstacle1 ? HIGH : LOW);
    Serial.println(isObstacle1 ? "Obstacle detected by IR sensor 1 - Relay 1 ON" : "No obstacle detected by IR sensor 1 - Relay 1 OFF");
    delay(500); // Add a delay to avoid multiple triggers
  }

  // Check IR sensor 2
  if (digitalRead(IR_SENSOR_2_PIN) == LOW) {
    // Obstacle detected, toggle relay 2
    isObstacle2 = !isObstacle2;
    digitalWrite(RELAY_2_PIN, isObstacle2 ? HIGH : LOW);
    Serial.println(isObstacle2 ? "Obstacle detected by IR sensor 2 - Relay 2 ON" : "No obstacle detected by IR sensor 2 - Relay 2 OFF");
    delay(500); // Add a delay to avoid multiple triggers
  }

  // Check IR sensor 3
  if (digitalRead(IR_SENSOR_3_PIN) == LOW) {
    // Obstacle detected, toggle relay 3
    isObstacle3 = !isObstacle3;
    digitalWrite(RELAY_3_PIN, isObstacle3 ? HIGH : LOW);
    Serial.println(isObstacle3 ? "Obstacle detected by IR sensor 3 - Relay 3 ON" : "No obstacle detected by IR sensor 3 - Relay 3 OFF");
    delay(500); // Add a delay to avoid multiple triggers
  }
}
