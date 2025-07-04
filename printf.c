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
int octal_num(int num)
{
        int i;
        int count = 0;

        if (num / 8)
        {
                count += octal_num(num / 8);
        }
        count += _putchar((num % 8) + '0');

        return count;
}
int print_unsigned(unsigned int num)
{
    int count = 0;

    if (num / 10)
        count += print_unsigned(num / 10);

    count += _putchar((num % 10) + '0');

    return count;
}
