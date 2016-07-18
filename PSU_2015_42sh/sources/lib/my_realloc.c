/*
** my_realloc.c for realloc in /home/maison_m/lib/my
**
** Made by Maxime Maisonnas
** Login   <maison_m@epitech.net>
**
** Started on  Mon Jan 18 13:15:32 2016 Maxime Maisonnas
** Last update Thu Jun  2 10:46:26 2016 Maxime Maisonnas
*/

#include "sh.h"

char	*my_realloc(char *str, int size)
{
  char	*new;
  int	l;
  int	i;

  i = 0;
  l = my_strlen(str);
  if ((new = malloc(sizeof(char) * (l + size + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      new[i] = str[i];
      i++;
    }
  new[i] = 0;
  free(str);
  return (new);
}
