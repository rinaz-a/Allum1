/*
** get_next_line.c for get_next_line in /home/rinaz_a/rendu/CPE_2015_getnextline
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Wed Jan 13 20:48:37 2016 selim rinaz
** Last update Thu Feb 18 14:45:56 2016 selim rinaz
*/

#include <stdlib.h>
#include <unistd.h>
#include "allum1.h"

char		*alloc(int idx, int pos, char *buf, char *line)
{
  char		*new_line;
  int		i;

  i = 0;
  while ((line != NULL) && (line[i] != 0))
    i = i + 1;
  if ((new_line = malloc(i + (idx - pos) + 2)) == NULL)
    return (NULL);
  i = 0;
  while ((line != NULL) && (line[i] != 0) && (i = i + 1))
    new_line[i - 1] = line[i - 1];
  while (pos <= idx)
    {
      if (buf[pos] == '\n')
	new_line[i] = '\0';
      else
	new_line[i] = buf[pos];
      i = i + 1;
      pos = pos + 1;
    }
  new_line[i] = '\0';
  if (line != NULL)
    free(line);
  return (new_line);
}

char	       	*get_next_line(const int fd)
{
  static t_data	data;
  t_tmp	       	tmp;

  tmp.line = 0;
  tmp.kill = 0;
  tmp.pos = data.idx;
  while (tmp.kill == 0)
    {
      if ((data.idx == 0) && ((data.ret = read(fd, data.buf, READ_SIZE)) < 1))
	return (NULL);
      if (((data.buf[data.idx] == '\n') || (data.idx == (data.ret - 1)))
	 && ((tmp.line = alloc(data.idx, tmp.pos, data.buf, tmp.line)) == NULL))
	return (NULL);
      if ((data.buf[data.idx] == '\n')
	  || ((data.ret < READ_SIZE) && (data.idx == (data.ret - 1))))
	tmp.kill = 1;
      if (data.idx != (data.ret - 1))
	data.idx = data.idx + 1;
      else
	{
	  data.idx = 0;
	  tmp.pos = 0;
	}
    }
  return (tmp.line);
}
