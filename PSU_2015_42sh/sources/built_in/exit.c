/*
** exit.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/built_in
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Thu Jun  2 10:56:00 2016 Maxime Maisonnas
** Last update Sat Jun  4 18:47:10 2016 Maxime Maisonnas
*/

#include "sh.h"

int	my_exit2(char **com)
{
  if (!com[1] || !com[1][0])
    {
      my_putstr("exit\n");
      exit(0);
    }
  if (com[1] && com[2])
    {
      printerr("exit: Expression Syntax.\n");
      return (KO);
    }
  return (OK);
}

char	**my_exit(char **com, char **env)
{
  int   j;

  if (my_exit2(com))
    return (NULL);
  j = 1;
  if (com[1][0] != '-' && (com[1][0] < '0' || com[1][0] > '9'))
    {
      printerr("exit: Expression Syntax.\n");
      return (NULL);
    }
  while (com[1][j])
    {
      if (com[1][j] < '0' || com[1][j] > '9')
	{
	  printerr("exit: Expression Syntax.\n");
	  return (NULL);
	}
      j++;
    }
  my_putstr("exit\n");
  exit(my_getnbr(com[1]));
  return (env);
}
