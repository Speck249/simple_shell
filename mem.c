#include "main.h"
/**
*bfree - frees pointer & sets address to NULL
*@ptr: parameter
*Return: 1 if success, 0 otherwise
*/
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
