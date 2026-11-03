
const int MQ2_PIN = 27;
const int FLAME_AO = 34;
const int BUZZER_PIN = 14;

const int LIGHT_RELAY = 26;
const int FAN_RELAY = 25;

// Relay module is active LOW
const int RELAY_ON = LOW;
const int RELAY_OFF = HIGH;

// Sensor settings
const int SMOKE_LEVEL = LOW;
const int FIRE_THRESHOLD = 500;

bool previousDanger = false;

void setup() {
  Serial.begin(115200);

  pinMode(MQ2_PIN, INPUT);
  pinMode(FLAME_AO, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(LIGHT_RELAY, OUTPUT);
  pinMode(FAN_RELAY, OUTPUT);

  // Initially keep relays OFF
  digitalWrite(LIGHT_RELAY, RELAY_OFF);
  digitalWrite(FAN_RELAY, RELAY_OFF);

  noTone(BUZZER_PIN);

  Serial.println("================================");
  Serial.println(" HOMIQ SMART HOME SAFETY SYSTEM ");
  Serial.println("================================");
  Serial.println("System Started");
}

void loop() {

  // Read sensors
  int smokeValue = digitalRead(MQ2_PIN);
  int fireValue = analogRead(FLAME_AO);

  // Detect smoke and fire
  bool smokeDetected = (smokeValue == SMOKE_LEVEL);
  bool fireDetected = (fireValue < FIRE_THRESHOLD);

  bool danger = smokeDetected || fireDetected;

  // Display sensor readings
  Serial.println("--------------------------------");
  Serial.print("MQ2 Digital Value: ");
  Serial.println(smokeValue);

  Serial.print("Flame Analog Value: ");
  Serial.println(fireValue);

  if (danger) {

    // Turn OFF appliances during danger
    digitalWrite(LIGHT_RELAY, RELAY_OFF);
    digitalWrite(FAN_RELAY, RELAY_OFF);

    // Activate buzzer
    tone(BUZZER_PIN, 2000);

    if (smokeDetected && fireDetected) {
      Serial.println("ALERT: SMOKE AND FIRE DETECTED!");
    }
    else if (smokeDetected) {
      Serial.println("ALERT: SMOKE DETECTED!");
    }
    else if (fireDetected) {
      Serial.println("ALERT: FIRE DETECTED!");
    }

  } 
  else {

    // Safe condition
    noTone(BUZZER_PIN);

    digitalWrite(LIGHT_RELAY, RELAY_ON);
    digitalWrite(FAN_RELAY, RELAY_ON);

    Serial.println("STATUS: NORMAL - SAFE");
  }

  // Print danger status only when it changes
  if (danger != previousDanger) {

    if (danger) {
      Serial.println("DANGER STARTED!");
    } 
    else {
      Serial.println("DANGER CLEARED!");
    }

    previousDanger = danger;
  }

  delay(500);
}
