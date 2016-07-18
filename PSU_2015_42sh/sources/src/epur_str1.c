/*
** epur_str1.c for 42sh in /home/Maxoulakin/B2/PSU/PSU_2015_42sh/Max/sources
** 
** Made by Maxime Maisonnas
** Login   <Maxoulakin@epitech.net>
** 
** Started on  Mon May 30 16:50:24 2016 Maxime Maisonnas
** Last update Wed Jun  1 16:40:15 2016 Maxime Maisonnas
*/

#include "sh.h"
#include "epur_str.h"

int	f_sp_tab_ptvr(char *new, char *str, int *i, int *j)
{
  int	m;

  m = 0;
  new[(*j)++] = ' ';
  while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == ';')
    if (str[(*i)++] == ';')
      m = 1;
  if (m == 1)
    {
      new[(*j)++] = ';';
      new[(*j)++] = ' ';
    }
  return (OK);
}

int	f_pipe(char *new, char *str, int *i, int *j)
{
  char	tmp[4];
  int	k;

  k = 0;
  while (k < 3 && str[*i] == '|')
    tmp[k++] = str[(*i)++];
  tmp[k] = 0;
  if (k > 2)
    {
      printerr("Invalid null command.\n");
      return (KO);
    }
  k = 0;
  if (new[*j - 1] != ' ')
    new[(*j)++] = ' ';
  while (tmp[k])
    new[(*j)++] = tmp[k++];
  if (str[*i] != ' ')
    new[(*j)++] = ' ';
  return (OK);
}

int	f_chevl(char *new, char *str, int *i, int *j)
{
  char	tmp[4];
  int	k;

  k = 0;
  while (k < 3 && str[*i] == '<')
    tmp[k++] = str[(*i)++];
  tmp[k] = 0;
  if (k > 2)
    {
      printerr("Invalid null command.\n");
      return (KO);
    }
  k = 0;
  if (new[*j - 1] != ' ')
    new[(*j)++] = ' ';
  while (tmp[k])
    new[(*j)++] = tmp[k++];
  if (str[*i] != ' ')
    new[(*j)++] = ' ';
  return (OK);
}

int	f_chevr(char *new, char *str, int *i, int *j)
{
  char	tmp[4];
  int	k;

  k = 0;
  while (k < 3 && str[*i] == '>')
    tmp[k++] = str[(*i)++];
  tmp[k] = 0;
  if (k > 2)
    {
      printerr("Invalid null command.\n");
      return (KO);
    }
  k = 0;
  if (new[*j - 1] != ' ')
    new[(*j)++] = ' ';
  while (tmp[k])
    new[(*j)++] = tmp[k++];
  if (str[*i] != ' ')
    new[(*j)++] = ' ';
  return (OK);
}

int	f_et_com(char *new, char *str, int *i, int *j)
{
  char	tmp[4];
  int	k;

  k = 0;
  while (k < 3 && str[*i] == '&')
    tmp[k++] = str[(*i)++];
  tmp[k] = 0;
  if (k != 2)
    {
      printerr("Invalid null command.\n");
      return (KO);
    }
  k = 0;
  if (new[*j - 1] != ' ')
    new[(*j)++] = ' ';
  while (tmp[k])
    new[(*j)++] = tmp[k++];
  if (str[*i] != ' ')
    new[(*j)++] = ' ';
  return (OK);
}
