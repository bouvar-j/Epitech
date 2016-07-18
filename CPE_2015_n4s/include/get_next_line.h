/*
** get_next_line.h for gtx in /home/juniqu_v/rendu/CPE_2015_n4s
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sun May 29 23:16:29 2016 virgile junique
** Last update Sun May 29 23:16:30 2016 virgile junique
*/

#ifndef GET_NEXT_LINE_H_

# define GET_NEXT_LINE_H_

# include <unistd.h>
# include <stdlib.h>

# ifndef READ_SIZE
#  define READ_SIZE (100)
# endif /* READ_SIZE */

char	*my_reader(const int fd, char **save);
char	*get_next_line(const int fd);

#endif /* GET_NEXT_LINE_H_ */
