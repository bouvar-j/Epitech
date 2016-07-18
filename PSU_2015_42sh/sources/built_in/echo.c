/*
** echo.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/built_in
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Thu Jun  2 17:06:22 2016 Maxime Maisonnas
** Last update Sun Jun  5 23:14:16 2016 Maxime Maisonnas
*/

#include "sh.h"

char	*ret_fp_env(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!(new = malloc(my_strlen(str) + 1)))
    exit(1);
  while (str[i] && str[i] != '=')
    new[j++] = str[i++];
  new[j] = 0;
  return (new);
}

char	*ret_sp_env(char *str)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!(new = malloc(my_strlen(str) + 1)))
    exit(1);
  while (str[i] && str[i] != '=')
    i++;
  if (str[i])
    i++;
  while (str[i])
    new[j++] = str[i++];
  new[j] = 0;
  return (new);
}

int	is_good(char *tmp, char *str, int fd, char *str1)
{

  if (my_strcmp(tmp, str))
    {
      free(tmp);
      tmp = ret_sp_env(str1);
      write(fd, tmp, my_strlen(tmp));
      free(tmp);
      return (OK);
    }
  return (KO);
}

int	search_in_env(char *str, char **env, int fd)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  while (str[i] == '$')
    i++;
  while (str[i])
    str[j++] = str[i++];
  str[j] = 0;
  while (env[i])
    {
      tmp = ret_fp_env(env[i]);
      if (!is_good(tmp, str, fd, env[i]))
	return (OK);
      free(tmp);
      i++;
    }
  printerr(str);
  printerr(": Undefined variable.\n");
  return (KO);
}

char	**my_echo(char **com, char **env, int fd)
{
  int	i;

  if (fd == -1)
    fd = 1;
  i = 1;
  while (com[i])
    {
      if (com[i][0] == '$')
	{
	  if (search_in_env(com[i], env, fd))
	    return (NULL);
	}
      else
	write(fd, com[i], my_strlen(com[i]));
      i++;
      if (com[i])
	write(fd, " ", 1);
    }
  write(fd, "\n", 1);
  return (env);
}
