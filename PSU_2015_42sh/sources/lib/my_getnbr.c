/*
** my_getnbr.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/lib/my
**
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
**
** Started on  Wed May  4 14:39:36 2016 Maxime Maisonnas
** Last update Wed May 25 15:42:53 2016 Steven Syp
*/

#include "sh.h"

int	my_getnbr(char *str)
{
  int	i;
  int	p;
  int	nb;

  i = my_strlen(str) - 1;
  p = 1;
  nb = 0;
  while (i >= 0)
    {
      nb += ((str[i] - '0') * p);
      p *= 10;
      i--;
    }
  return (nb);
}
