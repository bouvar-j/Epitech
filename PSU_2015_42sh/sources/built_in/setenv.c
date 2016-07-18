/*
** setenv.c for mysh in /home/Maxoulakin/B2/PSU/PSU_2015_minishell2
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Wed Mar 30 14:26:34 2016 Maxime Maisonnas
** Last update Thu Jun  2 21:10:10 2016 Maxime Maisonnas
*/

#include "sh.h"

char	**modif_env(char **env, int i, char *name, char *value)
{
  int	j;

  j = 0;
  if (!env[i])
    env = realloc_env2(env, i + 2);
  else
    while (env[i][j])
      env[i][j++] = 0;
  if (!(name = my_realloc(name, 1)))
    exit(2);
  j = 0;
  while (name[j])
    j++;
  name[j] = '=';
  name[++j] = 0;
  if (value)
    env[i] = my_strcat(name, value);
  else
    env[i] = name;
  return (env);
}

int	search_error2(char **com)
{
  int	i;

  i = -1;
  while (com[1][++i])
    if ((com[1][i] < '0' || (com[1][i] > '9' && com[1][i] < 'A')
	 || (com[1][i] > 'Z' && com[1][i] < 'a')
	 || com[1][i] > 'z') && com[1][i] != '_')
      {
	printerr("setenv: Variable name must contain alphanumeric\
 characters.\n");
	return (KO);
      }
  return (OK);
}

int	search_error(char **com)
{
  if (com[1])
    if (com[2])
      if (com[3])
	{
	  printerr("setenv: Too many arguments.\n");
	  return (KO);
	}
  return (OK);
}

int	search_error3(char **com, char **env)
{
  int	i;

  i = 0;
  if (!com[1])
    {
      while (env[i])
	{
	  my_putstr(env[i++]);
	  my_putstr("\n");
	}
      return (KO);
    }
  return (OK);
}

char	**my_setenv(char **com, char **env)
{
  int	i;
  int	m;

  if (search_error3(com, env))
    return (env);
  if (search_error(com) || search_error2(com))
    return (NULL);
  i = 0;
  m = 0;
  while (env[i] && m == 0)
    {
      if (my_strcmp(com[1], ret_name(env[i])))
  	m = 1;
      i++;
    }
  if (m == 1)
    env = modif_env(env, --i, com[1], com[2]);
  else
    {
      i = 0;
      while (env[i])
  	i++;
      env = modif_env(env, i, com[1], com[2]);
    }
  return (env);
}
