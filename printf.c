#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _putchar(char c)
{
        return write(1, &c, 1);
}
int print_reverse(char *s)
{
    int len = 0;
   int  count = 0;

    while (s[len])
        len++;

    for (int i = len - 1; i >= 0; i--)
        count += _putchar(s[i]);

    return count;
}
