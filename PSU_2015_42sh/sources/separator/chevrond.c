/*
** chevrond1.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/separator
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Thu Jun  2 21:24:26 2016 Maxime Maisonnas
** Last update Sun Jun  5 23:17:05 2016 Maxime Maisonnas
*/

#include "sh.h"

int	my_chevrond1(char **com1, char **com2, t_shell *sh, int fd0)
{
  int	fd;
  int	r;

  r = 0;
  if ((fd = ret_write_fd(false, com2[0])) == FAILURE)
    return (KO);
  if (my_strcmp(com1[0], "echo"))
    my_echo(com1, sh->env, fd);
  else
    r = my_exec_com(sh, com1, fd, fd0);
  close(fd);
  return (r);
}

int	my_chevrond2(char **com1, char **com2, t_shell *sh, int fd0)
{
  int	fd;
  int	r;

  r = 0;
  if ((fd = ret_write_fd(true, com2[0])) == FAILURE)
    return (KO);
  if (my_strcmp(com1[0], "echo"))
    my_echo(com1, sh->env, fd);
  else
    r = my_exec_com(sh, com1, fd, fd0);
  close(fd);
  return (r);
}
