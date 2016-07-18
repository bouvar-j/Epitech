/*
** sh.h for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/include/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Wed Jun  1 18:36:13 2016 Steven Syp
** Last update Sun Jun  5 22:46:04 2016 Maxime Maisonnas
*/

#ifndef SH_H_
# define SH_H_

# include <dirent.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "typedef.h"
# include "lib.h"

# ifndef OK
#  define OK	0
# endif /* !OK */

# ifndef KO
#  define KO	1
# endif /* !KO */

# ifndef FAILURE
#  define FAILURE	-1
# endif /* !FAILURE */

# ifndef BUFF_LINE
#  define BUFF_LINE	200
# endif /* !BUFF_LINE */

int		kill(pid_t pid, int sig);
int		exec_pipe(char **, t_shell *);
int		exec_red(char **com, t_shell *sh, int m[3], int nb);
int		search_pipe(char **);
int		search_red(char **);
char		*my_newstrcpy2(char *, char *, int, int);
int		my_exec(char *total, char **com, char **env, int fd[3]);
int		my_pipe(t_input *, int, int, t_shell *);
int		my_chevrong1(char **, char **, t_shell *, int);
int		my_chevrong2(char **, char **, t_shell *, int);
int		my_chevrond1(char **, char **, t_shell *, int);
int		my_chevrond2(char **, char **, t_shell *, int);
int		ret_write_fd(bool, char *);
int		my_exec_com(t_shell *, char **, int, int);
t_cd		searchenv(char **);
t_cd		search_home(char **, t_cd);
char		**my_cd(char **, char **);
char		**my_echo(char **, char **, int);
char		*ret_name(char *);
char		**realloc_env2(char **, int);
char		**realloc_env(char **, int);
char		**my_setenv(char **, char **);
char		**my_unsetenv(char **, char **);
char		**my_exit(char **, char **);
char		**search_built_in(char **, char **, int *, int);
t_shell		*init_sh(char **);
char		*init_prompt(t_shell *);
t_path		*init_path(t_shell *);
char		**init_env(char **);
t_path		*new_path(t_path *);
t_path		*create_path_list(void);
t_shell		*config_file(t_shell *);
char		*epur_str(char *);
char		*get_input(t_shell *);
t_input		*parse_input_list(char *);
int		my_and(t_input *, int, t_pos, t_shell *);
int		my_or(t_input *, int, t_pos, t_shell *);
t_input		*init_input(t_input *);
t_input		*create_input_list(t_input *);
t_shell		*act_path(t_shell *);
void		clean_path(t_path *);
void		exec_cmd(t_shell *, t_input *);
t_execution	*create_exec_list(t_execution *, t_input *);
t_input		*shift_or_input(t_execution *, t_input *);
t_input		*shift_sc_input(t_execution *, t_input *);
void		input_free(t_input *);

#endif /* !SH_H_ */
