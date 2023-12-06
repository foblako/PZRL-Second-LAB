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

int convert_from_bin_to_int(char* num)
{
    int res = 0;
    int sign = get_sign(num);
    if_bin(num);
    for (int i = get_first_index(num); i < strlen(num); i++)
    {
        res = res * 2 + (num[i] - '0');
    }
    return res * sign;
}

char* convert_from_int_to_bin(int num)
{
    char* reversed_res = (char*) malloc(sizeof(char));
    while (num > 0)
    {
        reversed_res = (char*) realloc(reversed_res, strlen(reversed_res) + 1);
        reversed_res[strlen(reversed_res)] = num % 2 + '0';
        num /= 2;
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