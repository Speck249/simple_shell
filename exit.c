#include "main.h"
/**
*_strncpy - copies a string
*@dest: first parameter
*@src: second parameter
*@n: third parameter
*Return: copied string
*/
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *str = dest;
i = 0;

while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (str);
}

/**
*_strncat - concatenates two strings
*@dest: first parameter
*@src: second parameter
*@n: third parameter
*Return: concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *str = dest;
i = 0;
j = 0;

while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (str);
}
/**
*_strchr - locates a character in a string
*@str: first parameter
*@ch: second parameter
*Return: located string
*/
char *_strchr(char *str, char ch)
{
do {
if (*str == ch)
return (str);
} while (*str++ != '\0');

return (NULL);
}
