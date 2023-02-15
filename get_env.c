#include "main.h"
/**
*get_environ - returns string copy of env
*@info: first parameter
*Return: Always 0 (success)
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->environ);
}

/**
*_unsetenv - Removes env variable
*@info: first parameter
*@var: second parameter
*Return: 1 if success, 0 if error
*/
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t i = 0;
char *ptr;

if (!node || !var)
return (0);

while (node)
{
ptr = starts_with(node->str, var);
if (ptr && *ptr == '=')
{
info->env_changed = delete_node_at_index(&(info->env), i);
i = 0;
node = info->env;
continue;
}
node = node->next;
i++;
}
return (info->env_changed);
}

/**
* _setenv - creates new env variable
*@info: first parameter
*@var: second parameter
*@value: third parameter
*Return: Always 0 (success)
*/
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *ptr;

if (!var || !value)
return (0);

buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->env;
while (node)
{
ptr = starts_with(node->str, var);
if (ptr && *ptr == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}
