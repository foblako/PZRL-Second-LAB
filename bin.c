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

char* convert_from_int_to_bin(int number)
{
    char *result_reversed = (char *) malloc(sizeof(char));
    while (number > 0) {
        int digit = number % 2;
        result_reversed = (char *) realloc(result_reversed, (strlen(result_reversed) + 1) * sizeof(char));
        result_reversed[strlen(result_reversed)] = digit + '0';
        number /= 2;
    }
    char *result = (char *) malloc(sizeof(char));
    for (int i = strlen(result_reversed) - 1; i >= 0; i--) {
        result = (char *) realloc(result, (strlen(result) + 1) * sizeof(char));
        result[strlen(result)] = result_reversed[i];
    }
    free(result_reversed);
    return result;
}