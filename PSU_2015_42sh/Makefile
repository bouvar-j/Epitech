##
## Makefile for My Makefile in /home/syp_s
##
## Made by Steven Syp
## Login   <syp_s@epitech.net>
##
## Started on  Thu Oct 26 12:25:54 2015 Steven Syp
## Last update Sun Jun  5 22:13:21 2016 Maxime Maisonnas
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

SR	= sources/

SRC	= $(SR)src/main.c \
	  $(SR)src/analyse.c \
	  $(SR)src/analyse2.c \
	  $(SR)src/epur_str.c \
	  $(SR)src/epur_str1.c \
	  $(SR)src/search.c \
	  $(SR)src/exec1.c \
	  $(SR)src/exec.c \
	  $(SR)src/exec_sep.c

INIT	= $(SR)init/init_sh.c \
	  $(SR)init/init_env.c \
	  $(SR)init/init_prompt.c \
	  $(SR)init/init_path.c

LIB	= $(SR)lib/gnl.c \
	  $(SR)lib/funcs.c \
	  $(SR)lib/funcs2.c \
	  $(SR)lib/my_getnbr.c \
	  $(SR)lib/my_realloc.c \
	  $(SR)lib/print_tab.c \
	  $(SR)lib/my_putstr.c \
	  $(SR)lib/my_put_nbr.c \
	  $(SR)lib/my_str_to_word_tab.c

BUILTIN	= $(SR)built_in/search.c \
	  $(SR)built_in/exit.c \
	  $(SR)built_in/setenv.c \
	  $(SR)built_in/unsetenv.c \
	  $(SR)built_in/utils.c \
	  $(SR)built_in/my_cd.c \
	  $(SR)built_in/echo.c \
	  $(SR)built_in/realloc.c

INPUT	= $(SR)input/get_input.c \
	  $(SR)input/parse_input_list.c \
	  $(SR)input/exec_cmd.c \
	  $(SR)input/shift_input.c \
	  $(SR)list/list_exec.c \
	  $(SR)list/list_input.c \
	  $(SR)list/list_path.c

SEP	= $(SR)separator/and_or.c \
	  $(SR)separator/utils.c \
	  $(SR)separator/chevrond.c \
	  $(SR)separator/chevrong.c \
	  $(SR)separator/pipe.c

OBJS	= $(SRC:.c=.o) $(LIB:.c=.o) $(INIT:.c=.o) $(INPUT:.c=.o) \
	  $(SEP:.c=.o) $(BUILTIN:.c=.o)

CFLAGS	= -Iinclude -W -Wextra -Wall -ansi -pedantic -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
