#include <string.h>
#include <stdlib.h>

#include "funny_string.h"

int funny_string(char* S, char* result) {

        int fl = 0;
        int i, j, l;

        l = strlen(S);

        for(i=1, j=l-1; i < l && j > 0; i++, j--)
        {
            if(abs(S[i] - S[i-1]) == abs(S[j-1] - S[j]))
                fl++;
            else
               break;
        }

        if(fl == l-1)
            strcpy(result, "funny");
        else
            strcpy(result, "not funny");

        return fl;
}
