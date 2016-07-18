/*
** gnl.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/lib/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Fri May 27 15:11:02 2016 Steven Syp
** Last update Sun Jun  5 15:47:50 2016 Maxime Maisonnas
*/

#include "sh.h"

char	*gnl(int fd)
{
  char	*line;
  int	r;
  int	i;
  char	buff[1];

  i = 0;
  if ((line = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  r = read(fd, buff, 1);
  if (r == 0)
    return (NULL);
  while (r != 0 && buff[0] != '\n')
    {
      line = my_realloc(line, 1);
      line[i] = buff[0];
      line[++i] = 0;
      r = read(fd, buff, 1);
    }
  line[i] = 0;
  return (line);
}

char	*gmf(int fd)
{
  char	*line;
  int	r;
  int	i;
  char	buff[1];

  i = 0;
  if ((line = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  r = read(fd, buff, 1);
  if (r == 0)
    return (NULL);
  while (r != 0)
    {
      line = my_realloc(line, 1);
      line[i] = buff[0];
      line[++i] = 0;
      r = read(fd, buff, 1);
    }
  line[i] = 0;
  return (line);
}
