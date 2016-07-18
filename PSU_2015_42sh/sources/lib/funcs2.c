/*
** funcs2.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/lib/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Wed May 25 16:03:32 2016 Steven Syp
** Last update Sat Jun  4 08:53:35 2016 Steven Syp
*/

#include "sh.h"

int	err_code(char *str, int err)
{
  printerr(str);
  return (err);
}

t_pos	init_pos(int i, int j)
{
  t_pos	p;

  p.i = i;
  p.j = j;
  return (p);
}

char	**malloc_tab(int i, int j)
{
  char	**tab;
  int	k;

  k = 0;
  if ((tab = malloc(sizeof(char *) * i)) == NULL)
    return (NULL);
  while (k < i)
    {
      if ((tab[k++] = malloc(j)) == NULL)
	return (NULL);
    }
  return (tab);
}

void	tab_free(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

char	**my_strtabcpy(char **dest, char **src)
{
  t_pos	p;

  p = init_pos(0, 0);
  while (src[p.i])
    p.i++;
  if ((dest = malloc_tab(p.i + 1, BUFF_LINE)) == NULL)
    return (NULL);
  while (p.j < p.i)
    {
      my_strcpy(dest[p.j], src[p.j]);
      if ((dest[p.j] = my_realloc(dest[p.j], my_strlen(dest[p.j]) + 1))
	  == NULL)
	return (NULL);
      p.j++;
    }
  dest[p.j] = NULL;
  free(src);
  return (dest);
}
