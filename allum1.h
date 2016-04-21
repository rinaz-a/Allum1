/*
** allum1.h for allum1 in /home/rinaz_a/rendu/CPE_2015_Allum1
** 
** Made by selim rinaz
** Login   <rinaz_a@epitech.net>
** 
** Started on  Tue Feb  9 16:30:29 2016 selim rinaz
** Last update Thu Feb 18 14:45:48 2016 selim rinaz
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

# ifndef READ_SIZE
#  define READ_SIZE (32)
# endif /* !READ_SIZE */

typedef struct	s_data
{
  char		buf[READ_SIZE];
  int		idx;
  int		ret;
}		t_data;

typedef struct	s_tmp
{
  char		*line;
  int		kill;
  int		pos;
}		t_tmp;

void		my_put_nbr(int nb);
char		*get_next_line(const int fd);
char		*alloc(int idx, int pos, char *buf, char *line);
int		my_strlen(char *str);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putstr_2d(char **str);
unsigned int   	my_getnbr_u(char *str, char *status);
char		*my_strdup(char *src);
void		my_puterr(char *str);
int		check_matches_remaining(char **map);
char		**fill_my_map();
char		**remove_these_matches(int line, int matches, char **map);
int		count_matches(char *line);
int		check_line(int line, int stat, char **map);
void		if_imput(char **av);
int		check_matches_ia(int line, int matches, char **map);
int		check_line_ia(int line, char **map);
int		check_matches(int line, int matches, char **map);
char		**play_the_game(char **map);
char		**my_allum_ia(char **map);
char		**my_allum_player(char **map);
int		my_allum_player_2(int line, char **map, int status);
int		main(int ac, char **av);

#endif /* !ALLUM1_H_ */
