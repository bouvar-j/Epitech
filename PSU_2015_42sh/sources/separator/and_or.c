/*
** and.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/separator
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Wed Jun  1 17:40:26 2016 Maxime Maisonnas
** Last update Sat Jun  4 15:46:18 2016 Maxime Maisonnas
*/

#include "sh.h"

int		my_and(t_input *com, int r, t_pos id, t_shell *sh)
{
  t_input	*tmp;

  tmp = com;
  if (r == KO && r != -1)
    return (KO);
  while (id.i <= id.j)
    {
      r = my_exec_com(sh, tmp->text, -1, -1);
      if (r == KO || r == FAILURE)
	break ;
      tmp = tmp->next;
      id.i++;
    }
  return (r);
}

int		my_or(t_input *com, int r, t_pos id, t_shell *sh)
{
  t_input	*tmp;

  tmp = com;
  if (r == OK && r != -1)
    return (KO);
  while (++id.i <= id.j)
    {
      r = my_exec_com(sh, tmp->text, -1, -1);
      if (r == OK || r == FAILURE)
	break ;
      tmp = tmp->next;
      id.i++;
    }
  return (r);
}
