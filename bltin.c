#include "main.h"
/**
*_exit - enables shell exit
*@info: parameter
*Return: exit status
*/
int _exit(info_t *info)
{
int exitcheck;

if (info->argv[1])
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "erroneous Input: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
*_cd - change directory
*@info: parameter
*Return: Always 0 (success)
*/
int _cd(info_t *info)
{
char *str, *dir, buffer[1024];
int chdir_ret;

str = getcwd(buffer, 1024);
if (!str)
_puts("failed to access Dir.\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_ret = /* what should this be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(str);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* what should this be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "error accessing Dir.");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
*_help - changes current directory of process
*@info: parameter
*Return: Always 0 (success)
*/
int _help(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puts("help call successful. Function not yet implemented \n");
if (0)
_puts(*arg_array);
return (0);
}
