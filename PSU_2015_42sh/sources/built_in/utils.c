/*
** utils_cd.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/built_in
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Thu Jun  2 15:53:24 2016 Maxime Maisonnas
** Last update Sat Jun  4 18:47:54 2016 Maxime Maisonnas
*/

#include "sh.h"

char	*my_newstrcpy(char *str, int j, int i)
{
  char	*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 10))) == NULL)
    exit(2);
  while (str[j])
    new[i++] = str[j++];
  new[i] = 0;
  return (new);
}

char	*my_newstrcpy2(char *str, char *str1, int i, int j)
{
  str = my_realloc(str, my_strlen(str1));
  while (str1[j])
    str[i++] = str1[j++];
  str[i] = 0;
  return (str);
}

t_cd	search_home(char **env, t_cd cd)
{
  int   i;

  i = 0;
  while (env[i] && (env[i][0] != 'H' || env[i][1] != 'O' || env[i][2] != 'M'
		    || env[i][3] != 'E' || env[i][4] != '='))
    i++;
  if (!env[i])
    {
      cd.home = NULL;
      return (cd);
    }
  cd.home = my_newstrcpy(env[i], 5, 0);
  cd.h = i;
  return (cd);
}

t_cd	searchenv(char **env)
{
  int	i;
  t_cd	cd;

  i = 0;
  while (env[i] && (env[i][0] != 'O' || env[i][1] != 'L' || env[i][2] != 'D'
		    || env[i][3] != 'P' || env[i][4] != 'W' || env[i][5] != 'D'
		    || env[i][6] != '='))
    i++;
  if (!env[i])
    cd.opwd = NULL;
  else
    cd.opwd = my_newstrcpy(env[i], 7, 0);
  cd.o = i;
  i = 0;
  while (env[i] && (env[i][0] != 'P' || env[i][1] != 'W' || env[i][2] != 'D'
		    || env[i][3] != '='))
    i++;
  if (!env[i])
    cd.pwd = NULL;
  else
    cd.pwd = my_newstrcpy(env[i], 4, 0);
  cd.p = i;
  return (cd);
}
