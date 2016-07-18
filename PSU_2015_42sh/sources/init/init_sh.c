/*
** init_sh.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Wed May 25 14:36:05 2016 Steven Syp
** Last update Mon Jul 18 18:55:24 2016 Julien Bouvard
*/

#include "sh.h"

t_shell		*init_sh(char **env)
{
  t_shell	*sh;

  if ((sh = malloc(sizeof(t_shell))) == NULL)
    return (NULL);
  sh->quit = false;
  if ((sh->env = init_env(env)) == NULL)
    return (NULL);
  if ((sh->prompt = init_prompt(sh)) == NULL)
    return (NULL);
  if ((sh->path = init_path(sh)) == NULL)
    return (NULL);
  return (sh);
}
