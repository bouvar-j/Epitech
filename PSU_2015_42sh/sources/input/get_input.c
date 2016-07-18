/*
** get_input.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/input/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Fri May 27 14:14:06 2016 Steven Syp
** Last update Wed Jun  8 11:45:09 2016 Maxime Maisonnas
*/

#include "sh.h"

char		*get_input(t_shell *sh)
{
  char		*brut;

  if ((brut = malloc(1)) == NULL)
    return (NULL);
  brut[0] = 0;
  while (!(brut[0]))
    {
      write(1, sh->prompt, sh->prompt_len);
      if (!(brut = gnl(0)))
	{
	  my_putstr("exit\n");
	  exit(0);
	}
      if (!(brut = epur_str(brut)))
	return (NULL);
    }
  return (brut);
}
