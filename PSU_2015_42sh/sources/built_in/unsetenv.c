/*
** unsetenv.c for mysh in /home/Maxoulakin/B2/PSU/PSU_2015_minishell2
**
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
**
** Started on  Thu Mar 31 12:41:30 2016 Maxime Maisonnas
** Last update Sun Jun  5 21:41:48 2016 Steven Syp
*/

#include "sh.h"

char	*ret_name(char *str)
{
  char	*new;
  int	i;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(2);
  i = 0;
  while (str[i] && str[i] != '=')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = 0;
  return (new);
}

char	**modif_env3(char **env, char **new, int i, int k)
{
  while (env[i])
    {
      if ((new[k] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	exit(2);
      new[k] = my_strcpy(new[k], env[i]);
      k++;
      i++;
    }
  return (new);
}

char	**modif_env2(char **env, int j)
{
  int	i;
  int	k;
  char	**new;

  i = 0;
  k = 0;
  while (env[i] != NULL)
    i++;
  if ((new = malloc(sizeof(char *) * i)) == NULL)
    exit(2);
  i = 0;
  while (i < j)
    {
      if ((new[k] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	exit(2);
      new[k] = my_strcpy(new[k], env[i]);
      k++;
      i++;
    }
  i++;
  new = modif_env3(env, new, i, k);
  return (new);
}

char	**my_unsetenv(char **com, char **env)
{
   int	i;
   int	j;
   int	m;

  j = 1;
  if (!com[1])
    {
      printerr("unsetenv: Too few arguments.\n");
      return (NULL);
    }
  while (com[j])
    {
      i = 0;
      m = 0;
      while (env[i] && m == 0)
	{
	  if (my_strcmp(com[j], ret_name(env[i])))
	    m = 1;
	  i++;
	}
      if (m == 1)
	env = modif_env2(env, --i);
      j++;
    }
  return (env);
}
