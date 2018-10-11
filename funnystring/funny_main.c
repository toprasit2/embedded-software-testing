#include <stdio.h>
#include <string.h>

#include "funny_string.h"

int main() {

    char str[][100] = {"acxz", "bcxz"}; 
    char output[10];
    int i, lenght=2;
    int distance;
        
    for(i = 0; i < lenght; i++){
        distance = funny_string(str[i], output);
        printf("%s get %s distance %d\n", str[i], output, distance);
    }

    return 0;
}
