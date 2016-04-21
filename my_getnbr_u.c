/*
** my_getnbr.c for my_getnbr in /home/rinaz_a/rendu/Piscine_C_J07/lib/my
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Tue Oct  6 11:10:42 2015 selim rinaz
** Last update Thu Feb 18 14:46:21 2016 selim rinaz
*/

#include "allum1.h"

unsigned int	my_getnbr_u(char *str, char *status)
{
  unsigned int	a;
  unsigned int	res;

  res = 0;
  a = 0;
  *status = 0;
  while (str[a])
    {
      if (str[a] < '0' || str[a] > '9')
	{
	  *status = 1;
	  return (0);
	}
      res = res * 10 + (str[a] - 48);
      a = a + 1;
    }
  return (res);
}
