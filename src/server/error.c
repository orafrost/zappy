/*
** error.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:51:06 2017 kerma
** Last update Tue Jun 20 16:00:47 2017 kerma
*/

#include "zappy.h"

void	puterr(char *err)
{
  fprintf(stderr, "%s\n", err);
  exit(ERROR);
}
