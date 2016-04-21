/*
** allum1.c for allum1 in /home/rinaz_a/rendu/CPE_2015_Allum1
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Tue Feb  9 16:48:04 2016 selim rinaz
** Last update Fri Feb 19 17:21:34 2016 selim rinaz
*/

#include <stdlib.h>
#include <time.h>
#include "allum1.h"

int	my_allum_player_2(int line, char **map, int status)
{
  int	matches;
  char	stat;
  char	*str;

  my_putstr("Matches: ");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  matches = my_getnbr_u(str, &stat);
  if (stat == 1 || str[0] == '\0')
    my_putstr("Error: invalid input (positive number expected)\n");
  else if (check_matches(line, matches, map) == 0)
    {
      map = remove_these_matches(line, matches, map);
      my_putstr("Player removed ");
      my_put_nbr(matches);
      my_putstr(" match(es) from line ");
      my_put_nbr(line);
      my_putchar('\n');
      status = 0;
    }
  free(str);
  return (status);
}

char	**my_allum_player(char **map)
{
  int	line;
  char	*str;
  int	status;
  char	stat;

  status = 1;
  my_putstr("Your turn:\n");
  while (status != 0)
    {
      my_putstr("Line: ");
      if ((str = get_next_line(0)) == NULL)
	return (NULL);
      line = my_getnbr_u(str, &stat);
      if (stat == 1 || str[0] == '\0')
	{
	  my_putstr("Error: invalid input (positive number expected)\n");
	  stat = 1;
	}
      free(str);
      if (check_line(line, stat, map) == 0 && stat != 1)
	if ((status = my_allum_player_2(line, map, status)) == -1)
	  return (NULL);
    }
  return (map);
}

char	**my_allum_ia(char **map)
{
  int	line;
  int	matches;
  int	status;

  status = 1;
  my_putstr("AI's turn...\n");
  while (status != 0)
    {
      line = (rand() %4) + 1;
      if (check_line_ia(line, map) == 0)
	{
	  matches = (rand() %(count_matches(map[line]))) + 1;
	  if (check_matches_ia(line, matches, map) == 0)
	    {
	      map = remove_these_matches(line, matches, map);
	      my_putstr("AI removed ");
	      my_put_nbr(matches);
	      my_putstr(" match(es) from line ");
	      my_put_nbr(line);
	      my_putchar('\n');
	      status = 0;
	    }
	}
    }
  return (map);
}

char   	**play_the_game(char **map)
{
  if (check_matches_remaining(map) == 0)
    {
      my_putstr_2d(map);
      my_putstr("You lost, too bad..\n");
      return (0);
    }
  else
    {
      my_putstr_2d(map);
      my_putchar('\n');
    }
  map = my_allum_ia(map);
  if (check_matches_remaining(map) == 0)
    {
      my_putstr_2d(map);
      my_putstr("I lost.. snif.. but I'll get you next time!!\n");
      return (0);
    }
  else
    {
      my_putstr_2d(map);
      my_putchar('\n');
    }
  return (map);
}

int		main(int ac, char **av)
{
  char		**map;
  time_t	t;

  if (ac == 1)
    {
      srand((unsigned) time(&t));
      if ((map = fill_my_map()) == NULL)
	{
	  my_puterr("malloc the map failed\n");
	  return (0);
	}
      my_putstr_2d(map);
      my_putchar('\n');
      while ((check_matches_remaining(map)) > 0)
	{
	  if ((map = my_allum_player(map)) == NULL)
	    return (0);
	  if ((map = play_the_game(map)) == 0)
	    return (0);
	}
    }
  else
    if_imput(av);
  return (0);
}
