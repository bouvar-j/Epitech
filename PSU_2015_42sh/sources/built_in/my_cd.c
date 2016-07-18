/*
** my_cd.c for mysh in /home/Maxoulakin/B2/PSU/PSU_2015_minishell2
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Tue Mar 29 14:34:31 2016 Maxime Maisonnas
** Last update Mon Jul 18 18:54:31 2016 Julien Bouvard
*/

#include "sh.h"

void	my_chhome(char **env, char *path, t_cd cd)
{
  int	i;

  i = 7;
  while (env[cd.o][i])
    env[cd.o][i++] = 0;
  i = 4;
  while (env[cd.p][i])
    env[cd.p][i++] = 0;
  env[cd.o] = my_newstrcpy2(env[cd.o], cd.pwd, 7, 0);
  i = 0;
  while (env[cd.o][i])
    i++;
  if (env[cd.o][--i] == '/')
    env[cd.o][i] = 0;
  env[cd.p] = my_newstrcpy2(env[cd.p], path, 4, 0);
  chdir(path);
}

void	my_chdir2(char *path, t_cd cd, char **env)
{
  int	i;

  i = 0;
  if (path[0] == '/')
    my_chhome(env, path, cd);
  else
    {
      while (cd.pwd[i])
	i++;
      if (cd.pwd[--i] != '/')
	{
	  cd.pwd = my_realloc(cd.pwd, 1);
	  cd.pwd[++i] = '/';
	}
      my_chhome(env, my_strcat(cd.pwd, path), cd);
    }
}

int	my_chdir3(struct stat buf, char *path, char **env, t_cd cd)
{
  DIR	*dir;

  if (S_ISDIR(buf.st_mode))
    {
      if ((dir = opendir(path)) != NULL)
	{
	  my_chdir2(path, cd, env);
	  closedir(dir);
	  return (OK);
	}
      else
	{
	  printerr(path);
	  printerr(": Permission denied.\n");
	}
    }
  else
    {
      printerr(path);
      printerr(": Not a directory.\n");
    }
  return (KO);
}

int		my_chdir(char **env, char *path, t_cd cd)
{
  struct stat	buf;

  stat(path, &buf);
  if (access(path, F_OK) != -1)
    {
      if (my_chdir3(buf, path, env, cd))
	return (KO);
    }
  else
    {
      printerr(path);
      printerr(": No such file or directory.\n");
      return (KO);
    }
  return (OK);
}

char	**my_cd(char **com, char **env)
{
  t_cd	cd;

  cd = searchenv(env);
  if (!com[1])
    {
      cd = search_home(env, cd);
      if (!cd.home)
	{
	  printerr("cd: No home directory.\n");
	  return (NULL);
	}
      my_chhome(env, cd.home, cd);
      return (env);
    }
  if (my_strcmp(com[1], "-"))
    {
      if (my_chdir(env, cd.opwd, cd))
	return (NULL);
    }
  else
    if (my_chdir(env, com[1], cd))
      return (NULL);
  return (env);
}
