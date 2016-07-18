/*
** lib.h for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/include/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Wed May 25 15:02:48 2016 Steven Syp
** Last update Sun Jun  5 15:48:12 2016 Maxime Maisonnas
*/

#ifndef LIB_H_
# define LIB_H_

char	**my_realloc_tab(char **);
void	my_putnbr(int);
char	**my_str_to_word_tab(char *);
void	my_putstr(char *);
int	my_strlen(char *);
void	printerr(char *);
int	my_strcmp(char *, char *);
char	*my_strcpy(char *, char *);
int	my_getnbr(char *);
char	*gnl(int);
char	*gmf(int);
char	*my_realloc(char *, int);
void	print_tab(char **);
int	err_code(char *, int);
char	*my_strcat(char *, char *);
t_pos	init_pos(int, int);
char	**my_strtabcpy(char **, char **);
char	**malloc_tab(int, int);
void	tab_free(char **);

#endif /* !LIB_H_ */
