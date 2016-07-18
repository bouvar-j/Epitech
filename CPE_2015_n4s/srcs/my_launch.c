/*
** my_launch.c for launch in /home/juniqu_v/rendu/CPE_2015_n4s/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Thu May 26 15:12:25 2016 virgile junique
** Last update Sun May 29 23:04:54 2016 virgile junique
*/

#include "ia.h"

static void	my_transfer_value(t_params *p)
{
  p->last.l_ave = p->now.l_moy;
  p->last.r_ave = p->now.r_moy;
  p->last.mid1_ave = p->now.mid1_moy;
  p->last.mid2_ave = p->now.mid2_moy;
  p->now.l_moy = 0;
  p->now.r_moy = 0;
  p->now.mid1_moy = 0;
  p->now.mid2_moy = 0;
}

int		my_launch(t_params *p)
{
    if (my_start(p) == -1)
    return (-1);
  while (my_strcmp(p->last_addinfo, "Track clear") != 0)
    {
      if (p->state == 1)
	my_transfer_value(p);
      else
	p->state = 1;
      if ((check_pos(p)) == -1)
	return (my_stop(-1, "Error with LIDAR.\n"));
      if (my_parse(p) == -1)
	return (my_stop(-1, "You are in an impasse.\n"));
      if (my_choose(p) == -1)
	return (my_stop(-1, "Error during travel sorry i'm bad.\n"));
    }
  return (my_stop(0, "You win the Track nice, thanks and goodbye.\n"));
}
