// Тут будет кусок запуска самого калькулятора
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main()
{
    char* input = NULL;
    size_t size_of_input = 0;
    getline(&input, &size_of_input, stdin);
    choose_mode_of_calculator(input);

    free(input);
    return 0;
}