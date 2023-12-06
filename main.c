// Тут будет кусок запуска самого калькулятора
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main()
{
    printf("%d\n", if_bin("101010110"));
    printf("%d\n", if_oct("0101010110"));
    printf("%d\n", if_hex("0x1e0101ace0110"));

    printf("%d\n", convert_from_bin_to_int("10100"));
    printf("%d\n", convert_from_oct_to_int("0101500"));
    printf("%d\n", convert_from_hex_to_int("0xF"));
    return 0;
}