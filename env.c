#include "main.h"
/**
*_env - prints shell environment
*@info: parameter
*Return: Always 0 (success)
*/
int _env(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
*_getenv - gets env variable value
*@info: first parameter
*@name: second parameter
*Return: env variable value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *ptr;

while (node)
{
ptr = starts_with(node->str, name);
if (ptr && *ptr)
return (ptr);
node = node->next;
}
return (NULL);
}

/**
* _setenv - creates or modifies env variable
*@info: parameter
*Return: Always 0 (success)
*/
int _setenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Invalid Number of Arguments. Try Again.\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
*_unsetenv - Remove an environment variable
*@info: parameter
*Return: Always 0(success)
*/
int _unsetenv(info_t *info)
{
int counter;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (counter = 1; counter <= info->argc; counter++)
_unsetenv(info, info->argv[counter]);

return (0);
}

/**
* populate_env_list - populates env linked list
* @info: parameter
* Return: Always 0 (success)
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t counter;

for (counter = 0; environ[counter]; counter++)
add_node_end(&node, environ[counter], 0);
info->env = node;
return (0);
}
