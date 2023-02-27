#include <time.h>

void getHMS(time_t someTime, int *hour, int *min, int *sec);
int getDayOfWeek(time_t curTime);
time_t getTime(int month, int day, int year, int hour, int min, int sec);