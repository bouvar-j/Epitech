/*
** main.c for main in /home/lacroi_m/rendu/CPE_2015_n4s/srcs
**
** Made by maxime lacroix
** Login   <lacroi_m@epitech.net>
**
** Started on  Tue May 24 12:31:21 2016 maxime lacroix
** Last update Mon Jul 18 18:51:27 2016 Julien Bouvard
*/

#include "ia.h"

static int             my_separator(char c, char *str)
{
  while (*str != '\0')
    {
      if (*str == c)
        return (1);
      str = str + 1;
    }
  return (0);
}

static int	my_count(char *str, char *c)
{
  int           i;
  int           cnt;

  i = 0;
  cnt = 0;
  while (str[i] != '\0')
    {
      if (my_separator(str[i], c) == 1)
        cnt++;
      while (my_separator(str[i], c) == 1 && str[i] != '\0')
        i++;
      if (str[i] != '\0')
        i++;
    }
  return (cnt);
}

static char	**fill_tab(char **tab, char *str, char *c)
{
  int           i;
  int           j;
  int           k;

  i = 0;
  j = 0;
  while (i < my_strlen(str))
    {
      k = 0;
      while (my_separator(str[i], c) != 1 && str[i] != '\0')
        {
          tab[j][k] = str[i];
          k++;
          i++;
        }
      while (my_separator(str[i], c) == 1 && str[i] != '\0')
        i++;
      tab[j][k] = '\0';
      j++;
    }
  return (tab);
}

char            **my_str_to_point_tab(char *str, char *c)
{
  char          **tab;
  int           i;
  int           j;
  int           k;

  if (str == NULL)
    return (NULL);
  if ((tab = malloc(sizeof(char *) * (my_count(str, c) + 2))) == NULL)
    return (NULL);
  j = 0;
  i = -1;
  while (i < my_strlen(str))
    {
      k = 0;
      while (my_separator(str[++i], c) != 1 && str[i] != '\0')
        k++;
      while (my_separator(str[i], c) == 1 && str[i] != '\0')
        i++;
      if ((tab[j] = malloc(sizeof(char) * (k + 2))) == NULL)
        return (NULL);
      j++;
    }
  tab[j] = NULL;
  return (fill_tab(tab, str, c));
}

int		*my_tab_to_int_tab(char **tab)
{
  int		*r;
  int		i;
  int		j;

  i = 2;
  j = -1;
  if ((r = malloc(sizeof(int) * 33)) == NULL)
    return (NULL);
  while (tab[++i] && i < 35)
    {
      if ((r[++j] = my_getnbr(tab[i])) == -1)
	return (NULL);
    }
  r[j] = 0;
  return (r);
}
