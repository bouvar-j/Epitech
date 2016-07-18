/*
** list_input.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/sources/list/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Thu Jun  2 15:43:30 2016 Steven Syp
** Last update Sun Jun  5 20:41:37 2016 Steven Syp
*/

#include "sh.h"

void		input_free(t_input *input)
{
  if (input->prec)
    {
      if (input->prec->text)
	tab_free(input->prec->text);
      free(input->prec);
    }
  input->prec = NULL;
}

t_input		*init_input(t_input *input)
{
  if ((input = malloc(sizeof(t_input))) == NULL)
    return (NULL);
  input->flag = -1;
  input->id = 0;
  input->prec = NULL;
  input->next = NULL;
  return (input);
}

t_input		*create_input_list(t_input *input)
{
  t_input	*new;

  if ((new = malloc(sizeof(t_input))) == NULL)
    return (NULL);
  new->flag = -1;
  new->id = input->id + 1;
  new->prec = input;
  new->next = NULL;
  input->next = new;
  input = new;
  return (input);
}
