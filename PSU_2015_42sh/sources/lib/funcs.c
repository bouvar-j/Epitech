/*
** lib1.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/lib/my
**
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
**
** Started on  Wed May  4 14:32:54 2016 Maxime Maisonnas
** Last update Thu Jun  2 15:31:11 2016 Maxime Maisonnas
*/

#include "sh.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (151);
  while (str[i])
    i++;
  return (i);
}

void	printerr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(2, &str[i++], 1);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (my_strlen(str1) != my_strlen(str2))
    return (0);
  while (str1[i] && str2[i])
    {
      if (str1[i] != str2[i])
	return (0);
      i++;
    }
  return (1);
}

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*new;

  i = 0;
  j = 0;
  if ((new = malloc(my_strlen(str1) + my_strlen(str2) + 1)) == NULL)
    return (NULL);
  while (str1[i])
    new[j++] = str1[i++];
  i = 0;
  while (str2[i])
    new[j++] = str2[i++];
  new[j] = 0;
  return (new);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
