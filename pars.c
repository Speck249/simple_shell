#include "main.h"
/**
*is_cmd - determines if file is executable
*@info: first parameter
*@path: second parameter
*Return: 1 if true, 0 otherwise
*/
int is_cmd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
*dup_chars - duplicates characters
*@pathstr: first parameter
*@start: second parameter
*@stop: third parameter
*Return: pointer to new buffer
*/
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];
int i = 0, k = 0;

for (k = 0, i = start; i < stop; i++)
if (pathstr[i] != ':')
buf[k++] = pathstr[i];
buf[k] = 0;
return (buf);
}

/**
*find_path - finds this cmd in the PATH string
*@info: first parameter
*@pathstr: second parameter
*@cmd: third parameter
*Return: full path of cmd, otherwise NULL
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
int counter = 0, curr_pos = 0;
char *path;

if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[counter] || pathstr[counter] == ':')
{
path = dup_chars(pathstr, curr_pos, counter);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[counter])
break;
curr_pos = counter;
}
counter++;
}
return (NULL);
}
