/*
** search.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/src
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Sat Jun  4 21:58:03 2016 Maxime Maisonnas
** Last update Sun Jun  5 14:35:34 2016 Maxime Maisonnas
*/

#include "sh.h"

int	search_pipe(char **com)
{
  int	i;

  i = 0;
  while (com[i])
    {
      if (my_strcmp(com[i], "|"))
	return (KO);
      i++;
    }
  return (OK);
}

int	search_red(char **com)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (com[i])
    {
      if (my_strcmp(com[i], ">") || my_strcmp(com[i], ">>")
	  || my_strcmp(com[i], "<<") || my_strcmp(com[i], "<"))
	nb++;
      i++;
    }
  return (nb);
}
