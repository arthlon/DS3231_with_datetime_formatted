#include "RTC.h"

RTC rtc;

// variable declaration
char dateNow[20];
char timeNow[20];
char dateTimeNow[44];

void setup() {
  // initialize the serial monitor
  Serial.begin(115200);

  // initialize DS3231
  rtc.init();
}

void loop() {
  // formats character arrays as specified
  rtc.strFormattedDateTime(dateNow, sizeof dateNow, "Date: %m.%d.%Y");
  rtc.strFormattedDateTime(timeNow, sizeof timeNow, "Time: %I:%M:%S %p");
  rtc.strFormattedDateTime(dateTimeNow, sizeof dateTimeNow, "Date/Time: %A, %B %d, %Y %I:%M %p");

  // print formatted character arrays
  Serial.println(dateNow);
  Serial.println(timeNow);
  Serial.println(dateTimeNow);

  Serial.println();

  delay(3000);
}




