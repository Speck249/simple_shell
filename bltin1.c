#include "main.h"
/**
*set_alias - sets alias to string
*@info: first parameter
*@str: second parameter
*Return: Always 0 (success)
*/
int set_alias(info_t *info, char *str)
{
char *ptr;

ptr = _strchr(str, '=');
if (!ptr)
return (1);
if (!*++ptr)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - prints alias string
* @node: parameter
* Return: Always 0 (success)
*/
int print_alias(list_t *node)
{
char *ptr = NULL, *a = NULL;

if (node)
{
ptr = _strchr(node->str, '=');
for (a = node->str; a <= ptr; a++)
_putchar(*a);
_putchar('\'');
_puts(ptr + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
*unset_alias - sets alias to string
*@info: first parameter
*@str: second parameter
*Return: Always 0 (success)
*/
int unset_alias(info_t *info, char *str)
{
char ch, *ptr;
int result;

ptr = _strchr(str, '=');
if (!ptr)
return (1);

ch = *ptr;
*ptr= 0;
result = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*ptr = ch;
return (result);
}

/**
*_alias - creates, redefines, writes values of exiting alias def to stdout
*@info: parameter
*Return: Always 0 (success)
*/
int _alias(info_t *info)
{
int counter = 0;
char *ptr = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (counter = 1; info->argv[counter]; counter++)
{
ptr = _strchr(info->argv[counter], '=');
if (ptr)
set_alias(info, info->argv[counter]);
else
print_alias(node_starts_with(info->alias, info->argv[counter], '='));
}
return (0);
}

/**
*_history - enables history display
*@info: parameter
*Return: Always 0 (success)
*/
int _history(info_t *info)
{
print_list(info->history);
return (0);
}
