/*
** typedef.h for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Tue May 24 17:07:01 2016 Steven Syp
** Last update Wed Jun 15 18:49:03 2016 Julien Bouvard
*/

#ifndef TYPEDEF_H_
# define TYPEDEF_H_

typedef struct		s_pos
{
  int			i;
  int			j;
}			t_pos;

typedef struct		s_path
{
  char			*file;
  struct s_path		*prec;
  struct s_path		*next;
}			t_path;

typedef struct		s_cd
{
  char			*home;
  char			*opwd;
  char			*pwd;
  int			h;
  int			o;
  int			p;
}			t_cd;

typedef struct		s_input
{
  char			**text;
  int			id;
  int			flag;
  int			p_flag;
  struct s_input	*prec;
  struct s_input	*next;
}			t_input;

typedef struct		s_execution
{
  struct s_input	*input;
  struct s_pos		id;
  int			flag;
  int			r_value;
  struct s_execution	*prec;
  struct s_execution	*next;
}			t_execution;

typedef struct		s_shell
{
  bool			quit;
  char			*prompt;
  int			prompt_len;
  char			**env;
  struct s_path		*path;
  struct s_path		*path_start;
}			t_shell;

#endif /* !TYPEDEF_H_ */
