#include "smpshl.h"
/**
*_strcpy - copies a string
*@dest: first parameter
*@src: second parameter
*Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
int counter = 0;

if (dest == src || src == 0)
return (dest);
while (src[counter])
{
dest[counter] = src[counter];
counter++;
}
dest[counter] = 0;
return (dest);
}

/**
*_strdup - duplicates string
*@str: parameter
*Return: pointer to duplicated string
*/
char *_strdup(const char *str)
{
int len = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
len++;
ret = malloc(sizeof(char) * (len + 1));
if (!ret)
return (NULL);
for (len++; len--;)
ret[len] = *--str;
return (ret);
}

/**
*_puts - prints an input string
*@str: parameter
*Return: no return value
*/
void _puts(char *str)
{
int counter = 0;

if (!str)
return;
while (str[counter] != '\0')
{
_putchar(str[counter]);
counter++;
}
}

/**
*_putchar - writes character to stdout
*@ch: parameter
*Return: 1 for success, -1 otherwise
*/
int _putchar(char ch)
{
static int counter;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, counter);
counter = 0;
}
if (ch != BUF_FLUSH)
buf[counter++] = ch;
return (1);
}
