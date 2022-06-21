#ifndef FUN_WITH_TIME_H
#define FUN_WITH_TIME_H
#include <stdbool.h>
#include <time.h>
#include "fun_with_time.h"
bool add_secs(time_t tm, const struct tm *start, struct tm *end);
double ratio(const struct tm *bday, const struct tm *milestone);
bool copy_structtm(const struct tm *src, struct tm *dst);
#endif
