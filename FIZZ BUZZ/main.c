#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fizz_buzz.h"

int main(){
    int i;
    char *output;
    
    output = (char*)malloc(sizeof(char)*9);

    for(i = 0; i <= 15; i++){
        fizz_buzz_detector(output, i);
        printf("number = %d %s\n", i, output);
    }   
    
    free(output);
    return 0;
}
