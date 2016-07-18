/*
** utils.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/separator
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Thu Jun  2 21:24:36 2016 Maxime Maisonnas
** Last update Sun Jun  5 21:35:22 2016 Maxime Maisonnas
*/

#include "sh.h"

int	ret_fd(bool f_create, bool f_append, char *file)
{
  int	fd;

  if (f_create)
    {
      if ((fd = open(file, O_CREAT | O_WRONLY, 0644)) == -1)
        exit(2);
    }
  else if (f_append)
    {
      if ((fd = open(file, O_WRONLY | O_APPEND)) == -1)
        exit(2);
    }
  else
    if ((fd = open(file, O_WRONLY | O_TRUNC)) == -1)
      exit(2);
  return (fd);
}

int	ret_write_fd(bool f_append, char *file)
{
  bool	f_create;
  int	fd;

  f_create = false;
  if (access(file, F_OK) == -1)
    f_create = true;
  if (access(file, W_OK) == -1 && !f_create)
    {
      printerr(file);
      printerr(": Permission denied.\n");
      return (FAILURE);
    }
  fd = ret_fd(f_create, f_append, file);
  return (fd);
}

char	**my_realloc_tab(char **tab)
{
  char	**new;
  int	l;
  int	i;

  l = 0;
  i = 0;
  while (tab[l])
    l++;
  if (!(new = malloc(sizeof(char *) * (l + 1))))
    exit(2);
  while (tab[i])
    {
      if (!(new[i] = malloc(my_strlen(tab[i]) + 1)))
	exit(2);
      new[i] = my_strcpy(new[i], tab[i]);
      i++;
    }
  return (new);
}
