// работа с восьмиричным инпутом
#include <string.h>
#include <stdlib.h>

#include "functions.h"

int if_oct(char* num)
{
    for (int i = get_first_index(num) + 1; i < strlen(num); i++)
    {
        if (!('0' <= num[i] && num[i] <= '7')) { return 1; } 
    } return 0;
}