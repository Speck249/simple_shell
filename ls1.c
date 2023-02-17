#include "main.h"
/**
*list_len - determines linked list length
*@h: parameter
*Return: list size
*/
size_t list_len(const list_t *h)
{
size_t counter = 0;

while (h)
{
h = h->next;
counter++;
}
return (counter);
}

/**
*list_to_strings - returns an array of strings of the list->str
*@head: pointer to first node
*Return: array of strings
*/
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), j;
char **strs;
char *str;

if (!head || !i)
return (NULL);
strs = malloc(sizeof(char *) * (i + 1));
if (!strs)
return (NULL);
for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < i; j++)
free(strs[j]);
free(strs);
return (NULL);
}
str = _strcpy(str, node->str);
strs[i] = str;
}
strs[i] = NULL;
return (strs);
}


/**
*print_list - prints all elements of a list_t linked list
*@h: parameter
*Return: list size
*/
size_t print_list(const list_t *h)
{
size_t i = 0;

while (h)
{
_puts(convert_num(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}

/**
*node_starts_with - returns node whose string starts with prefix
*@node: first parameter
*@prefix: second parameter
*@ch: third parameter
*Return: match node or null
*/
list_t *node_starts_with(list_t *node, char *prefix, char ch)
{
char *ptr = NULL;

while (node)
{
ptr = starts_with(node->str, prefix);
if (ptr && ((ch == -1) || (*ptr == ch)))
return (node);
node = node->next;
}
return (NULL);
}

/**
*get_node_index - gets node index
*@head: first parameter
*@node: second parameter
*Return: index of node, -1 otherwise
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;

while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}
