/*
** chevrong1.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/separator
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Sat Jun  4 16:26:54 2016 Maxime Maisonnas
** Last update Sun Jun  5 19:49:37 2016 Maxime Maisonnas
*/

#include "sh.h"

char	**init_tab_entry(char *end)
{
  char	*line;
  char	**tab;
  int	i;

  if (!(tab = malloc(sizeof(char *))))
    exit(2);
  i = 0;
  my_putstr("? ");
  while ((line = gnl(0)) && !my_strcmp(line, end))
    {
      if (!(tab[i] = malloc(my_strlen(line) + 1)))
	exit(2);
      tab[i] = my_strcpy(tab[i], line);
      tab[i + 1] = NULL;
      free(line);
      tab = my_realloc_tab(tab);
      my_putstr("? ");
      i++;
    }
  return (tab);
}

int	my_chevrong2(char **com1, char **com2, t_shell *sh, int fd1)
{
  int	pfd[2];
  char	**tab;
  int	i;
  int	r;

  tab = init_tab_entry(com2[0]);
  if (pipe(pfd) == -1)
    exit(1);
  i = -1;
  while (tab[++i])
    {
      write(pfd[1], tab[i], my_strlen(tab[i]));
      write(pfd[1], "\n", 1);
    }
  close (pfd[1]);
  r = my_exec_com(sh, com1, fd1, pfd[0]);
  close(pfd[0]);
  tab_free(tab);
  return (r);
}

int	my_chevrong11(char *file, char **com1, t_shell *sh, int fd1)
{
  int	fd;
  int	r;
  char	*line;
  int	pfd[2];

  if (pipe(pfd) == -1)
    exit(1);
  if ((fd = open(file, O_RDONLY)) != -1)
    {
      while ((line = gmf(fd)))
	{
	  write(pfd[1], line, my_strlen(line));
	  write(pfd[1], "\n", 1);
	}
      close (pfd[1]);
      r = my_exec_com(sh, com1, fd1, pfd[0]);
      close(pfd[0]);
      close(fd);
      return (r);
    }
  printerr(file);
  printerr(": Permission denied.\n");
  return (KO);
}

int	my_chevrong1(char **com1, char **com2, t_shell *sh, int fd1)
{
  int	r;
  int	i;

  i = 0;
  while (com2[i])
    i++;
  i--;
  if (access(com2[i], F_OK) != -1)
    {
      if ((r = my_chevrong11(com2[i], com1, sh, fd1)))
	return (r);
    }
  else
    {
      printerr(com2[i]);
      printerr(": No such file or directory.\n");
    }
  return (KO);
}
