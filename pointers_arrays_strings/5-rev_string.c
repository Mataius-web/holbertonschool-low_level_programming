#include "main.h"

/**
 * rev_string - reverse a string
 * @s: string to reverse
 */

void rev_string(char *s)
{
int start;
int end;
char tempo;

start = 0;
end = 0;
while (s[end] != '\0')
{
end++;
}
end--;
while (start < end)
{
tempo = s[start];
s[start] = s[end];
s[end] = tempo;
start++;
end--;
}
}
