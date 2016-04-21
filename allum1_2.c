/*
** allum1_2.c for allum1_2 in /home/rinaz_a/rendu/CPE_2015_Allum1
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Thu Feb 18 11:01:16 2016 selim rinaz
** Last update Thu Feb 18 14:45:03 2016 selim rinaz
*/

#include "allum1.h"

int	check_matches(int line, int matches, char **map)
{
  if (matches == 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (-1);
    }
  if ((count_matches(map[line])) < matches)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (-1);
    }
  return (0);
}

int	check_line_ia(int line, char **map)
{
  if (line < 1 || line > 4)
    return (-1);
  else if (count_matches(map[line]) == 0)
    return (-1);
  return (0);
}

int	check_matches_ia(int line, int matches, char **map)
{
  if (matches == 0)
    return (-1);
  if ((count_matches(map[line])) < matches)
    return (-1);
  if ((matches > 1) && (matches == check_matches_remaining(map)))
    return (-1);
  return (0);
}

void   	if_imput(char **av)
{
  my_puterr("allum1 takes no imput like ");
  my_puterr(av[1]);
  my_puterr("\n");
}
