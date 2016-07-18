/*
** epur_str.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/tmp/sources/src
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Mon May 30 13:59:08 2016 Maxime Maisonnas
** Last update Sun Jun  5 16:54:08 2016 Maxime Maisonnas
*/

#include "sh.h"
#include "epur_str.h"

int	getflag(char *new, char *str, int *i, int *j)
{
  int	(*ptr[FSIZE])(char *new, char *str, int *i, int *j);
  char	*flags;
  int	k;

  flags = " \t;|<>&";
  ptr[0] = &f_sp_tab_ptvr;
  ptr[1] = &f_sp_tab_ptvr;
  ptr[2] = &f_sp_tab_ptvr;
  ptr[3] = &f_pipe;
  ptr[4] = &f_chevl;
  ptr[5] = &f_chevr;
  ptr[6] = &f_et_com;
  k = -1;
  while (++k < FSIZE && str[*i] != flags[k]);
  if (k == FSIZE)
    new[(*j)++] = str[(*i)++];
  else
    {
      if (ptr[k](new, str, &*i, &*j))
	return (KO);
    }
  return (OK);
}

char	*epur_str(char *str)
{
  char	*new;
  int	i;
  int	j;

  if (!(new = malloc(my_strlen(str) * 3 + 10)))
    return (NULL);
  i = 0;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == ';' || str[i] == '&')
    i++;
  if (str[i] == '|' || str[i] == '<' || str[i] == '>')
    {
      printerr("Invalid command.\n");
      return (NULL);
    }
  j = 0;
  while (str[i])
    {
      if (getflag(new, str, &i, &j))
  	return (NULL);
    }
  new[j--] = 0;
  while (new[j] == ' ' || new[j] == '\t' || new[j] == ';')
    new[j--] = 0;
  free(str);
  return (analyse_cmd(new));
}
