/*
** main.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:10:18 2017 kerma
** Last update Wed Jun 21 13:41:26 2017 kerma
*/

#include "zappy.h"

int		main(int ac, char **av)
{
  t_zappy	zappy;

  args(&zappy, ac, av);

  clean(&zappy);
  return (0);
}
