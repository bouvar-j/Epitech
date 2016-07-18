/*
** shift_input.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/sources/input/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Sun Jun  5 11:23:26 2016 Steven Syp
** Last update Sun Jun  5 21:57:35 2016 Steven Syp
*/

#include "sh.h"

void		set_ids(t_input *input)
{
  t_input	*tmp;
  int		i;

  tmp = input;
  i = 0;
  while (tmp)
    {
      tmp->id = i++;
      tmp = tmp->next;
    }
  return ;
}

t_input		*get_exec_end(t_execution *exec, t_input *input)
{
  while (input->id != exec->id.j)
    {
      input_free(input);
      input = input->next;
    }
  return (input);
}

t_input		*shift_or_input(t_execution *exec, t_input *input)
{
  t_input	*tmp;

  tmp = input;
  if (!exec->r_value)
    {
      while (tmp->flag == 3 || tmp->flag == 2)
	{
	  tmp = tmp->next;
	  input_free(tmp);
	}
    }
  if (!tmp->flag)
    {
      tab_free(tmp->text);
      free(tmp);
      return (NULL);
    }
  else
    {
      tmp = tmp->next;
      input_free(tmp);
      exec->input = tmp;
    }
  set_ids((input = tmp));
  return (input);
}

t_input		*shift_sc_input(t_execution *exec, t_input *input)
{
  t_input	*tmp;

  tmp = input;
  if (!tmp->flag)
    {
      tab_free(tmp->text);
      free(tmp);
      return (NULL);
    }
  else
    {
      tmp = tmp->next;
      input_free(input);
      exec->input = tmp;
    }
  set_ids((input = tmp));
  return (input);
}
