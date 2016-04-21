/*
** my_strdup.c for my_strdup in /home/rinaz_a/rendu/Piscine_C_J08/ex_01
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Wed Oct  7 11:38:38 2015 selim rinaz
** Last update Thu Feb 18 14:46:58 2016 selim rinaz
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;
  int	length;
  char	*dest;

  length = 0;
  i = 0;
  while (src[length] != 0)
    length = length + 1;
  if ((dest = malloc(length + 1)) == NULL)
    return (NULL);
  while (src[i++] != 0)
    dest[i - 1] = src[i - 1];
  dest[i - 1] = '\0';
  return (dest);
}
