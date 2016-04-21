/*
** my_put_nbr.c for my_put_nbr in /home/rinaz_a/rendu/Piscine_C_J07/lib/my
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Tue Oct  6 10:26:27 2015 selim rinaz
** Last update Thu Feb 18 14:46:35 2016 selim rinaz
*/

#include "allum1.h"

void	my_put_nbr(int nb)
{
  int	div;
  int	result;

  result = 0;
  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  while ((nb/div) >= 10)
    div = div * 10;
  while (div >= 1)
    {
      result = (nb / div) % 10;
      my_putchar(result + 48);
      div = div / 10;
    }
}
