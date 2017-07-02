//
// main.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:27:22 2017 kerma
// Last update Sun Jul  2 18:23:42 2017 Guillaume Verrier
//

#include "Utils.hpp"
#include "Socket.hpp"

int		main(int ac, char **av)
{
  Socket	socket;
  Utils		utils;
  AI		ai;
  t_arg		args;
  bool    act;

  args = utils.ParsArg(ac, av);
  socket.Connect(args.port, args.machine);
  socket.SetTeamName(args.name);
  socket.SetAI(&ai);
  act = true;
  while ("ever") {
    socket.ServerTalk();
    if (ai.wait() == false)
    {
      if (act == true)
      {
        ai.vision();
        act = false;
      }
      else if (ai.resource() == 0)
      {
        ai.forward();
        act = true;
      }
      else if (ai.resource() == 1)
      {
        ai.clean();
        act = true;
      }
      else
      {
        ai.up();
      }
    }
  }
  return (0);
}
