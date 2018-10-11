#include <string.h>
#include "fizz_buzz.h"

void fizz_buzz(int number, char* output){
    if(number%3 == 0 && number%5 == 0)
        strcpy(output, "FizzBuzz");
    else if(number%3 == 0)
        strcpy(output, "Fizz");
    else if(number%5 == 0)
        strcpy(output, "Buzz");
    else
        strcpy(output, "");
}

