#include "smpshl.h"
/**
*_isalpha - checks for alphabetic character
*@ch: parameter
*Return: 1 if true, 0 if false
*/
int _isalpha(int ch)
{
if ((ch > 96  && ch < 123) || (ch > 64 && ch < 91))
return (1);

else
return (0);
}

/**
*is_delim - checks for a delimiter
*@ch: first parameter
*@delim: second parameter
*Return: 1 if true, 0 if false
*/
int is_delim(char ch, char *delim)
{
while (*delim)
{
if (*delim++ == ch)
return (1);
}
return (0);
}

/**
*interactive - checks if shell is interactive
*@info: parameter
*Return: interactive status
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
*_atoi - string to integer type conversion
*@str: parameter
*Return: converted value
*/
int _atoi(char *str)
{
int counter, sign = 1, flag = 0, output;
unsigned int result = 0;

for (counter = 0;  str[counter] != '\0' && flag != 2; counter++)
{
if (str[counter] == '-')
sign *= -1;

if (str[counter] >= '0' && str[counter] <= '9')
{
flag = 1;
result *= 10;
result += (str[counter] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}
