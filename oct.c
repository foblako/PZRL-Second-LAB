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

int convert_from_oct_to_int(char* num)
{
    int res = 0;
    int sign = get_sign(num);
    if_oct(num);
    for (int i = get_first_index(num) + 1; i < strlen(num); i++)
    {
        res = res * 8 + (num[i] - '0');
    }
    return res * sign;
}

char* convert_from_int_to_oct(int num)
{
    char* reversed_res = (char*) malloc(sizeof(char));
    while (num > 0)
    {
        reversed_res = (char*) realloc(reversed_res, strlen(reversed_res) + 1);
        reversed_res[strlen(reversed_res)] = num % 8 + '0';
        num /= 8;
    }
    char* res = (char*) malloc(sizeof(char));
    for (int i = strlen(reversed_res) - 1; i >= 0; i--)
    {
        res = (char*) realloc(res, strlen(res) + 1);
        res[strlen(res)] = reversed_res[i];
    }
    free(reversed_res);
    return res;
}