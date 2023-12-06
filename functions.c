// реализация общих функций для всех систем счисления
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"

#define SIZE 128

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

int do_operation(int n1, int n2, char o)
{
    switch (o)
    {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
        return n1 / n2;
    case '&':
        return n1 & n2;
    case '|':
        return n1 | n2;
    case '^':
        return n1 ^ n2;
    default:
        return -1;
    }
}

int unary_operation(char* input)
{
    char number[SIZE];
    memset(number, 0, sizeof(number));
    for (int i = 1; i < strlen(input); i++)
    {
        if (isspace(input[i]))
        {
            continue;
        }
        number[strlen(number)] = input[i];
        
    }

    int system = check_system_of_input(number);
    int num = to_int(number, system);

    // сделать унарное отрицание!

    return 0;
}

int binary_operation(char* input)
{
    return 0;
}

int to_int(char* number, int system)
{
    switch (system)
    {
    case 2:
        convert_from_bin_to_int(number);
    case 8:
        convert_from_oct_to_int(number);
    case 16:
        convert_from_hex_to_int(number);
    default:
        return -1;
    }
}