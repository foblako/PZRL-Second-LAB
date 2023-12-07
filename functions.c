// реализация общих функций для всех систем счисления
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
    if (num[0] == '-') { sign = -1; }
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
        break;
    case '-':
        return n1 - n2;
        break;
    case '*':
        return n1 * n2;
        break;
    case '/':
        return n1 / n2;
        break;
    case '%':
        return n1 % n2;
        break;
    case '&':
        return n1 & n2;
        break;
    case '|':
        return n1 | n2;
        break;
    case '^':
        return n1 ^ n2;
        break;
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

    show_result(~num, system);

    return 0;
}

int binary_operation(char* input)
{
    char first_number[SIZE];
    char second_number[SIZE];

    memset(first_number, 0, sizeof(first_number));
    memset(second_number, 0, sizeof(second_number));

    char operation;
    int slide = -1;

    for (int i = 0; i < strlen(input); i++)
    {
        if (isspace(input[i])) { continue; }
        if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '&' || input[i] == '|' || input[i] == '^') && slide == 1)
        {
            operation = input[i];
            slide = 2;
            continue;
        }
        if (slide == 1 || slide == -1)
        {
            slide = 1;
            first_number[strlen(first_number)] = input[i];
        } else
        {
            second_number[strlen(second_number)] = input[i];
        }
    }

    int first_system = check_system_of_input(first_number);
    int second_system = check_system_of_input(second_number);
    
    if (first_system != second_system || first_system == -1 || second_system == -1)
    {
        printf("Системы счисления не совпадают, либо число/а не в 2/8/16 системах!");
        return 1;
    }

    if (system_correct(first_number, first_system) == 1 || system_correct(second_number, second_system) == 1)
    {
        printf("Неверное число!");
        return 0;
    }
    
    int int_first_number = to_int(first_number, first_system);
    int int_second_number = to_int(second_number, second_system);

    if ((operation == '&' || operation == '|' || operation == '^') && (int_first_number < 0 || int_second_number  < 0))
    {
        printf("Эта операция [%c] над отрицательными числами запрещена!", operation);
        return 0;
    }
    
    if (operation == '/' && int_second_number == 0)
    {
        printf("Деление на ноль запрещено!");
        return 0;
    }

    int res = do_operation(int_first_number, int_second_number, operation);
    show_result(res, first_system);

    return 0;
}

int system_correct(char* number, int system)
{
    switch (system) {
        case 2:
            return if_bin(number);
        case 8:
            return if_oct(number);
        case 16:
            return if_hex(number);
        default:
            return 1;
    }
}

int to_int(char* number, int system)
{
    switch (system)
    {
    case 2:
        convert_from_bin_to_int(number);
        break;
    case 8:
        convert_from_oct_to_int(number);
        break;
    case 16:
        convert_from_hex_to_int(number);
        break;
    default:
        return -1;
    }
}

void show_result(int num, int system)
{
    char* res;
    int len;
    int sign = 1;
    if (num < 0)
    {
        sign = -1;
        printf("-");
    }
    switch (system)
    {
    case 2:
            res = convert_from_int_to_bin(num * sign);
            len = strlen(res);
            if (len){ printf("%s  (%d)\n", res, num);} 
            else { printf("0   (0)\n");}
            free(res); 
            break;      
    case 8:
            res = convert_from_int_to_oct(num * sign);
            len = strlen(res);
            if (len){ printf("0%s  (%d)\n", res, num);} 
            else { printf("00   (0)\n");} 
            free(res);
            break;
    case 16:
            res = convert_from_int_to_hex(num * sign);
            len = strlen(res);
            if (len){ printf("0x%s  (%d)\n", res, num);} 
            else { printf("0x0   (0)\n");} 
            free(res);
            break;        
    default:
        return;
    }
}

int choose_mode_of_calculator(char* input)
{
    if (input[0] == '~'){ return unary_operation(input);} 
    else{ return binary_operation(input); }
}