##
## Makefile for Makefile in /home/rinaz_a/rendu/PSU_2015_my_select
## 
## Made by selim rinaz
## Login   <rinaz_a@epitech.net>
## 
## Started on  Fri Dec  4 16:34:29 2015 selim rinaz
## Last update Thu Feb 18 11:42:51 2016 
##

CC	= gcc -g

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
#CFLAGS	+=-ansi -pedantic
#CFLAGS	+= -I.

NAME	= allum1

SRCS	= my_essentials.c	\
	  get_next_line.c	\
	  my_getnbr_u.c		\
	  my_put_nbr.c		\
	  my_strdup.c		\
	  allum1_3.c		\
	  allum1_2.c		\
	  allum1.c

OBJS	= $(SRCS:.c=.o)


all: 	$(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
