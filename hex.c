// работа с шестнадцатеричным инпутом
#include <string.h>
#include <stdlib.h>

#include "functions.h"

int if_hex(char* num)
{
    for (int i = get_first_index(num) + 2; i < strlen(num); i++)
    {
        if (!(('0' <= num[i] && num[i] <= '9') || ('a' <= num[i] && num[i] <= 'f') || ('A' <= num[i] && num[i] <= 'F'))) { return 1; } 
    } return 0;
}