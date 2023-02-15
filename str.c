#include "smpshl.h"
/**
*_strlen - computes string length
*@str: parameter
*Return: integer length of string
*/
int _strlen(char *str)
{
int counter = 0;

if (!str)
return (0);

while (*str++)
counter++;
return (counter);
}

/**
*_strcmp - compares two strings one char at a time
*@str1: first parameter
*@str2: second parameter
*Return: 0 for identical strings, non-zero value otherwise
*/
int _strcmp(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}

/**
*starts_with - checks if needle starts with haystack
*@haystack: first parameter
*@needle: second parameter
*Return: address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
*_strcat - concatenates two strings
*@dest: first parameter
*@src: second parameter
*Return: pointer to dest
*/
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;

while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
