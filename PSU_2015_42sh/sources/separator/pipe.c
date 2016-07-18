/*
** pipe.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/separator
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Fri Jun  3 18:19:55 2016 Maxime Maisonnas
** Last update Wed Jun  8 12:37:41 2016 Maxime Maisonnas
*/

#include "sh.h"

int	my_ids(t_shell *sh, int pfd[2], char **com)
{
  pid_t	cpid;
  int	r;

  if ((cpid = fork()) == -1)
    exit(1);
  wait(&r);
  if (cpid == 0)
    exit(my_exec_com(sh, com, pfd[1], -1));
  return (r);
}

int	my_ide(t_shell *sh, int pfd[2], char **com)
{
  pid_t	cpid;
  int	r;

  close(pfd[1]);
  if ((cpid = fork()) == -1)
    exit(1);
  wait(&r);
  if (cpid == 0)
    exit(my_exec_com(sh, com, -1, pfd[0]));
  close(pfd[0]);
  return (r);
}

int	pipeloop(int pfd[2], t_shell *sh, char **com, int id[2])
{
  int	r;
  int	fds;
  pid_t	cpid;

  if (id[0] == 0)
    r = my_ids(sh, pfd, com);
  else if (id[0] == id[1])
    r = my_ide(sh, pfd, com);
  else
    {
      fds = pfd[0];
      close(pfd[1]);
      if (pipe(pfd) == -1 || (cpid = fork()) == -1)
	exit(1);
      wait(&r);
      if (cpid == 0)
	exit(my_exec_com(sh, com, pfd[1], fds));
      close(fds);
    }
  return (r);
}

int		my_pipe(t_input *com, int ids, int ide, t_shell *sh)
{
  t_input	*tmp;
  int		pfd[2];
  int		id[4];

  tmp = com;
  if (pipe(pfd) == -1)
    exit(1);
  id[0] = ids;
  id[1] = ide;
  id[2] = KO;
  while (id[0] <= id[1])
    {
      id[3] = pipeloop(pfd, sh, tmp->text, id);
      id[0]++;
      if (id[3] && id[2] == OK)
	{
	  printerr(tmp->prec->text[0]);
	  printerr(": write error: Broken pipe\n");
	}
      tmp = tmp->next;
      id[2] = id[3];
    }
  return (OK);
}
