#include "palindrome.h"
#include <string.h>
/**
 * is_palindrome - test if a unsigned long int is palindrome or not
 * @n: unsigned long integer
 * Return: 1 if n is palindrome 0 otherwise
 */

int is_palindrome(unsigned long n)
{
char str[20];
int left = 0, right;
sprintf(str, "%ld", n);
right = strlen(str) - 1;
while (left <= right && str[left] == str[right] )
{
left++;
right--;
}
if (left > right)
{
    return(1);
}
else
{
return (0);
}
}
