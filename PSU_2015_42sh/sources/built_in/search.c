/*
** search.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/sources/built_in
**
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
**
** Started on  Thu Jun  2 10:49:18 2016 Maxime Maisonnas
** Last update Sun Jun  5 22:45:19 2016 Maxime Maisonnas
*/

#include "sh.h"

char	**search_built_in(char **com, char **env, int *r, int fd)
{
  *r = 1;
  if (my_strcmp(com[0], "cd"))
    return (my_cd(com, env));
  else if (my_strcmp(com[0], "echo"))
    return (my_echo(com, env, fd));
  else if (my_strcmp(com[0], "setenv"))
    return (my_setenv(com, env));
  else if (my_strcmp(com[0], "unsetenv"))
    return (my_unsetenv(com, env));
  else if (my_strcmp(com[0], "exit"))
    return (my_exit(com, env));
  *r = 0;
  return (NULL);
}
