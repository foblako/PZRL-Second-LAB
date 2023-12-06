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

char* convert_from_int_to_hex(int number)
{
    char *result_reversed = (char *) malloc(sizeof(char));
    while (number > 0) {
        int digit = number % 16;
        if (digit >= 0 && digit <= 9) {
            result_reversed = (char *) realloc(result_reversed, (strlen(result_reversed) + 1) * sizeof(char));
            result_reversed[strlen(result_reversed)] = digit + '0';
        } else {
            result_reversed = (char *) realloc(result_reversed, (strlen(result_reversed) + 1) * sizeof(char));
            result_reversed[strlen(result_reversed)] = digit - 10 + 'A';
        }
        number /= 16;
    }

    char *result = (char *) malloc(sizeof(char));
    for (int i = strlen(result_reversed) - 1; i >= 0; i--) {
        result = (char *) realloc(result, (strlen(result) + 1) * sizeof(char));
        result[strlen(result)] = result_reversed[i];
    }
    free(result_reversed);
    return result;
}

