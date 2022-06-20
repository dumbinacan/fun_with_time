#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fun_with_time.h"

int
main ( int argc, char** argv )
{
    struct tm *my_bday = calloc(1, sizeof (struct tm) );
    struct tm *my_first_billion = calloc(1, sizeof (struct tm) );
    double part_of_history;

    my_bday->tm_min = 45;
    my_bday->tm_hour = 2;
    my_bday->tm_mday = 27;
    my_bday->tm_mon = 10;
    my_bday->tm_year = 90;
    printf( "Born: %s", asctime(my_bday) );

    my_first_billion = billion_seconds_later(my_bday, my_first_billion);
    printf( "Billionth Second: %s", asctime(my_first_billion) );

    part_of_history = percent_of_history(my_bday);
    printf( "You have lived through %f%% of American History\n", part_of_history );

    return 0;
}
