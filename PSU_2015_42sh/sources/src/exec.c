/*
** exec.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/src
**
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
**
** Started on  Thu Jun  2 09:11:57 2016 Maxime Maisonnas
** Last update Sun Jun  5 23:21:41 2016 Maxime Maisonnas
*/

#include "sh.h"

int	ret_exec(int m[3], char **com, char *total, char **env)
{
  if (m[0] == 0)
    {
      printerr(com[0]);
      printerr(": Command not found.\n");
      return (KO);
    }
  else if (m[0] == 1)
    {
      printerr(com[0]);
      printerr(": Permission denied.\n");
      return (KO);
    }
  return (my_exec(total, com, env, m));
}

int		exec_file(char **com, char **env, int m[3])
{
  struct stat	buf;

  stat(com[0], &buf);
  if (access(com[0], F_OK) == -1)
    {
      printerr(com[0]);
      printerr(": Command not found.\n");
      return (KO);
    }
  if (access(com[0], X_OK) == -1 || S_ISDIR(buf.st_mode))
    {
      printerr(com[0]);
      printerr(": Permission denied.\n");
      return (KO);
    }
  return (my_exec(com[0], com, env, m));
}

int		exec_com(char **com, t_shell *sh, int m[3])
{
  t_path	*tmp;
  char		*total;

  if ((com[0][0] == '.' && (com[0][1] == '/'
			    || (com[0][1] == '.' && com[0][2] == '/')))
      || com[0][0] == '/')
    return (exec_file(com, sh->env, m));
  tmp = sh->path_start;
  while (tmp && !m[0])
    {
      if (!(total = my_strcat(tmp->file, com[0])))
        exit(2);
      if (access(total, F_OK) != -1)
  	{
  	  m[0] = 1;
  	  if (access(total, X_OK) != -1)
  	    m[0] = 2;
  	}
      if (!m)
  	free(total);
      tmp = tmp->next;
    }
  return (ret_exec(m, com, total, sh->env));
}

int	exec_all(t_shell *sh, char **com, int m[3])
{
  char	**tmp;
  int	r;

  if ((tmp = search_built_in(com, sh->env, &r, m[1])))
    {
      sh->env = tmp;
      return (OK);
    }
  else if (r == 1)
    return (KO);
  return (exec_com(com, sh, m));
}

int	my_exec_com(t_shell *sh, char **com, int fd1, int fd2)
{
  int	m[3];
  int	nb;

  m[0] = 0;
  m[1] = fd1;
  m[2] = fd2;
  if (search_pipe(com))
    return (exec_pipe(com, sh));
  else if ((nb = search_red(com)))
    return (exec_red(com, sh, m, nb));
  return (exec_all(sh, com, m));
}
