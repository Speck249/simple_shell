#include "main.h"
/**
*_eputs - prints input string
*@str: parameter
*Return: no return value
*/
void _eputs(char *str)
{
int counter = 0;

if (!str)
return;
while (str[counter] != '\0')
{
_eputchar(str[counter]);
counter++;
}
}

/**
* _eputchar - writes character ch to stderr
*@c: parameter
*Return: 1 for success, -1 for error
*/
int _eputchar(char ch)
{
static int counter;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || counter >= WRITE_BUF_SIZE)
{
write(2, buf, counter);
counter = 0;
}
if (ch != BUF_FLUSH)
buf[counter++] = ch;
return (1);
}

/**
*_putfd - writes character to given file descriptor
*@ch: first parameter
*@fd: second parameter
*Return: 1 for success, -1 for error.
*/
int _putfd(char ch, int fd)
{
static int counter;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || counter >= WRITE_BUF_SIZE)
{
write(fd, buf, counter);
counter = 0;
}
if (ch != BUF_FLUSH)
buf[counter++] = ch;
return (1);
}

/**
*_putsfd - prints input string
*@str: first parameter
*@fd: second parameter
*Return: char count
*/
int _putsfd(char *str, int fd)
{
int counter = 0;

if (!str)
return (0);
while (*str)
{
counter+= _putfd(*str++, fd);
}
return (counter);
}
