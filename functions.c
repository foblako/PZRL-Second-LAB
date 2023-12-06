// реализация общих функций для всех систем счисления
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"

int get_first_index(char* num)
{
    int i = 0;
    if (num[0] == '-') { i++; }
    return i;
}

int get_sign(char* num)
{
    int sign = 1;
    if (num[0] == '-') { sign--; }
    return sign;
}

int check_system_of_input(char* input)
{
    int i = get_first_index(input);

    if (input[i] == '1') { return 2; } else 
    if (input[i] == '0' && input[i + 1] != 'x') { return 8; } else 
    if (input[i] == '0' && input[i + 1] == 'x') { return 16; } else
    { return -1; }
}