/*
** utils.c for utils in /home/juniqu_v/rendu/CPE_2015_n4s/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Tue May 24 12:35:19 2016 virgile junique
** Last update Sun May 29 17:46:24 2016 virgile junique
*/

#include "ia.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i++;
  return (i);
}

int	my_putstr(char *str, int fd, int value)
{
  if (write(fd, str, my_strlen(str)) < 0)
    return (-2);
  return (value);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	j;

  i = 0;
  while (s1[i] == s2[i] && s1[i]
	 && s2[i])
    i++;
  if ((n - 1) >= i)
    j = s1[i] - s2[i];
  else
    return (0);
  return (j);
}

char    *my_strdup(char *src)
{
  char  *copy;
  int   i;
  int   len;

  len = my_strlen(src);
  i = 0;
  if (src == NULL || (copy = malloc(len + 1)) == NULL)
    return (NULL);
  while (i < len)
    {
      copy[i] = src[i];
      i = i + 1;
    }
  copy[i] = '\0';
  return (copy);
}

char	*my_strcat(char *dest, char *src)
{
  int   i;
  int   j;
  int   k;
  char  *dest_final;
  int   size;

  size = (my_strlen(dest)) + (my_strlen(src)) + 2;
  k = 0;
  i = 0;
  j = 0;
  if ((dest_final = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (dest[i] != 0)
    {
      dest_final[i] = dest[i];
      i++;
    }
  j = my_strlen(dest);
  while (src[k] != '\0')
    dest_final[j++] = src[k++];
  dest_final[j] = '\0';
  return (dest_final);
}
