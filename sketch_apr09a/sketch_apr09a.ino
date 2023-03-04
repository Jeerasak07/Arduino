#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "NMDfKgoYY4JqjCFkvl35wbx9eLZfUZer";
char ssid[] = "@Porntip AB1_2.4G";    //char ssid[] = "POCO X3 Pro";
char pass[] = "M0868524422";    //char pass[] = "1122334455";

int SensorPin = A0;   //พื้นที่ใช้รับค่า A0
int Sensor = 0;    //ตัวแปรของความชื้นในดิน เริ่มต้นที่ 0

void setup() 
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() 
{
  Blynk.run();
  
  Sensor = analogRead(SensorPin);
  Sensor = map(Sensor, 0, 1023, 0, 1023);

  Blynk.virtualWrite(V1, Sensor);    //โค้ดส่งค่าขึ้นแสดงบนแอป Blynk

  Serial.print("Moisture of Soil: ");   //ตั้งชื่อคำนำหน้า
  Serial.println(Sensor);    //เรียกดูค่า Sensor ใน Serial ว่ามีค่าเท่าไหร่
}
