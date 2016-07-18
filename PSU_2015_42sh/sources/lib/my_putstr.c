/*
** my_putstr.c for putstr in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/Max/sources
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Mon May 30 15:30:57 2016 Maxime Maisonnas
** Last update Wed Jun  1 16:45:23 2016 Maxime Maisonnas
*/

#include "sh.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(1, &str[i++], 1);
}
