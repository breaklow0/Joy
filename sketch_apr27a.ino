#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 8    

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
// #define DHTTYPE    DHT21     // DHT 21 (AM2301)
DHT_Unified dht(DHTPIN, DHTTYPE);
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
    sensor_t sensor;
    dht.temperature().getSensor(&sensor);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.0133/2;

    sensors_event_t event;
  dht.temperature().getEvent(&event);

  lcd.setCursor(0, 0);
  lcd.print("Activity #7");
  lcd.setCursor(0, 1);
  lcd.print("Interfacing LCD ");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("DHT sensor");
  lcd.setCursor(0, 1);
  lcd.print("Temperature = ");
  lcd.print(event.temperature);
  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("UltrasonicSensor");
  lcd.setCursor(0, 1);
  lcd.print("Distance = ");
  lcd.print(distance);
  delay(3000);
  lcd.clear();

}
