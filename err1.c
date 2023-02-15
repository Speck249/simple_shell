#include "main.h"
/**
*_erratoi - converts string to integer
*@str: parameter
*Return: -1 for error, converted value otherwise
*/
int _erratoi(char *str)
{
int counter = 0;
unsigned long int result = 0;

if (*str == '+')
str++;
for (counter = 0; str[counter] != '\0'; counter++)
{
if (str[counter] >= 48 && str[counter] <= 57)
{
result *= 10;
result += (str[counter] - 48);
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
*print_error - prints error message
*@info: first parameter
*@estr: second parameter
*Return: 0 for error, converted integer otherwise
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
*print_d - function prints base 10
*@input: first parameter
*@fd: second parameter
*Return: number of characters printed
*/
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int counter, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (counter = 1000000000; counter > 1; counter /= 10)
{
if (_abs_ / counter)
{
__putchar('0' + current / counter);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;

return (count);
}

/**
*convert_num - mimics itoa
*@num: first parameter
*@base: second parameter
*@flags: third parameter
*Return: string
*/
char *convert_num(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do	{
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
*remove_comments - removes comments
*@buf: parameter
*Return: Always 0 (success)
*/
void remove_comments(char *buf)
{
int counter;

for (counter = 0; buf[counter] != '\0'; counter++)
if (buf[counter] == '#' && (!counter || buf[counter - 1] == ' '))
{
buf[counter] = '\0';
break;
}
}
