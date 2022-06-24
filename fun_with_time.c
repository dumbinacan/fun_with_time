#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include "fun_with_time.h"

// const int ONE_BILLION = 1000000000;
// const struct tm americas_bday = {0, 0, 0, 4, 6, -124, 4, 186, -1};

bool
add_secs(time_t tm, const struct tm *start, struct tm* end)
{
    struct tm *cpy = calloc(1, sizeof (struct tm) );
    time_t time;

    if ( !copy_structtm(start, cpy) ) { return false; }
    time = mktime(cpy);
    time += tm;

    if ( !copy_structtm(localtime(&time), end) ) { return false; }
    return true;
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
ratio(const struct tm *bday, const struct tm *milestone)
{
    int64_t milestone_age; // avoid overflow
    time_t your_age;
    time_t today = time(NULL);
    struct tm *bd_cpy = calloc(1, sizeof (struct tm) );
    struct tm *ms_cpy = calloc(1, sizeof (struct tm) );

    if ( !copy_structtm(bday, bd_cpy) ) { return 0.0; }
    if ( !copy_structtm(milestone, ms_cpy) ) { return 0.0; }
    your_age = today - mktime(bd_cpy);
    milestone_age = (int64_t)  mktime(ms_cpy) * -1 + today;

    return (double) 100 * your_age / milestone_age;
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
