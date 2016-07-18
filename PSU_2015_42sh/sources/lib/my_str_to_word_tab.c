/*
** my_str_to_word_tab.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/lib
**
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
**
** Started on  Wed Jun  1 16:57:43 2016 Maxime Maisonnas
** Last update Tue Jun 14 13:50:53 2016 Julien Bouvard
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	count_nb_space(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i])
    if (str[i++] == ' ')
      nb++;
  return (++nb);
}

int	count_char(char *str, int j)
{
  int	nb;

  nb = 0;
  while (str[j] && str[j] != ' ')
    {
      nb++;
      j++;
    }
  return (nb);
}

char	**my_str_to_word_tab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if (!(tab = malloc(sizeof(char *) * (count_nb_space(str) + 1))))
    exit(1);
  while (str[j])
    {
      if (!(tab[i] = malloc(count_char(str, j) + 1)))
	exit(1);
      k = 0;
      while (str[j] && str[j] != ' ')
	tab[i][k++] = str[j++];
      if (str[j] == ' ')
	j++;
      tab[i++][k] = 0;
    }
  tab[i] = NULL;
  return (tab);
}

/*int     main(int ac, char **av)
{
  char  **str;
  int   i;
 
  i = 0;
  str = my_str_to_word_tab(av[1]);
  while (str[i])
    {
      printf("str[%d] = %s\n", i, str[i]);
      i++;
    }
    }*/
