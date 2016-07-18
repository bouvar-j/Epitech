/*
** list_path.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/lists/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Thu May 26 13:35:59 2016 Steven Syp
** Last update Fri Jun  3 17:12:56 2016 Steven Syp
*/

#include "sh.h"

t_path		*new_path(t_path *path)
{
  t_path	*new;

  if ((new = malloc(sizeof(t_path))) == NULL)
    return (NULL);
  if ((new->file = malloc(100)) == NULL)
    return (NULL);
  new->prec = path;
  new->next = NULL;
  path->next = new;
  path = new;
  return (path);
}

void		clean_path(t_path *path)
{
  while (path->next != NULL)
    {
      free(path->file);
      if (path->prec)
	free(path->prec);
      path = path->next;
    }
  free(path->file);
  free(path);
}

t_path		*create_path_list(void)
{
  t_path	*new;

  if ((new = malloc(sizeof(t_path))) == NULL)
    return (NULL);
  if ((new->file = malloc(100)) == NULL)
    return (NULL);
  new->prec = NULL;
  new->next = NULL;
  return (new);
}
