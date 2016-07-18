/*
** utils2.c for utils2 in /home/juniqu_v/rendu/CPE_2015_n4s/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Thu May 26 16:38:12 2016 virgile junique
** Last update Sun May 29 23:19:33 2016 virgile junique
*/

#include "ia.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] != '\0')
    {
      if ((s1[i] != s2[i]) || s1 == '\0' || s2 == '\0')
        return (1);
      i = i + 1;
    }
  return (0);
}
