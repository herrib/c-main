#include "two_fer.h"
#include <string.h>
#include <stdlib.h>


void two_fer(char *buffer, const char *name)
{

    char base[] = "One for you, one for me.";
    if (!name)
    {
        memcpy(buffer, base, sizeof(base));
        return;
    }
    char first[] = "One for ";
    memcpy(buffer, first, sizeof(first));
    char second[] = ", one for me.";
    strcat(buffer, name);
    strcat(buffer, second);
}

/*
#include "two_fer.h"
#include <stdio.h>
void two_fer(char *buffer, const char *name) {
     sprintf(buffer, "One for %s, one for me.", name? name : "you");   
}
*/