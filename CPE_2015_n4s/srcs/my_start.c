/*
** my_start.c for my_start in /home/juniqu_v/rendu/CPE_2015_n4s/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Thu May 26 15:50:00 2016 virgile junique
** Last update Sun May 29 18:00:21 2016 virgile junique
*/

#include "ia.h"

static int	my_forward(t_params *p)
{
  int		size;
  char		buff[1024];

  size = 0;
  if (write(1, "car_forward:0.2\n", 16) == -1)
    return (my_putstr("Error with write.\n", 2, -1));
  if ((size = read(0, buff, 1023)) < 0)
    return (my_putstr("Error with read.\n", 2, -1));
  buff[size -1] = '\0';
  if (my_strncmp(buff, "1:OK:", 5) != 0)
    return (my_putstr("Error wih car_forward.\n", 2, -1));
  else
    {
      if (p->last_addinfo != NULL)
	free(p->last_addinfo);
      p->last_addinfo = my_strdup("No further info");
    }
  return (0);
}

static int	stop_run(int value, char *message)
{
  int		size;
  char		buff[1024];

  size = 0;
  if (write(1, "stop_simulation\n", 16) == -1)
    return (my_putstr("Error with write.\n", 2, -1));
  if ((size = read(0, buff, 1023)) < 0)
    return (my_putstr("Error with read.\n", 2, -1));
  buff[size -1] = '\0';
  if (my_strncmp(buff, "10:OK:", 6) != 0)
    return (my_putstr("Error with stop_simulation", 2, -1));
  if (value == -1)
    return (my_putstr(message, 2, value));
  else
    return (my_putstr(message, 1, value));
  return (0);
}

int		my_stop(int value, char *message)
{
  int		size;
  char		buff[1024];

  size = 0;
  if (write(1, "car_forward:0\n", 14) == -1)
    return (my_putstr("Error with write.\n", 2, -1));
  if ((size = read(0, buff, 1023)) < 0)
    return (my_putstr("Error with read.\n", 2, -1));
  buff[size - 1] = '\0';
  if (my_strncmp(buff, "1:OK:", 5) != 0)
    return (my_putstr("Error with car_forward:0.\n", 2, -1));
  return (stop_run(value, message));
}

int		my_start(t_params *p)
{
  int		size;
  char		buff[1024];

  size = 0;
  if (write(1, "start_simulation\n", 17) == -1)
    return (my_putstr("Error with write.\n", 2, -1));
  if ((size = read(0, buff, 1023)) < 0)
    return (my_putstr("Error with read.\n", 2, -1));
  buff[size -1] = '\0';
  if (my_strncmp(buff, "1:OK:", 5) != 0)
    return (my_putstr("Error with start_simulation.\n", 2, -1));
  else
    p->last_addinfo = my_strdup("No further info");
  if (my_forward(p) == -1)
    return (-1);
  else
    return (0);
  return (0);
}
