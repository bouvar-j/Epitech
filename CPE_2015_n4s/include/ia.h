/*
** ia.h for ia in /home/juniqu_v/rendu/CPE_2015_n4s/include
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Tue May 24 12:37:17 2016 virgile junique
** Last update Sun May 29 23:18:04 2016 virgile junique
*/

#ifndef _IA_H_
# define _IA_H_

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"

typedef struct	s_naverage
{
  int		l_moy;
  int		r_moy;
  int		mid1_moy;
  int		mid2_moy;
}		t_naverage;

typedef struct	s_laverage
{
  int		l_ave;
  int		r_ave;
  int		mid1_ave;
  int		mid2_ave;
}		t_laverage;

typedef struct	s_params
{
  char		*last_addinfo;
  t_laverage	last;
  t_naverage	now;
  int		*lidar;
  int		state;
}		t_params;

int		my_choose(t_params *p);
int		my_getnbr(char *str);
int		my_strncmp(char *s1, char *s2, int n);
int		check_pos(t_params  *p);
char		**my_str_to_point_tab(char *str, char *c);
int		*my_tab_to_int_tab(char **tab);
int		my_start(t_params *p);
int		my_stop(int value, char *message);
int		my_launch(t_params *p);
int		my_strcmp(char *s1, char *s2);
int		my_strlen(char *str);
int		my_putstr(char *str, int fd, int value);
char		*my_strdup(char *src);
int		my_parse(t_params *p);
char		*my_strncat(char *dest, char *src, int n);
char		*my_strndup(char *src, int n);

#endif /* !_IA_H_ */
