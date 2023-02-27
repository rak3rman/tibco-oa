/*
 * Epoch Parsing
 *
 * Radison Akerman, February 2023
 * TIBCO Coding Assessment
 */

#include "epochParse.h"
#include <sys/_types/_time_t.h>
#include <time.h>

/*
 * getHMS()
 * Parses the hour, min, and sec of a given time in epoch format.
 *
 * @param {time_t} someTime - a time_t object containing a time epoch
 * @param {int*} hour - pointer to hour based on someTime
 * @param {int*} min - pointer to min based on someTime
 * @param {int*} sec - pointer to sec based on someTime
 */
void getHMS(time_t someTime, int *hour, int *min, int *sec) {

}

/*
 * getDayOfWeek()
 * Returns an int representing the day of the week of a given time in
 * epoch format.
 *
 * @param {time_t} curTime - a time_t object containing a time epoch
 * @returns {int} - the day of the week in int format (0 = Sun -> 6 = Sat)
 */
int getDayOfWeek(time_t curTime) {
    return 0;
}

/*
 * getTime()
 * Returns a time_t epoch constructed from a given month, day, year,
 * hour, min, sec.
 *
 * @param {int} month - given month
 * @param {int} day - given day
 * @param {int} year - given year
 * @param {int} hour - given hour
 * @param {int} min - given min
 * @param {int} sec - given sec
 * @returns {time_t} - a time_t object constructed from month, day, year,
 *                     hour, min, sec
 */
time_t getTime(int month, int day, int year, int hour, int min, int sec) {
    time_t value;
    return value;
}