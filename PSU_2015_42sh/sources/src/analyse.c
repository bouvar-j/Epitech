/*
** analyse.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/src
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Sun Jun  5 16:09:49 2016 Maxime Maisonnas
** Last update Sun Jun  5 18:23:37 2016 Maxime Maisonnas
*/

#include "sh.h"
#include "epur_str.h"

int	check_redd(char *str, int *flag)
{
  if ((my_strcmp(str, ">") || my_strcmp(str, ">>")) && *flag)
    {
      if (*flag == FREDD)
	{
	  printerr("Ambiguous output redirect.\n");
	  return (KO);
	}
      *flag = FREDD;
    }
  else if (my_strcmp(str, ">") || my_strcmp(str, ">>"))
    *flag = FREDD;
  return (OK);
}

int	check_pipe(char *str, int *flag)
{
  if (my_strcmp(str, "|") && *flag)
    {
      if (*flag == FREDD)
	{
	  printerr("Ambiguous output redirect.\n");
	  return (KO);
	}
      *flag = FPIPE;
    }
  else if (my_strcmp(str, "|"))
    *flag = FPIPE;
  return (OK);
}

int	check_redg(char *str, int *flag)
{
  if ((my_strcmp(str, "<") || my_strcmp(str, "<<")) && *flag)
    {
      if (*flag != FREDD)
	{
	  printerr("Ambiguous input redirect.\n");
	  return (KO);
	}
      *flag = FREDG;
    }
  else if (my_strcmp(str, "<") || my_strcmp(str, "<<"))
    *flag = FREDG;
  return (OK);
}

char	*analyse_cmd(char *str)
{
  int	flag;
  char	**tab;
  int	i;

  flag = 0;
  tab = my_str_to_word_tab(str);
  i = 0;
  while (tab[i])
    {
      if (my_strcmp(tab[i], ";") || my_strcmp(tab[i], "&&")
	  || my_strcmp(tab[i], "||"))
	flag = 0;
      if (check_redd(tab[i], &flag))
	return (NULL);
      if (check_redg(tab[i], &flag))
	return (NULL);
      if (check_pipe(tab[i], &flag))
	return (NULL);
      i++;
    }
  str = analyse_cmd2(tab, str);
  tab_free(tab);
  return (str);
}
