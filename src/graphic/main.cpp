//
// main.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:27:22 2017 kerma
// Last update Wed Jun 28 17:38:31 2017 kerma
//

#include "graphic.hpp"

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

int	main()
{
  launchGraphics();
  return (0);
}
