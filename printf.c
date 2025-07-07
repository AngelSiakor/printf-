#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <limits.h>


int _putchar(char c)
{
        return write(1, &c, 1);
}

int print_str(char *s)
{
        int i = 0;
        if (!s)
                s = "(null)";

        while (s[i])
        {
                _putchar(s[i]);
                i++;
        }
        return i;
}

int print_num(int num)
{
	static int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	if (num > 10)
	{
		count++;
		print_num(num / 10);
	}

	count++;
	_putchar((num % 10) + '0');
	return count;
}

int print_reverse(char *s)
{
    int len = 0;

    while (s[len])
        len++;

    for (int i = len - 1; i >= 0; i--)
         _putchar(s[i]);

    return 0;
}
int print_octal(unsigned int num)
{
        int count = 0;

        if (num / 8)
        {
                count ++;
	       	print_octal(num / 8);
        }
         _putchar((num % 8) + '0');
        return 0;
}
int print_unsigned(unsigned int num)
{
    int count = 0;

    if (num / 10)
        count += print_unsigned(num / 10);

    count += _putchar((num % 10) + '0');

    return count;
}
int print_hex(unsigned int num)
{
    static int count = 0;
    char *hex = "0123456789abcdef";

    if (num / 16)
    {
        count ++;
	print_hex(num / 16);
    }

    count ++;
    _putchar(hex[num % 16]);

    return count;
}
int print_upper_hex(unsigned int num)
{
    static int count = 0;
    char *hex = "0123456789ABCDEF";

    if (num / 16)
    {
        count ++;
	print_upper_hex(num / 16);
    }

    count ++;
    _putchar(hex[num % 16]);

    return count;
}
int print_float(double num, int precision)
{
	static int count = 0;
	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	int int_part = (int)num;
	count ++;
	print_num(int_part);
	count ++;
	_putchar('.');
	double frac = num - int_part;

	for (int i = 0; i < precision; i++)
		frac *= 10;
	int frac_int = (int)(frac);

	count ++; 
	print_num(frac_int);
	return count;
}

int print_binary(unsigned int num)
{
  	static int count = 0;

    if (num / 2)
    {
	 count++;
         print_binary(num / 2);
    }

    _putchar((num % 2) + '0');

    return count;
}

int print_pointer(void *ptr)
{
    static  int count = 0;
    unsigned long addr = (unsigned long)ptr;

    count ++;
    print_str("0x");
    count ++;
    print_hex(addr);

    return count;
}

int _printf(char *format, ...)
{
	int i = 0;
	static int printed = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != 0; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			if (format[i] == 's')
			{
				printed ++;
				print_str(va_arg(args, char *));
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				printed ++;
				print_num(va_arg(args, int));
			}
			else if (format[i] == 'f')
			{
				printed ++;
				print_float(va_arg(args, double), 2);
			}
			else if (format[i] == 'b')
			{
				printed += print_binary(va_arg(args, int));
			}
			else if (format[i] == 'u')
			{
				printed ++;
				print_unsigned(va_arg(args, unsigned int ));
			}
			else if (format[i] == 'x')
			{
				printed ++;
				print_hex(va_arg(args, unsigned int));
			}
			else if (format[i] == 'X')
			{
				printed ++;
				print_upper_hex(va_arg(args, unsigned int));
			}
			else if (format[i] == 'c')
			{
				printed ++;
				_putchar(va_arg(args, int));
			}
			else if (format[i] == '%')
			{
				printed ++;
				_putchar('%');
			}
			else if (format[i] == 'o')
			{
				printed ++;
				print_octal(va_arg(args, unsigned int));
			}
			else if (format[i] == 'X')
			{
				printed ++;
				print_upper_hex(va_arg(args, unsigned int));
			}
			else if (format[i] == 'p')
			{
				printed++;
				print_pointer(va_arg(args, void *));
			}
			else if (format[i] == '%')
			{
				printed++;
				_putchar('%');
			}
			else
			{

				printed ++;
				_putchar('%');
				printed ++;
				_putchar(format[i]);
			}
		}
		else
		{
			printed ++;
			_putchar(format[i]);
		}
	}

	va_end(args);
	return printed;
}

int main(void)
{
    int len;
    int len2;
    unsigned int ui, ua;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    _printf("%f", 2322.23);
    return (0);
}

