/*
** allum1_3.c for allum1_3 in /home/rinaz_a/rendu/CPE_2015_Allum1
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Thu Feb 18 11:04:11 2016 selim rinaz
** Last update Thu Feb 18 14:45:13 2016 selim rinaz
*/

#include <stdlib.h>
#include "allum1.h"

int	check_matches_remaining(char **map)
{
  int	idx[2];
  int	matches;

  idx[0] = 0;
  idx[1] = 0;
  matches = 0;
  while (map[idx[0]] != NULL)
    {
      while (map[idx[0]][idx[1]] != '\0')
	{
	  if (map[idx[0]][idx[1]] == '|')
	    matches++;
	  idx[1]++;
	}
      idx[1] = 0;
      idx[0]++;
    }
  return (matches);
}

char	**fill_my_map()
{
  char	**map;

  if ((map = malloc(sizeof(char*) * 7)) == NULL)
    return (NULL);
  if ((map[0] = my_strdup("*********")) == NULL)
    return (NULL);
  if ((map[1] = my_strdup("*   |   *")) == NULL)
    return (NULL);
  if ((map[2] = my_strdup("*  |||  *")) == NULL)
    return (NULL);
  if ((map[3] = my_strdup("* ||||| *")) == NULL)
    return (NULL);
  if ((map[4] = my_strdup("*|||||||*")) == NULL)
    return (NULL);
  if ((map[5] = my_strdup("*********")) == NULL)
    return (NULL);
  map[6] = NULL;
  return (map);
}

char	**remove_these_matches(int line, int matches, char **map)
{
  int	idx;

  idx = my_strlen(map[line]);
  while ((idx > 0) && (matches > 0))
    {
      if (map[line][idx] == '|')
	{
	  map[line][idx] = ' ';
	  matches--;
	}
      idx--;
    }
  return (map);
}

int	count_matches(char *line)
{
  int	idx;
  int	matches;

  matches = 0;
  idx = 0;
  while (line[idx] != '\0')
    {
      if (line[idx] == '|')
	matches++;
      idx++;
    }
  return (matches);
}

int	check_line(int line, int stat, char **map)
{
  if ((stat != 1 && line < 1) || (line > 4 && stat != 1))
    {
      my_putstr("Error: this line is out of range\n");
      return (-1);
    }
  else if (stat != 1 && count_matches(map[line]) == 0)
    {
      my_putstr("Error: this line is empty\n");
      return (-1);
    }
  return (0);
}
