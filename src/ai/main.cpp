//
// main.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:27:22 2017 kerma
// Last update Sun Jul  2 10:42:40 2017 kerma
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
  socket.SetTeamName(args.name);
  while ("ever") {
    socket.ServerTalk();
  }
  return (0);
}
