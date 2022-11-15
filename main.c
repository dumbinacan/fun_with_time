#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fun_with_time.h"
const int ONE_BILLION = 1000000000;
const int ONE_MILLION = 1000000;
const struct tm AMERICAS_BDAY ={0, 0, 0, 4, 6, -124, 4, 186, -1};
const struct tm MY_BDAY = {0, 45, 2, 27, 10, 90, 2, 331, 0};
const struct tm NITA_BDAY = {0, 35, 18, 27, 6, 91, 5, 0, 0};

int
main ( int argc, char** argv )
{
    struct tm *a_billie = calloc(1, sizeof (struct tm) );
    double part_of_history;

    if ( add_secs(ONE_MILLION, &MY_BDAY, a_billie) ) {
        printf( "Millionth Second: %s", asctime(a_billie) );
    }

    if ( add_secs(ONE_BILLION, &MY_BDAY, a_billie) ) {
        printf( "Billionth Second: %s", asctime(a_billie) );
    }

    part_of_history = ratio(&MY_BDAY, &AMERICAS_BDAY);
    printf( "You have lived through %f%% of American History\n", part_of_history );

    return 0;
}
