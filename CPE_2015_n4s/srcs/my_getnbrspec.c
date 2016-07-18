/*
** my_getnbrspec.c for getnbr in /home/juniqu_v/rendu/CPE_2015_n4s
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sun May 29 22:01:38 2016 virgile junique
** Last update Sun May 29 22:30:35 2016 virgile junique
*/

#include "ia.h"

int	my_getnbr(char *str)
{
  int	nb;

  while (*str == ' ' || *str == '\t')
    str++;
  if (*str == '-')
    return (-1);
  nb = 0;
  while (*str)
    {
      if (*str > '9' || *str < '.')
	return (-1);
      nb = nb * 10 + *str - '0';
      str++;
      if (*str == '.')
	return (nb);
    }
  return (nb);
}
