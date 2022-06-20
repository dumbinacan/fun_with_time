#ifndef FUN_WITH_TIME_H
#define FUN_WITH_TIME_H
#include <stdbool.h>
#include <time.h>
#include "fun_with_time.h"
/* when will you turn a billion seconds old? */
struct tm* billion_seconds_later(const struct tm *start_date, struct tm *end_date);
/* what percentage of american history have lived through? */
double percent_of_history(const struct tm *start_date);
bool copy_structtm(const struct tm *src, struct tm *dst);
#endif
