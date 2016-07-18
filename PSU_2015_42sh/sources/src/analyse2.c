/*
** analyse2.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/src
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Sun Jun  5 18:01:12 2016 Maxime Maisonnas
** Last update Sun Jun  5 18:44:37 2016 Maxime Maisonnas
*/

#include "sh.h"
#include "epur_str.h"

int	is_separator(char *str)
{
  if (my_strcmp(str, ">") || my_strcmp(str, ">>"))
    return (FREDD);
  if (my_strcmp(str, "<") || my_strcmp(str, "<<"))
    return (FREDG);
  if (my_strcmp(str, "|"))
    return (FPIPE);
  if (my_strcmp(str, "&&") || my_strcmp(str, "||") || my_strcmp(str, ";"))
    return (FSEP);
  return (OK);
}

void	my_err(int flag, int i)
{
  if (flag == FPIPE || flag == FSEP)
    {
      printerr("Invalid null command1.\n");
      return ;
    }
  else if (flag == FREDG)
    printerr((i != 0) ? ("Invalid null command2.\n")
	     : ("Missing name for redirect.\n"));
  else
    printerr((i == 0) ? ("Invalid null command3.\n")
	     : ("Missing name for redirect.\n"));
}

char	*analyse_cmd2(char **tab, char *str)
{
  int	i;
  int	flag;

  i = 0;
  while (tab[i])
    {
      if ((flag = is_separator(tab[i])))
	if (i == 0 || !tab[i + 1] || is_separator(tab[i + 1]))
	  {
	    my_err(flag, i);
	    return (NULL);
	  }
      i++;
    }
  return (str);
}
