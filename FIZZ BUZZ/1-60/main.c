#include <stdio.h>
#include <string.h>
#include "fizz_buzz.h"

int main(){
    int i;
    char output[10];
    for(i=0; i<100; i++){
        fizz_buzz(i, output);
        printf("num is %d result is %s \n", i, output);
    }
    return 0;
}

