# ds3231_with_datetime_formatted
Works with the DS3231 module, using 'strftime' to format the date and time.

 - This project inherits from "RTClib.h", so we can create a datetime output formatted with "strftime".
 - "strftime" lets you create a formatted datetime character array using a combination of regular characters and conversion specifiers.
 - For this, instead of the function returning an array of characters, it formats the array that we passed as a pointer.
 - For more details about the conversion specifiers and "strftime" go to https://cplusplus.com/reference/ctime/strftime/.
