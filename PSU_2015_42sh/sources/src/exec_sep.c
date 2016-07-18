/*
** exec_sep.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/src
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Sun Jun  5 10:54:23 2016 Maxime Maisonnas
** Last update Sun Jun  5 22:00:43 2016 Maxime Maisonnas
*/

#include "sh.h"

t_input		*my_add_elem(char **text, t_input *com, int i, int j)
{
  int		k;
  t_input	*new;

  if (!(new = malloc(sizeof(t_input)))
      || !(new->text = malloc(sizeof(char *) * (j - i))))
    exit(2);
  k = 0;
  while (i < j)
    {
      if (!(new->text[k] = malloc(my_strlen(text[i]) + 1)))
	exit(2);
      new->text[k] = my_strcpy(new->text[k], text[i]);
      i++;
      k++;
    }
  new->text[k] = NULL;
  new->prec = com;
  new->next = NULL;
  if (com)
    com->next = new;
  return (new);
}

int	exec_1red(t_input *tmp, t_shell *sh, int m[3], char *str)
{
  if (my_strcmp(str, ">"))
    return (my_chevrond1(tmp->prec->text, tmp->text, sh, m[2]));
  else if (my_strcmp(str, ">>"))
    return (my_chevrond2(tmp->prec->text, tmp->text, sh, m[2]));
  else if (my_strcmp(str, "<"))
    return (my_chevrong1(tmp->prec->text, tmp->text, sh, m[1]));
  else
    return (my_chevrong2(tmp->prec->text, tmp->text, sh, m[1]));
  return (FAILURE);
}

int	exec_2red(t_input *tmp, t_shell *sh, char *str1, char *str2)
{
  int	fd;

  if (my_strcmp(str1, "<<") || my_strcmp(str1, "<"))
    {
      if ((fd = ret_write_fd((my_strcmp(str2, ">>")) ? (true) : (false),
			     tmp->next->next->text[0])) == FAILURE)
	return (KO);
      if (my_strcmp(str1, "<"))
	return (my_chevrong1(tmp->text, tmp->next->text, sh, fd));
      return (my_chevrong2(tmp->text, tmp->next->text, sh, fd));
    }
  if ((fd = ret_write_fd((my_strcmp(str1, ">>")) ? (true) : (false),
			 tmp->next->text[0])) == FAILURE)
    return (KO);
  if (my_strcmp(str2, "<"))
    return (my_chevrong1(tmp->text, tmp->next->next->text, sh, fd));
  return (my_chevrong2(tmp->text, tmp->next->next->text, sh, fd));
}

int		exec_red(char **com, t_shell *sh, int m[3], int nb)
{
  t_input	*tmp;
  t_pos		p;
  t_pos		s;

  p.i = 0;
  while (!my_strcmp(com[p.i], ">") && !my_strcmp(com[p.i], ">>")
	 && !my_strcmp(com[p.i], "<<") && !my_strcmp(com[p.i], "<"))
    p.i++;
  tmp = my_add_elem(com, NULL, 0, p.i);
  s.i = p.i++;
  p.j = p.i;
  while (com[p.i] && !my_strcmp(com[p.i], ">") && !my_strcmp(com[p.i], ">>")
	 && !my_strcmp(com[p.i], "<<") && !my_strcmp(com[p.i], "<"))
    p.i++;
  tmp = my_add_elem(com, tmp, p.j, p.i);
  if (nb == 1)
    return (exec_1red(tmp, sh, m, com[s.i]));
  s.j = p.i++;
  p.j = p.i;
  while (com[p.i])
    p.i++;
  tmp = my_add_elem(com, tmp, p.j, p.i);
  while (tmp->prec)
    tmp = tmp->prec;
  return (exec_2red(tmp, sh, com[s.i], com[s.j]));
}

int		exec_pipe(char **com, t_shell *sh)
{
  t_input	*tmp;
  int		nb;
  t_pos		p;

  nb = 0;
  tmp = NULL;
  p = init_pos(0, 0);
  while (com[p.i - 1])
    {
      if (my_strcmp(com[p.i], "|") || !com[p.i])
	{
	  tmp = my_add_elem(com, tmp, p.j, p.i);
	  tmp->id = nb;
	  if (com[p.i + 1])
	    p.j = p.i + 1;
	  else
	    p.j = p.i;
	  nb++;
	}
      p.i++;
    }
  while (tmp->prec)
    tmp = tmp->prec;
  return (my_pipe(tmp, 0, --nb, sh));
}
