/*
** my_put_nbr.c for my_put_nbr in /home/maison_m/lib/c_files
** 
** Made by Maxime Maisonnas
** Login   <maison_m@epitech.net>
** 
** Started on  Tue Oct  6 14:11:30 2015 Maxime Maisonnas
** Last update Sat Jun  4 14:44:02 2016 Maxime Maisonnas
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putnbr(int nb)
{
  int	min;

  min = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  nb = -2147483647;
	  min = 1;
	}
      nb = -nb;
    }
  if (nb > 9)
    {
      my_putnbr(nb / 10);
      my_putchar(nb % 10 + 48 + min);
    }
  else if (nb <= 9)
    {
      my_putchar(nb % 10 + 48 + min);
    }
  return (0);
}
