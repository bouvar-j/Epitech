/*
** epur_str.h for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/Max
**
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
**
** Started on  Wed Jun  1 12:40:54 2016 Maxime Maisonnas
** Last update Sun Jun  5 18:16:49 2016 Maxime Maisonnas
*/

#ifndef EPUR_STR_H_
# define EPUR_STR_H_

# ifndef FSIZE
#  define FSIZE	7
# endif /* !FSIZE */

# ifndef FPIPE
#  define FPIPE	1
# endif /* !FPIPE */

# ifndef FREDD
#  define FREDD	2
# endif /* !FREDD */

# ifndef FREDG
#  define FREDG	3
# endif /* !FREDG */

# ifndef FSEP
#  define FSEP	4
# endif /* !FSEP */

char	*analyse_cmd(char *);
char	*analyse_cmd2(char **, char *);
int	f_sp_tab_ptvr(char *, char *, int *, int *);
int	f_pipe(char *, char *, int *, int *);
int	f_chevl(char *, char *, int *, int *);
int	f_chevr(char *, char *, int *, int *);
int	f_et_com(char *, char *, int *, int *);

#endif /* !EPUR_STR_H_ */
