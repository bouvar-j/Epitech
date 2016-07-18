/*
** init_env.c for  in /Users/stevensyp/Dropbox/Epitech/gitclone/PSU/42sh/tmp/sources/init/
**
** Made by Steven Syp
** Login   <syp_s@epitech.eu>
**
** Started on  Wed May 25 16:28:30 2016 Steven Syp
** Last update Mon Jul 18 18:54:57 2016 Julien Bouvard
*/

#include "sh.h"

char		*default_fill(char *line, char *content)
{
  if ((line = malloc(my_strlen(content) + 1)) == NULL)
    return (NULL);
  return (my_strcpy(line, content));
}

char		**default_env(char **env)
{
  if ((env = malloc(sizeof(char *) * 12)) == NULL)
    return (NULL);
  if (!(env[0] = default_fill(env[0], "HOSTTYPE=unknown")))
    return (NULL);
  if (!(env[1] = default_fill(env[1], "VENDOR=unknown")))
    return (NULL);
  if (!(env[2] = default_fill(env[2], "OSTYPE=unknown")))
    return (NULL);
  if (!(env[3] = default_fill(env[3], "MACHTYPE=unknown")))
    return (NULL);
  if (!(env[4] = default_fill(env[5], "PWD=")))
    return (NULL);
  if (!(env[4] = my_strcat(env[4], getcwd(NULL, 0))))
    return (NULL);
  if (!(env[5] = default_fill(env[6], "LOGNAME=unknown")))
    return (NULL);
  if (!(env[6] = default_fill(env[7], "USER=unknown")))
    return (NULL);
  if (!(env[7] = default_fill(env[9], "HOST=unknown")))
    return (NULL);
  if (!(env[8] = default_fill(env[10], "OLDPWD=")))
    return (NULL);
  env[9] = NULL;
  return (env);
}

char		**init_env(char **envp)
{
  int		count;
  int		save;
  char		**env;

  count = 0;
  save = 0;
  if (!envp[0])
    return (default_env(NULL));
  while (envp[save])
    save++;
  if ((env = malloc(sizeof(char *) * (++save))) == NULL)
    return (NULL);
  while (count < (save - 1))
    {
      if ((env[count] = malloc(my_strlen(envp[count]) + 1)) == NULL)
	return (NULL);
      my_strcpy(env[count], envp[count]);
      count++;
    }
  env[count] = NULL;
  return (env);
}
