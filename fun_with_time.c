#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "fun_with_time.h"

const int ONE_BILLION = 1000000000;

struct tm*
billion_seconds_later(const struct tm *start_date, struct tm* end_date)
{
    struct tm *cpy = calloc(1, sizeof (struct tm) );
    time_t time;

    copy_structtm(start_date, cpy);
    time = mktime(cpy);
    time += ONE_BILLION;

    end_date = localtime(&time);
    return end_date;
}

/* 
 **
 * TODO
 * percent_of_history(const struct tm *start_date,
 *                      const struct tm *milestone)
 * add a database with notable dates to compare
 **
 */
double
percent_of_history(const struct tm *start_date)
{
    int64_t americas_age;
    time_t your_age;
    time_t today = time(NULL);
                      /* July 4th, 1776 */
    struct tm americas_bday = {0, 0, 0, 4, 6, -124, 4, 186, -1};
    struct tm *cpy = calloc(1, sizeof (struct tm) );

    if ( !copy_structtm(start_date, cpy) ) { return 0.0; }
    your_age = today - mktime(cpy);
    americas_age = (int64_t)  mktime(&americas_bday) * -1
                            + today;

    return (double) 100 * your_age / americas_age;
}

bool /* could I avoid this function by passing by value? */
copy_structtm(const struct tm *src, struct tm *dst)
{
    if (src == NULL || dst == NULL) { return false; }
    dst->tm_sec = src->tm_sec;
    dst->tm_min = src->tm_min;
    dst->tm_hour = src->tm_hour;
    dst->tm_mday = src->tm_mday;
    dst->tm_mon = src->tm_mon;
    dst->tm_year = src->tm_year;
    dst->tm_wday = src->tm_wday;
    dst->tm_yday = src->tm_yday;
    dst->tm_isdst = src->tm_isdst;
    return true;
}
