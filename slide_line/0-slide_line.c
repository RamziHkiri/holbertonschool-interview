#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "slide_line.h"
int slide_line(int *line, size_t size, int direction)
{
int new_line[size];
int indice;
size_t i;
for (i = 0; i < size ; i++)
new_line[i] = 0;
if (direction == SLIDE_LEFT)
{
indice = 0;
for (i = 0; i < size ; i++)
{
if (line[i] != 0)
{
if (line[i] != new_line[indice])
new_line[indice] = line[i];
else
{
new_line[indice] += line[i];
indice++;
}
}
}
for (i = 0; i < size ; i++)
line[i] = new_line[i];
return (1);
}
else if (direction == SLIDE_RIGHT)
{
indice = size - 1;
for (i = size ; i > 0 ; i--)
{
if (line[i - 1] != 0)
{
if (line[i-1] != new_line[indice])
new_line[indice] = line[i-1];
else
{
new_line[indice] += line[i-1];
indice--;
}
}   
}
for (size_t i = 0; i < size ; i++)
line[i] = new_line[i];
return (1) ;
}
else
{
return (0);
}
}