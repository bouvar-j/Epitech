/*
** init_path.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/init/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Thu May 26 10:22:59 2016 Steven Syp
** Last update Mon Jul 18 18:55:06 2016 Julien Bouvard
*/

#include "sh.h"

t_shell		*act_path(t_shell *sh)
{
  clean_path(sh->path_start);
  if ((sh->path = init_path(sh)) == NULL)
    return (NULL);
  return (sh);
}

int		get_path_line(char **env)
{
  int		line;

  line = 0;
  while (env[line])
    {
      if (env[line][0] == 'P' && env[line][1] == 'A' &&
          env[line][2] == 'T' && env[line][3] == 'H' &&
          env[line][4] == '=')
	return (line);
      line++;
    }
  return (-1);
}

t_path		*empty_path(t_path *path)
{
  t_path	*tmp;

  if (!(tmp = malloc(sizeof(t_path))) || !(tmp->file = malloc(10))
      || !(path->file = my_realloc(path->file, 6)))
    exit(1);
  my_strcpy(path->file, "/bin/");
  path->next = tmp;
  my_strcpy(tmp->file, "/usr/bin/");
  return (path);
}

t_path		*copy_path(t_shell *sh, t_pos p, int line)
{
  while (sh->env[line][p.i])
    {
      if (sh->env[line][p.i] == ':')
	{
	  sh->path->file[p.j++] = '/';
	  sh->path->file[p.j] = 0;
	  sh->path = new_path(sh->path);
	  p.i++;
	  p.j = 0;
	}
      sh->path->file[p.j++] = sh->env[line][p.i++];
    }
  sh->path->file[p.j++] = '/';
  sh->path->file[p.j] = 0;
  return (sh->path);
}

t_path		*init_path(t_shell *sh)
{
  t_pos		p;
  int		line;

  p = init_pos(0, 0);
  if ((sh->path = create_path_list()) == NULL)
    return (NULL);
  if ((line = get_path_line(sh->env)) == -1)
    {
      sh->path_start = sh->path;
      return (empty_path(sh->path));
    }
  while (sh->env[line][p.i++] != '=');
  sh->path_start = sh->path;
  sh->path = copy_path(sh, p, line);
  return (sh->path);
}
