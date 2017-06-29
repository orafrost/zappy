//
// main.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:27:22 2017 kerma
// Last update Thu Jun 29 15:30:59 2017 kerma
//

#include "Utils.hpp"
#include "Socket.hpp"
#include "Graphic.hpp"

int		main(int ac, char **av)
{
  Graphic	graph;
  Socket	socket;
  Utils		utils;
  int		port;

  port = utils.ParsArg(ac, av);
  socket.Connect(port);
  socket.SetGraphicPtr(&graph);
  while ("ever") {
    socket.ServerTalk();
    graph.update();
  }
  return (0);
}
