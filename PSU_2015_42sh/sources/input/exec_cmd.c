/*
** exec_cmd.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/sources/input/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Fri Jun  3 18:38:24 2016 Steven Syp
** Last update Wed Jun  8 11:10:13 2016 Maxime Maisonnas
*/

#include "sh.h"

void		get_exec_input(t_execution *exec, t_input *input)
{
  while (input->flag == 2)
    input = input->next;
  exec->id = init_pos(0, input->id);
  exec->flag = input->flag;
  return ;
}

t_input		*shift_input(t_execution *exec, t_input *input)
{
  while (input->id != exec->id.j)
    {
      input_free(input);
      if (!input->flag)
	return (NULL);
      input = input->next;
    }
  return (input);
}

void		exec_cmd(t_shell *sh, t_input *input)
{
  t_execution	*exec;

  exec = create_exec_list(NULL, input);
  while (input)
    {
      get_exec_input(exec, input);
      exec->r_value = ((exec->id.i == exec->id.j) ?
		       (my_exec_com(sh, exec->input->text, -1, -1)) :
		       (my_and(input, exec->r_value, exec->id, sh)));
      if (!(input = shift_input(exec, input)))
	return ;
      if (!exec->flag)
	return ;
      else if (exec->flag == 1)
	{
	  input = shift_sc_input(exec, input);
	  exec = create_exec_list(exec, input);
	}
      else
	{
	  input = shift_or_input(exec, input);
	  exec = create_exec_list(exec, input);
	}
    }
}
