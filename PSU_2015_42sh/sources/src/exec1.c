/*
** exec.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/src
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Thu Jun  2 09:11:57 2016 Maxime Maisonnas
** Last update Sat Jun  4 18:42:46 2016 Maxime Maisonnas
*/

#include "sh.h"

void	print_err_exec(int s)
{
  if (WIFSIGNALED(s))
    {
      if (WTERMSIG(s) == 11)
	printerr("Segmentation fault\n");
      else if (WTERMSIG(s) == 8)
	printerr("Floating exception\n");
    }
}

int	my_exec(char *total, char **com, char **env, int fd[3])
{
  pid_t	cpid;
  int	s;

  if ((cpid = fork()) == -1)
    exit(2);
  wait(&s);
  if (cpid == 0)
    {
      if (fd[1] != -1)
	if (dup2(fd[1], 1) == -1)
	  exit(3);
      if (fd[2] != -1)
	if (dup2(fd[2], 0) == -1)
	  exit(3);
      execve(total, com, env);
    }
  kill(cpid, 9);
  free(total);
  print_err_exec(s);
  return ((s == 0) ? (OK) : (KO));
}
