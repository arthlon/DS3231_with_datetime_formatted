/*
  This project inherits from "RTClib.h", so we can create a datetime output formatted with "strftime".
  "strftime" lets you create a formatted datetime character array using a combination of regular characters and conversion specifiers.
  For this, instead of the function returning an array of characters, it formats the array that we passed as a pointer.
  For more details about the conversion specifiers and "strftime" go to https://cplusplus.com/reference/ctime/strftime/.
*/

#ifndef RTC_H
#define RTC_H

#include "RTClib.h"
#include <ctime>

class RTC : public RTC_DS3231 {
  private:
    // stores datetime value now
    DateTime dateTimeNow;
    // sets dateTimeNow
    void setDateTimeNow();

  public:
    // constructor
    RTC();

    // start module (similar to 'begin')
    void init();

    // gets dateTimeNow
    DateTime getDateTimeNow();

    // sets formatted string to a pointer
    void strFormattedDateTime(char* ptr, size_t maxSize, const char* format);
};

#endif




