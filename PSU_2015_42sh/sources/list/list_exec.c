/*
** list_exec.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/sources/list/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Sun Jun  5 09:36:43 2016 Steven Syp
** Last update Sun Jun  5 14:40:26 2016 Steven Syp
*/

#include "sh.h"

t_execution		*create_exec_list(t_execution *prec, t_input *input)
{
  t_execution		*exec;

  if (!input)
    return (NULL);
  if ((exec = malloc(sizeof(t_execution))) == NULL)
    exit(1);
  exec->input = input;
  exec->id = init_pos(0, 0);
  exec->flag = 0;
  exec->r_value = -1;
  exec->next = NULL;
  exec->prec = prec;
  return (exec);
}
