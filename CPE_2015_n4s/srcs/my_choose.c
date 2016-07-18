/*
** my_choose.c for my_choose in /home/juniqu_v/rendu/CPE_2015_n4s/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Fri May 27 15:35:55 2016 virgile junique
** Last update Sun May 29 23:34:34 2016 virgile junique
*/

#include "ia.h"

int		my_choose(t_params *p)
{
  int		co;

  co = 0;
  co = ((p->now.l_moy) - (p->now.r_moy));
  if (co > -15 && co < 15)
    write(1, "WHEELS_DIR:0.0\n", 15);
  if (co >= 25 && co <= 100)
    write(1, "WHEELS_DIR:0.8\n", 15);
  if (co <= -25 && co >= -100)
    write(1, "WHEELS_DIR:-0.8\n", 16);
  if (co <= -101 && co >= -200)
    write(1, "WHEELS_DIR:-0.6\n", 15);
  if (co <= 101 && co >= 200)
    write(1, "WHEELS_DIR:0.6\n", 16);
  if (co >= 201 && co <= 300)
    write(1, "WHEELS_DIR:0.5\n", 15);
  if (co >= -201 && co <= -300)
    write(1, "WHEELS_DIR:-0.5\n", 16);
  if (co >= 301 && co <= 400)
    write(1, "WHEELS_DIR:0.4\n", 15);
  if (co >= -301 && co <= -400)
    write(1, "WHEELS_DIR:-0.4\n", 15);
  if (co > 401)
    write(1, "WHEELS_DIR:0.2n", 15);
  if (co < -401)
    write(1, "WHEELS_DIR:-0.2\n", 16);
  return (0);
}
