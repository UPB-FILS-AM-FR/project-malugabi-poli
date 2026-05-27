#define BLYNK_TEMPLATE_ID "TMPL4UW-fB7QH"
#define BLYNK_TEMPLATE_NAME "smart house"
#define BLYNK_AUTH_TOKEN "hpyZkFi7Vq8GXzKW8kZCBxruxVyZfrOw"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

char ssid[] = "iPhone-gabi";
char pass[] = "numorcaiicandvorcainii";

LiquidCrystal_I2C lcd(0x27, 16, 2);

int flamePin = 4;
int gasPin = 5;
int waterPin = 34;

int ledPin = 2;
int buzzerPin = 18;

bool fireSent = false;
bool gasSent = false;
bool waterSent = false;

void setup() {

  Serial.begin(115200);

  Serial.println("================================");
  Serial.println("SMART HOUSE SYSTEM STARTING...");
  Serial.println("ESP32 INITIALIZATION...");
  Serial.println("================================");

  pinMode(flamePin, INPUT);
  pinMode(gasPin, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("SMART HOUSE");

  lcd.setCursor(0,1);
  lcd.print("CONNECTING");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("WIFI CONNECTED");
  Serial.println("BLYNK READY");
  Serial.println("SYSTEM READY");

  delay(2000);

  lcd.clear();
}

void loop() {

  Blynk.run();

  int flame = digitalRead(flamePin);
  int gas = digitalRead(gasPin);
  int water = analogRead(waterPin);

  Serial.print("Flame: ");
  Serial.print(flame);

  Serial.print(" | Gas: ");
  Serial.print(gas);

  Serial.print(" | Water: ");
  Serial.println(water);

  bool danger = false;

  // FIRE
  if(flame == 0) {

    danger = true;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FIRE ALERT");

    lcd.setCursor(0,1);
    lcd.print("CHECK HOUSE");

    Blynk.virtualWrite(V0, "FIRE");

    if(!fireSent) {

      Serial.println("FIRE DETECTED");

      Blynk.logEvent("fire_alert");

      fireSent = true;
    }

  } else {

    fireSent = false;
  }

  // GAS
  if(gas == 0) {

    danger = true;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("GAS ALERT");

    lcd.setCursor(0,1);
    lcd.print("CHECK HOUSE");

    Blynk.virtualWrite(V1, "GAS");

    if(!gasSent) {

      Serial.println("GAS DETECTED");

      Blynk.logEvent("gas_alert");

      gasSent = true;
    }

  } else {

    gasSent = false;
  }

  // WATER
  if(water > 1000) {

    danger = true;

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("WATER ALERT");

    lcd.setCursor(0,1);
    lcd.print("CHECK HOUSE");

    Blynk.virtualWrite(V2, "WATER");

    if(!waterSent) {

      Serial.println("WATER DETECTED");

      Blynk.logEvent("water_alert");

      waterSent = true;
    }

  } else {

    waterSent = false;
  }

  // SAFE
  if(danger) {

    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);

  } else {

    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("HOUSE SAFE");

    lcd.setCursor(0,1);
    lcd.print("ALL OK");
  }

  delay(500);
}
