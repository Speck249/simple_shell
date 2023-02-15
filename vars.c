#include "smpshl.h"
/**
*is_chain - checks for a chain delimiter
*@info: first parameter
*@buf: second parameter
*@ptr: third parameter
*Return: 1 for success, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *ptr)
{
size_t j = *ptr;

if (buf[j] == '|' && buf[j + 1] == '|')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[j] == '&' && buf[j + 1] == '&')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[j] == ';')
{
buf[j] = 0;
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*ptr = j;
return (1);
}

/**
*check_chain - checks chain
*@info: first parameter
*@buf: second parameter
*@ptr: third parameter
*@i: fourth parameter
*@len: buffer length
*Return: no return value
*/
void check_chain(info_t *info, char *buf, size_t *ptr, size_t i, size_t len)
{
size_t j = *ptr;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
j = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
j = len;
}
}
*ptr = j;
}

/**
*replace_alias - alias replacement
*@info: parameter
*Return: 1 for success, 0 otherwise
*/
int replace_alias(info_t *info)
{
int counter;
list_t *node;
char *ptr;

for (counter = 0; counter < 10; counter++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
ptr = _strchr(node->str, '=');
if (!ptr)
return (0);
ptr = _strdup(ptr + 1);
if (!ptr)
return (0);
info->argv[0] = ptr;
}
return (1);
}

/**
*replace_vars - vars replacement
*@info: parameter
*Return: 1 for success, 0 otherwise
*/
int replace_vars(info_t *info)
{
int counter = 0;
list_t *node;

for (counter = 0; info->argv[counter]; counter++)
{
if (info->argv[counter][0] != '$' || !info->argv[counter][1])
continue;

if (!_strcmp(info->argv[counter], "$?"))
{
replace_string(&(info->argv[counter]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[counter], "$$"))
{
replace_string(&(info->argv[counter]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[counter][1], '=');
if (node)
{
replace_string(&(info->argv[counter]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[counter], _strdup(""));
}
return (0);
}

/**
*replace_string - string replacement
*@old: first parameter
*@new: second parameter
*Return: 1 for success, 0 otherwise
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
