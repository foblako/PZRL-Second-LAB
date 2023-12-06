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

int convert_from_hex_to_int(char* num)
{
    int res = 0;
    int sign = get_sign(num);
    if_hex(num);
    for (int i = get_first_index(num) + 2; i < strlen(num); i++)
    {
        if (num[i] >= '0' && num[i] <= '9') { res = res * 16 + (num[i] - '0'); } else 
        if (num[i] >= 'a' && num[i] <= 'f') { res = res * 16 + (num[i] - 'a' + 10); } else 
        if (num[i] >= 'A' && num[i] <= 'F') { res = res * 16 + (num[i] - 'A' + 10); }
    }
    return res * sign;
}

char* convert_from_int_to_hex(int num)
{
    char* reversed_res = (char*) malloc(sizeof(char));
    while (num > 0)
    {
        reversed_res = (char*) realloc(reversed_res, strlen(reversed_res) + 1);
        if (num % 16 >= 0 && num % 16 <= 9){ reversed_res[strlen(reversed_res)] = num % 16 + '0';} 
        else { reversed_res[strlen(reversed_res)] = num % 16 - 10 + 'A';}
        num /= 16;
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