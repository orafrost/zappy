//
// zappy_graphic.cpp for zappy in /home/eric/tek2/zappy/graphic
// 
// Made by Eric Amilhat
// Login   <eric.amilhat@epitech.eu>
// 
// Started on  Tue Jun 20 14:14:46 2017 Eric Amilhat
// Last update Thu Jun 29 16:09:59 2017 Eric Amilhat
//

#include "Graphic.hpp"

Graphic::Graphic() : mapIsSized(false), spriteSize(0)
{
  map.width = 0;
  map.height = 0;
  assets.backgroundT.create(WINDOW_SIZE, WINDOW_SIZE);
  assets.hoverT.loadFromFile("./assets/hover.png");
  assets.multipleT.loadFromFile("./assets/pikachu.png");
  assets.background.setTexture(assets.backgroundT);
  assets.font.loadFromFile("./assets/font.ttf");
  textures.resize(8);
  textures[e_resources::Food].loadFromFile("./assets/Food.png");
  textures[e_resources::Linemate].loadFromFile("./assets/Linemate.png");
  textures[e_resources::Deraumere].loadFromFile("./assets/Deraumere.png");
  textures[e_resources::Sibur].loadFromFile("./assets/Sibur.png");
  textures[e_resources::Mendiane].loadFromFile("./assets/Mendiane.png");
  textures[e_resources::Phiras].loadFromFile("./assets/Phiras.png");
  textures[e_resources::Thystame].loadFromFile("./assets/Thystame.png");
  textures[EMPTY].loadFromFile("./assets/Grass.png");
}
  
Graphic::~Graphic()
{
  window.close();
}

int	Graphic::Error(const std::string &err) const
{
  std::cerr << "Error: " << err << std::endl;
  exit(84);
}

void	Graphic::expandTile()
{
  int x = mouse.getPosition(window).x / spriteSize;
  int y = mouse.getPosition(window).y / spriteSize;
  sf::Text text;
  sf::RectangleShape	drawer;
  
  // Text
  text.setFont(assets.font);
  text.setCharacterSize(35);
  text.setPosition(WINDOW_SIZE , 50);
  text.setString("x = " + std::to_string(x) + "  y = " + std::to_string(y));
  window.draw(text);

  // Hover
  drawer.setTexture(&(assets.hoverT));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(x * spriteSize, y * spriteSize);
  drawer.setFillColor(sf::Color(255, 255, 255, 128));
  window.draw(drawer);
  drawer.setFillColor(sf::Color(255, 255, 255, 255));
  
  if (sumOfBlock(x, y) > 1)
    {
      int off = 0;
      for (int i = 0; i < 7; i++)
	{
	  if (map.arr[x][y].resources[i] != 0)
	    {
	      
	      drawer.setTexture(&(textures[i]));
	      drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
	      drawer.setPosition(WINDOW_SIZE + (off * spriteSize), 0);
	      window.draw(drawer);
	      off++;
	    }
	    
	}
      //std::cout << "here" << std::endl;
    }
    
}

void	Graphic::eventManager()
{
  while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
	  window.close();
	  exit(0);
	}
      if (event.type == sf::Event::MouseMoved)
	{
	  //expandTile(event.mouseMove.x, event.mouseMove.y);
	}
    }
}

void	Graphic::initWindow()
{
  if (map.width != 0 && map.height != 0 && !map.arr.empty() && mapIsSized == false)
    {
      window.create(sf::VideoMode(WINDOW_SIZE + 500, WINDOW_SIZE), "Zappy");
      mapIsSized = true;
    }
}

void	Graphic::update()
{
  if (window.isOpen())
    {
      eventManager();
      window.clear();
      window.draw(assets.background);
      printMap();
      expandTile();
      window.display();      
    }
}

int	Graphic::sumOfBlock(int x, int y) const
{
  int	sum = 0;
  if (x >= map.width || y >= map.height || x < 0 || y < 0)
    return (0);
  for (int i = 0; i < 7;i++)
    sum += map.arr[x][y].resources[i];
  return (sum);
}


void	Graphic::drawSprite(int resource, int x, int y)
{
  sf::RectangleShape	drawer;

  drawer.setTexture(&(textures[resource]));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(x * spriteSize, y * spriteSize);
  window.draw(drawer);
}

void	Graphic::drawMultiple(int x , int y)
{
  sf::RectangleShape	drawer;
  drawer.setTexture(&(assets.multipleT));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(x * spriteSize, y * spriteSize);
  window.draw(drawer);
}
			     
void	Graphic::printMap()
{
  for (int y = 0; y < map.height; y++)
    {
      for (int x = 0; x < map.width;x++)
	{
	  drawSprite(EMPTY, x, y);
	  if (sumOfBlock(x, y) == 1)
	    {
	      for (int i = 0;i < 7;i++)
		{
		  if (map.arr[x][y].resources[i] != 0)
		    drawSprite((e_resources)i, x, y);
		}
	    }
	  else if (sumOfBlock(x, y) > 1)
	    {
	      drawMultiple(x, y);
	    }
	}
    }
}

void	Graphic::setMapDimensions(int width, int height)
{
  map.width = width;
  map.height = height;
  map.arr.resize(width);
  for (int i = 0; i < width; i++)
    map.arr[i].resize(height);
  int max = (map.height > map.width) ? map.height : map.width;
  this->spriteSize = WINDOW_SIZE/max;
}

void                  Graphic::setBlock(int x, int y, std::vector<int> arg)
{
  if (x > map.width || y > map.height)
    return;
  for (int i = 0; i < 7; i++)
    map.arr[x][y].resources[i] = arg[i];
}
