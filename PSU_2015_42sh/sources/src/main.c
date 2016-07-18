/*
** main.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Wed May 25 14:28:38 2016 Steven Syp
** Last update Sun Jun  5 22:38:07 2016 Maxime Maisonnas
*/

#include "sh.h"

int		main(int ac, char **av, char **env)
{
  t_shell	*sh;
  t_input	*input;
  char		*brut;

  (void)ac;
  (void)av;
  if ((sh = init_sh(env)) == NULL)
    return (err_code(NULL, FAILURE));
  while (!sh->quit)
    {
      if ((brut = get_input(sh)) != NULL)
	{
	  if ((input = parse_input_list(brut)) == NULL)
	    return (err_code(NULL, FAILURE));
	  exec_cmd(sh, input);
	  if ((sh = act_path(sh)) == NULL)
	     return (err_code(NULL, FAILURE));
	}
    }
  return (OK);
}
