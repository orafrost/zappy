/*
** main.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Tue Jun 20 14:10:18 2017 kerma
** Last update Sat Jun 24 17:16:49 2017 kerma
*/

#include "zappy.h"

int		main(int ac, char **av)
{
  t_zappy	zappy;
  int		ret;

  if ((ret = args(&zappy, ac, av)) == 0)
    ret = main_loop(&zappy);
  clean(&zappy);
  return (ret);
}
