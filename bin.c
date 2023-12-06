// работа с бинарным инпутом
#include <string.h>
#include <stdlib.h>

#include "functions.h"

int if_bin(char* num)
{
    for (int i = get_first_index(num); i < strlen(num); i++)
    {
        if (!('0' <= num[i] && num[i] <= '1')) { return 1; } 
    } return 0;
}