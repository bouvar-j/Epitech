/*
** parse_input_list.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/input/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Mon May 30 11:50:33 2016 Steven Syp
** Last update Wed Jun  8 11:45:55 2016 Steven Syp
*/

#include "sh.h"

int		is_sep(char *brut, int *i)
{
  if (brut[*i] == ';')
    {
      *i += 2;
      return (1);
    }
  if (brut[*i + 1])
    {
      if ((brut[*i] == '&' && brut[*i + 1] == '&') ||
	  (brut[*i] == '|' && brut[*i + 1] == '|'))
	{
	  *i += 3;
	  if (brut[*i - 3] == '&')
	    return (2);
	  else
	    return (3);
	}
    }
  return (-1);
}

char		*shift_brut(char *brut, int j)
{
  int		i;

  i = 0;
  while (brut[j])
    brut[i++] = brut[j++];
  brut[i] = 0;
  return (brut);
}

char		*get_cmd(char *cmd, char *brut, int *flag)
{
  t_pos		p;

  p = init_pos(0, 0);
  if ((cmd = malloc(my_strlen(brut))) == NULL)
    return (NULL);
  while (brut[p.i])
    {
      if ((*flag = is_sep(brut, &p.i)) != -1)
	break ;
      cmd[p.i] = brut[p.i];
      p.i++;
    }
  cmd[p.i] = 0;
  if (!brut[p.i])
    {
      *flag = 0;
      brut[0] = 0;
      return (cmd);
    }
  brut = shift_brut(brut, p.i);
  cmd = epur_str(cmd);
  return (cmd);
}

void		empty_cmd(char *cmd)
{
  t_pos		p;

  p = init_pos(0, my_strlen(cmd));
  while (p.i < p.j)
    cmd[p.i++] = 0;
  cmd[p.i] = 0;
  return ;
}

t_input		*parse_input_list(char *brut)
{
  t_input	*input;
  t_input	*new;
  char		*cmd;

  if ((input = init_input(NULL)) == NULL)
    return (NULL);
  new = input;
  while (new->flag != 0)
    {
      if ((cmd = get_cmd(cmd, brut, &new->flag)) == NULL)
	return (NULL);
      if ((new->text = my_str_to_word_tab(cmd)) == NULL)
	return (NULL);
      if (new->flag != 0)
	if ((new = create_input_list(new)) == NULL)
	  return (NULL);
      if (new->prec != NULL)
	{
	  empty_cmd(cmd);
	  free(cmd);
	}
    }
  new = input;
  return (input);
}
