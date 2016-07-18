/*
** main.c for main in /home/juniqu_v/rendu/CPE_2015_n4s/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Tue May 24 12:31:21 2016 virgile junique
** Last update Thu May 26 15:22:04 2016 virgile junique
*/

#include "ia.h"

static void	my_init(t_params *p)
{
  p->state = 0;
  p->last_addinfo = 0;
  p->lidar = 0;
  p->now.l_moy = 0;
  p->now.r_moy = 0;
  p->now.mid1_moy = 0;
  p->now.mid2_moy = 0;
  p->last.l_ave = 0;
  p->last.r_ave =0;
  p->last.mid1_ave = 0;
  p->last.mid2_ave = 0;
}

int		main(int ac, char **av)
{
  t_params	p;

  (void)av;
  if (ac == 1)
    {
      my_init(&p);
      if (my_launch(&p) == -1)
	return (-1);
      else
	return (0);
    }
  else
    return (my_putstr("Usage: ./ia.\n", 2, -1));
}
