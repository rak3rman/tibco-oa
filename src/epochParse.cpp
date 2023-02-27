/*
 * Epoch Parsing
 *
 * Radison Akerman, February 2023
 * TIBCO Coding Assessment
 */

#include "epochParse.h"
#include <time.h>

/*
 * getHMS()
 * Parses the hour, min, and sec of a given time in epoch format (UTC).
 * Does not account for inputs that are negative (before Jan 1st, 1970).
 *
 * @param {time_t} someTime - a time_t object containing a time epoch (secs)
 * @param {int*} hour - pointer to hour based on someTime
 * @param {int*} min - pointer to min based on someTime
 * @param {int*} sec - pointer to sec based on someTime
 */
void getHMS(time_t someTime, int *hour, int *min, int *sec) {
  // 1. Extract seconds from someTime, prep for min
  // epoch = 3601 => 1, epoch = 120 => 0, epoch = 61 => 1
  *sec = someTime % 60;
  someTime /= 60; // epoch = 3601 => 60, epoch = 120 => 2, epoch = 61 => 1
  // 2. Extract minutes from someTime, prep for hour
  *min = someTime % 60;
  someTime /= 60; // epoch = 60 => 1, epoch = 2 => 0, epoch = 1 => 0
  // 3. Extract hours from someTime
  *hour = someTime % 24;
}

/*
 * getDayOfWeek()
 * Returns an int representing the day of the week of a given time in
 * epoch format (secs). Leverages integer drops. Does not account for
 * inputs that are negative (before Jan 1st, 1970).
 *
 * @param {time_t} curTime - a time_t object containing a time epoch (secs)
 * @returns {int} - the day of the week in int format (0 = Sun -> 6 = Sat)
 */
int getDayOfWeek(time_t curTime) {
  // 1. Extract days from epoch with respect to curTime
  int days = ((curTime / 60) / 60) / 24;
  // 2. Determine weekday distance from Thurs, Jan 1st, 1970
  int weekday = days % 7;
  // 3. Return weekday, account for Thurs shift
  return (weekday + 4) % 7;
}

/*
 * getTime()
 * Returns a time_t epoch constructed from a given month, day, year,
 * hour, min, sec. Does not account for inputs that are before
 * Jan 1st, 1970, malformed, or time zones. Accounts for leap years.
 *
 * @param {int} month - given month, 0 based
 * @param {int} day - given day, 0 based
 * @param {int} year - given year, AD based
 * @param {int} hour - given hour, 0 based military time
 * @param {int} min - given min, 0 based
 * @param {int} sec - given sec, 0 based
 * @returns {time_t} - a time_t object constructed from month, day, year,
 *                     hour, min, sec
 */
time_t getTime(int month, int day, int year, int hour, int min, int sec) {
  time_t epoch = 0;
  // 1. Work backwards, construct based on sec, min, hour, year
  epoch += sec;
  epoch += min * 60;
  epoch += hour * 60 * 60;
  epoch += (year - 1970) * 365 * 24 * 60 * 60;
  // 2. Account for leap years (leverage that 1972 was first leap year after 1970)
  int leaps = (year - 1968) / 4;
  if ((year - 1968) % 4 == 0 && month < 2 && leaps > 0) leaps--;
  day += leaps;
  // 3. Determine total number of days passed
  epoch += day * 24 * 60 * 60;
  int monthToDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int i = 0; i < month; i++) {
    epoch += monthToDays[i] * 24 * 60 * 60;
  }
  // 4. Return epoch
  return epoch;
}