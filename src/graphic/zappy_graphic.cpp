//
// zappy_graphic.cpp for zappy in /home/eric/tek2/zappy/graphic
// 
// Made by Eric Amilhat
// Login   <eric.amilhat@epitech.eu>
// 
// Started on  Tue Jun 20 14:14:46 2017 Eric Amilhat
// Last update Wed Jun 28 16:06:10 2017 Eric Amilhat
//

#include "zappy_graphic.hpp"

Graphic::Graphic()
{
  window.create(sf::VideoMode(WINDOW_SIZE + 500, WINDOW_SIZE), "zappy");
  assets.backgroundT.create(WINDOW_SIZE, WINDOW_SIZE);
  assets.hoverT.loadFromFile("./hover.png");
  assets.multipleT.loadFromFile("./pikachu.png");
  assets.background.setTexture(assets.backgroundT);
  assets.font.loadFromFile("./font.ttf");
  textures.resize(8);
  textures[e_resources::Food].loadFromFile("./Food.png");
  textures[e_resources::Linemate].loadFromFile("./Linemate.png");
  textures[e_resources::Deraumere].loadFromFile("./Deraumere.png");
  textures[e_resources::Sibur].loadFromFile("./Sibur.png");
  textures[e_resources::Mendiane].loadFromFile("./Mendiane.png");
  textures[e_resources::Phiras].loadFromFile("./Phiras.png");
  textures[e_resources::Thystame].loadFromFile("./Thystame.png");
  textures[e_resources::Empty].loadFromFile("./Grass.png");
}
  
Graphic::~Graphic()
{
  window.close();
}

void	Graphic::randomlyFillMap()
{
  int	r;

  for (int y = 0; y < map.height;y++)
    {
      for (int x = 0; x < map.width;x++)
	{
	  r = rand () % 2;
	  if (r == 0)
	    map.arr[x][y] = getRandomBlock(true);
	  else
	    {
	      map.arr[x][y] = getRandomBlock(false);
	    }
	}
    }
}

t_block               Graphic::getRandomBlock(bool empty)
{
  t_block	      block;

  for (int i = 0; i < 7;i++)
      block.resources[i] = 0;
  if (!empty)
    {
      block.resources[rand() % 7] = 1;
      if (rand() % 3 == 0)
	block.resources[rand() % 7] = 1;
    }
  return (block);
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
      if (event.type == sf::Event::Closed)
	window.close();
      if (event.type == sf::Event::MouseMoved)
	{
	  //expandTile(event.mouseMove.x, event.mouseMove.y);
	}
    }
}

void	Graphic::loop()
{
  while (window.isOpen())
    {
      eventManager();
      window.clear();
      window.draw(assets.background);
      printMap();
      expandTile();
      window.display();      
    }
}
int	Graphic::sumOfBlock(int x, int y)
{
  int	sum = 0;
  if (x >= map.width || y >= map.height || x < 0 || y < 0)
    return (0);
  for (int i = 0; i < 7;i++)
    sum += map.arr[x][y].resources[i];
  return (sum);
}


void	Graphic::drawSprite(e_resources resource, int x, int y)
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
  //randomlyFillMap();
  for (int y = 0; y < map.height; y++)
    {
      for (int x = 0; x < map.width;x++)
	{
	  drawSprite(e_resources::Empty, x, y);
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

void	Graphic::receive()
{
  std::string input;
  getline(std::cin, input);
  std::cout << "trying to compare : " << std::endl;
  std::cout << input << std::endl;
  std::cout << "and" << std::endl;
  std::cout << "msz " << std::endl;
  
  if (input.substr(0,4).compare("msz ") == 0)
    {
      setMapDimensions(std::stoi(input.substr(4,5)),std::stoi(input.substr(6,7)));
      std::cout << "you entered may X = " << std::stoi(input.substr(4,5)) << " and "
		<< std::stoi(input.substr(6,7)) << std::endl;
    }
  else
    {
      setMapDimensions(100,100);
      std::cout << "Failed to get Map Size " << std::endl;
      
    }
  mapIsSized = true;

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

t_map const & Graphic::getMapInfo()
{
  return (this->map);
}

int main()
{
  Graphic graph;
  graph.setMapDimensions(20,20);
  graph.randomlyFillMap();
  //graph.receive();
  //if (ac >= 3)
    //graph.setMapDimensions(std::stoi(av[1]),std::stoi(av[2]));
    //else
  graph.loop();
  exit (0);
}

