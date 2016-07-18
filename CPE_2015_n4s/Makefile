##
## Makefile for  in /home/juniqu_v/rendu/CPE_2015_n4s
## 
## Made by virgile junique
## Login   <juniqu_v@epitech.net>
## 
## Started on  Tue May 24 12:28:59 2016 virgile junique
## Last update Sun May 29 23:38:32 2016 virgile junique
##

CC	= cc

CFLAGS	+= -W -Wall -Werror -Iinclude -lm

RM	= rm -f

NAME	= ia

SRCS	= $(addprefix srcs/, \
	    my_tab_to_int_tab.c \
	    my_getnbrspec.c \
	    my_choose.c \
	    utils2.c \
	    utils.c \
	    parse.c \
	    main.c \
	    my_launch.c \
	    get_next_line.c \
	    my_start.c )

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
