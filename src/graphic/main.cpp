//
// main.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:27:22 2017 kerma
// Last update Thu Jun 29 12:37:59 2017 kerma
//

#include "Utils.hpp"
#include "Socket.hpp"
#include "Graphic.hpp"

void	launchGraphics()
{
  Graphic graph;

  graph.setMapDimensions(20,20);
  graph.randomlyFillMap();
  //graph.receive();
  //if (ac >= 3)
  //graph.setMapDimensions(std::stoi(av[1]),std::stoi(av[2]));
  //else
  graph.loop();  
}

int		main(int ac, char **av)
{
  Socket	socket;
  Utils		utils;
  int		port;

  port = utils.ParsArg(ac, av);
  socket.Connect(port);
  
  // launchGraphics();
  while ("ever") {
    socket.ServerTalk();
  }
  return (0);
}
