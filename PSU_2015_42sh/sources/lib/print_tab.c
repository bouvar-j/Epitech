/*
** print_array.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/lib/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Wed May 25 15:31:03 2016 Steven Syp
** Last update Sun Jun  5 21:27:01 2016 Steven Syp
*/

#include "sh.h"

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  my_putstr("TAB\n---\n");
  while (tab[i])
    {
      my_putstr(tab[i++]);
      my_putstr("\n");
    }
  my_putstr("---\n");
}
