/*
** init_prompt.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/init/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Wed May 25 17:17:47 2016 Steven Syp
** Last update Mon Jul 18 18:55:16 2016 Julien Bouvard
*/

#include "sh.h"

int	get_user_line(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'U' && env[i][1] == 'S'
	  && env[i][2] == 'E' && env[i][3] == 'R'
	  && env[i][4] == '=')
	return (i);
      i++;
    }
  return (-1);
}

char	*get_prompt(char *env_user, char *prompt)
{
  t_pos	p;
  char	*usr;

  p = init_pos(0, 0);
  if ((usr = malloc(my_strlen(env_user) - 4)) == NULL)
    return (NULL);
  while (env_user[p.i++] != '=');
  while (env_user[p.i])
    usr[p.j++] = env_user[p.i++];
  prompt = my_strcat(usr, " > ");
  free(usr);
  return (prompt);
}

char	*init_prompt(t_shell *sh)
{
  int	line;
  char	*prompt;

  if ((prompt = malloc(100)) == NULL)
    return (NULL);
  line = get_user_line(sh->env);
  if (line == -1)
    my_strcpy(prompt, "42sh > ");
  else if (my_strcmp(sh->env[line], "USER=unknown"))
    my_strcpy(prompt, "42sh > ");
  else if ((prompt = get_prompt(sh->env[line], prompt)) == NULL)
    return (NULL);
  if ((prompt = my_realloc(prompt, my_strlen(prompt))) == NULL)
    return (NULL);
  sh->prompt_len = my_strlen(prompt);
  return (prompt);
}
