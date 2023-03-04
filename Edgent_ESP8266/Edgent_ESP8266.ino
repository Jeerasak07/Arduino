
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL4_eR5uVt"
#define BLYNK_DEVICE_NAME "LED Blynk"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

int SensorPin = A0;   //พื้นที่ใช้รับค่า A0
int Sensor = 0;    //ตัวแปรของความชื้นในดิน เริ่มต้นที่ 0
int outval = 0;

BLYNK_WRITE(V0)
{
  int val = param.asInt();
  digitalWrite(D0, !val);
}

void setup()
{
  pinMode(D0, OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() 
{
  Blynk.run();
  
  Sensor = analogRead(SensorPin);
  outval = map(Sensor, 0, 1023, 0, 1023);
  delay(1000);

  Blynk.virtualWrite(V1, outval);    //โค้ดส่งค่าขึ้นแสดงบนแอป Blynk
  BlynkEdgent.run();
}
