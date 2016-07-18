/*
** my_parse for my_parse in /home/lacroi_m/rendu/CPE_2015_n4s/srcs
**
** Made by maxime lacroix
** Login   <lacroi_m@epitech.net>
**
** Started on  Tue May 24 12:31:21 2016 maxime lacroix
** Last update Sun May 29 23:37:51 2016 virgile junique
*/

#include <stdio.h>
#include "ia.h"
#include "get_next_line.h"

static void	fill_struc(t_params *p)
{
  int		i;
  int		nb;

  i = 1;
  nb = 0;
  nb = p->lidar[0];
  while (i++ < 17)
      nb = nb + p->lidar[i];
  p->now.mid1_moy = p->lidar[16];
  p->now.mid2_moy = p->lidar[17];
  p->now.l_moy = nb / 16;
  nb = p->lidar[17];
  while (i++ < 32)
    nb = nb + p->lidar[i];
  p->now.r_moy = nb / 16;
  free(p->lidar);
}

int		check_pos(t_params  *p)
{
  char		**tab;
  char		*str;
  int		i;

  i = -1;
  if (write(1, "GET_INFO_LIDAR\n", 15) == -1)
    return (my_putstr("Error with write\n", 2, -1));
  str = get_next_line(0);
  if (my_strncmp(str, "1:OK:", 5) != 0
      || (tab = my_str_to_point_tab(str, ":")) == NULL)
    return (-1);
  p->lidar = my_tab_to_int_tab(tab);
  free(str);
  p->last_addinfo = my_strdup(tab[35]);
  while (tab[++i])
    free(tab[i]);
  free(tab);
  return (0);
}

int	my_parse(t_params *p)
{
  fill_struc(p);
  if (p->now.mid1_moy <= 800
      && p->now.mid2_moy <= 800
      && p->now.l_moy <= 800
      && p->now.r_moy <= 800)
    return (-1);
  return (0);
}
