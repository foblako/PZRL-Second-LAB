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
    return 0;
}