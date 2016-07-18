/*
** realloc.c for mysh in /home/Maxoulakin/B2/PSU/PSU_2015_minishell2
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Thu Mar 31 12:16:28 2016 Maxime Maisonnas
** Last update Thu Jun  2 15:28:00 2016 Maxime Maisonnas
*/

#include "sh.h"

char	**realloc_env2(char **env, int l)
{
  int	i;
  char	**new;

  i = 0;
  if ((new = malloc(sizeof(char *) * l)) == NULL)
    exit(2);
  while (i < l - 1)
    {
      if ((new[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	exit(2);
      if (i != l - 2)
	new[i] = my_strcpy(new[i], env[i]);
      i++;
    }
  return (new);
}

char	**realloc_env(char **env, int l)
{
  int	i;
  char	**new;

  i = 0;
  if ((new = malloc(sizeof(char *) * l)) == NULL)
    exit(2);
  while (i < l - 1)
    {
      if ((new[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	exit(2);
      new[i] = my_strcpy(new[i], env[i]);
      i++;
    }
  return (new);
}
