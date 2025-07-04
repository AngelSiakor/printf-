#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _putchar(char c)
{
        return write(1, &c, 1);
}

