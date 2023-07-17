#include "RTC.h"

/* constructor */
RTC::RTC() : RTC_DS3231() {}

/* start module (similar to 'begin') */
void RTC::init() {
  // the implementation of this block was taken from the example of "RTClib.h"
  // start the module and check
  if (!this->begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (this->lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    this->adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // this->adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // this->adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

/* sets dateTimeNow */
void RTC::setDateTimeNow() {
  this->dateTimeNow = this->now();
}

/* gets dateTimeNow */
DateTime RTC::getDateTimeNow() {
  this->setDateTimeNow();
  return this->dateTimeNow;
}

/* sets formatted string to a pointer */
void RTC::strFormattedDateTime(char* ptr, size_t maxSize, const char* format) {
  time_t t;
  struct tm *lt;

  t = this->getDateTimeNow().unixtime();
  lt = localtime(&t);

  strftime(ptr, maxSize, format, lt);
}




