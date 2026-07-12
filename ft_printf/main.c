#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int print_char(int c)
{
    return (write(1, &c, 1));
}int print_str(char *str)
{
    int count;    count = 0;
    while (*str != '\0')
    {
        print_char((int)*str);
        ++count;
        ++str;
    }
    return (count);
}int print_digit(long n, int base)
{
    int     count;
    char    *symb;    symb = "0123456789abcdef";
    if (n < 0)
    {
        write (1, "-", 1);
        return (print_digit(-n, base) + 1);
    }
    else if (n < base)
    {
        // printf("%d\n", symb[n]);
        return (print_char(symb[n]));
    }
    else
    {
        count = print_digit ((n / base), base);
        return (count = print_digit (n % base, base));
    }
}int print_format(char option, va_list args)
{
    int     count;    if (option == 'c')
        count += print_char ((char)va_arg(args, int));
    else if (option == 's')
        count += print_str (va_arg(args, char *));
    else if (option == 'd' || option == 'i')
        count += print_digit (va_arg(args, int), 10);
    else if (option == 'x')
        count += print_digit (va_arg(args, unsigned int), 16);
    else if (option == 'X')
        count += print_digit (va_arg(args, unsigned int), 16);
    else
        count += write(1, &option, 1);
    return (count);
}int ft_printf(const char *format, ...)
{
    va_list args;
    int     count;
    int     i;
    char    c;    va_start(args, format);    count = 0;
    while (*format != '\0')
    {
        if (*format == '%')
            count += print_format(*(++format), args);
        else
            count += write(1, format, 1);
        format++;
    }
    va_end(args);
    return (count);
}int main( void)
{
    int i;
    int ch;    ch = 0;
    i = printf("Hello %s\n", "World");
    printf("printf => The chars written are %d\n", i);
    // ch = ft_printf("Hello %s\n", "World");
    ch = ft_printf("Hello World\n");
    ft_printf("ft_printf => The chars written are %d\n", ch);
    ft_printf("ft_printf => Char %c\n", 'b');
    printf("printf => Char %c\n", 'b');
    ft_printf("ft_printf => x %x\n", 1234);
    printf("printf => x %x\n", 1234);
    ft_printf("ft_printf => d %d\n", -222);
    printf("printf => d %d\n", -222);
    ft_printf("ft_printf => i %i\n", 0);
    printf("printf => i %i\n", 0);
    return (0);
}
