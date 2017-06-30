//
// main.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:27:22 2017 kerma
// Last update Thu Jun 29 20:35:14 2017 kerma
//

#include "Utils.hpp"
#include "Socket.hpp"

int		main(int ac, char **av)
{
  Socket	socket;
  Utils		utils;
  t_arg		args;

  args = utils.ParsArg(ac, av);
  socket.Connect(args.port, args.machine);

  // Set TeamName on AI class
  while ("ever") {
    socket.ServerTalk();
  }
  return (0);
}
