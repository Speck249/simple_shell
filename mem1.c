#include "smpshl.h"
/**
*_memset - fills memory with constant byte
*@s: first parameter
*@b: second parameter
*@n: third parameter
*Return: pointer to s
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int counter;

for (counter = 0; counter < n; counter++)
s[counter] = b;
return (s);
}

/**
*ffree - frees string of strings
*@pp: parameter
*Return: no return value
*/
void ffree(char **pp)
{
char **a = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}

/**
*_realloc - reallocates memory block
*@ptr: first parameter
*@old_size: second parameter
*@new_size: third parameter
*Return: pointer to old memory block.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
