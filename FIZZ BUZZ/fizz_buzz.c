#include <string.h>
#include "fizz_buzz.h"

void fizz_buzz_detector(char *output, int i){
    if( i % 3 == 0 && i % 5 == 0 )
        strcpy( output, "FizzBuzz");
    else if( i % 3 == 0 )
        strcpy( output, "Fizz");
    else if( i % 5 == 0)
        strcpy( output, "Buzz");
    else
        strcpy( output, "");
}