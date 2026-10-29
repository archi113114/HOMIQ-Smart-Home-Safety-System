#define BLYNK_TEMPLATE_ID "TMPL3AUwpG4Q_"
#define BLYNK_TEMPLATE_NAME "HOMIQ"
#define BLYNK_AUTH_TOKEN ""

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

int mq2 = 27;
int flame = 33;
int buzzer = 14;

int relay = 26;       // Light
int relay2 = 25;      // Fan

bool danger = false;

BlynkTimer timer;


// Light control from Blynk
BLYNK_WRITE(V0)
{
  int value = param.asInt();

  if (!danger)
  {
    digitalWrite(relay, value);
  }
}


// Fan control from Blynk
BLYNK_WRITE(V1)
{
  int value = param.asInt();

  if (!danger)
  {
    digitalWrite(relay2, value);
  }
}


// Check smoke and fire
void checkSafety()
{
  int smoke = digitalRead(mq2);
  int fire = digitalRead(flame);

  bool currentDanger = (smoke == LOW || fire == LOW);

  // Danger detected
  if (currentDanger)
  {
    // Send notification ONLY when danger starts
    if (!danger)
    {
      Blynk.logEvent(
        "fire_smoke_alert",
        "Smoke or fire detected! Light and Fan have been turned OFF."
      );
    }

    danger = true;

    // Turn appliances OFF
    digitalWrite(relay, LOW);
    digitalWrite(relay2, LOW);

    // Buzzer ON
    tone(buzzer, 1000);

    // Safety status
    if (smoke == LOW && fire == LOW)
    {
      Serial.println("Smoke and Fire Detected");
      Blynk.virtualWrite(V2, "SMOKE AND FIRE DETECTED");
    }
    else if (smoke == LOW)
    {
      Serial.println("Smoke Detected");
      Blynk.virtualWrite(V2, "SMOKE DETECTED");
    }
    else
    {
      Serial.println("Fire Detected");
      Blynk.virtualWrite(V2, "FIRE DETECTED");
    }

    // Show OFF on Blynk switches
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V1, 0);
  }

  // Safe
  else
  {
    danger = false;

    // Current project behavior:
    // appliances automatically turn ON when danger clears
    digitalWrite(relay, HIGH);
    digitalWrite(relay2, HIGH);

    // Buzzer OFF
    noTone(buzzer);

    // Update Blynk
    Blynk.virtualWrite(V0, 1);
    Blynk.virtualWrite(V1, 1);
    Blynk.virtualWrite(V2, "SAFE");

    Serial.println("Normal - Safe");
  }
}


void setup()
{
  Serial.begin(115200);

  pinMode(mq2, INPUT);
  pinMode(flame, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);

  // Both appliances start ON
  digitalWrite(relay, HIGH);
  digitalWrite(relay2, HIGH);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Initial Blynk values
  Blynk.virtualWrite(V0, 1);
  Blynk.virtualWrite(V1, 1);
  Blynk.virtualWrite(V2, "SAFE");

  // Check safety every 500 ms
  timer.setInterval(500L, checkSafety);
}


void loop()
{
  Blynk.run();
  timer.run();
}