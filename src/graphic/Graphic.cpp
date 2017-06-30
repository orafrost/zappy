//
// zappy_graphic.cpp for zappy in /home/eric/tek2/zappy/graphic
// 
// Made by Eric Amilhat
// Login   <eric.amilhat@epitech.eu>
// 
// Started on  Tue Jun 20 14:14:46 2017 Eric Amilhat
// Last update Fri Jun 30 16:29:57 2017 Eric Amilhat
//

#include "Graphic.hpp"

Graphic::Graphic() : mapIsSized(false), spriteSize(0), frequency(0)
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
  textures[EMPTY].loadFromFile("./assets/empty.png");
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
      printPlayers();
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

void                  Graphic::drawPlayer(t_player const & player, sf::Color color)
{
  sf::RectangleShape    drawer;


  (void)color;
  drawer.setTexture(&(assets.multipleT));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(player.X * spriteSize, player.Y * spriteSize);
  window.draw(drawer);
}

void                  Graphic::printPlayers()
{
  for (std::vector<t_team>::const_iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::const_iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  drawPlayer(*it2, sf::Color(255, 0, 0));
	}
    }
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

void	Graphic::drawMultipleSprites(int resource,int x , int y, int sum, int pos)
{
  sf::RectangleShape	drawer;
  //int			offx;
  //int			offy = (spriteSize/sum);

  drawer.setTexture(&(textures[resource]));
  drawer.setSize(sf::Vector2f(spriteSize/sum, spriteSize/sum));
  drawer.setPosition((x * spriteSize) + ((spriteSize/sum) * pos), (y * spriteSize) );
  window.draw(drawer);
}



void	Graphic::printMap()
{
  int	sum;
  int	pos;
  int	left;
  
  for (int y = 0; y < map.height; y++)
    {
      for (int x = 0; x < map.width;x++)
	{
	  drawSprite(EMPTY, x, y);
	  sum = sumOfBlock(x, y);
	  if (sum == 1)
	    {
	      for (int i = 0;i < 7;i++)
		{
		  if (map.arr[x][y].resources[i] != 0)
		    drawSprite((e_resources)i, x, y);
		}
	    }
	  else if (sum > 1)
	    {
	      pos = 0;
	      for (int i = 0; i < 7;i++)
		{
		  left = map.arr[x][y].resources[i];
		  while (left != 0)
		    {
		      drawMultipleSprites((e_resources)i, x, y, sum, pos);
		      pos++;
		      left--;
		    }
		}
	      //drawMultiple(x, y);
	    }
	}
    }
}

void	Graphic::setMapDimensions(int width, int height)
{
  if (width > 100 || height > 100)
    Error("Map dimensions must not be over 100");
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

void			Graphic::addTeam(std::string name)
{
  t_team		team;

  team.teamName = name;
  teams.push_back(team);
}

void                  Graphic::addPlayer(int id, int x, int y, int dir, int level,
				std::string teamName)
{
  //std::cout << "dir  = "
  if (dir > 3 || x > map.width || y > map.height)
    {
      std::cout << "KO" << std::endl;
      return;
    }
  t_player	player;

  player.id = id;
  player.X = x;
  player.Y = y;
  player.dir = static_cast<e_dir>(dir);
  player.L = level;
  player.teamName = teamName;
  for (std::vector<t_team>::iterator it = teams.begin();it != teams.end(); ++it)
    {
      if (it->teamName == teamName)
	{
	  std::cout << "OKAY" << std::endl;
	  it->players.push_back(player);
	}
    }
}

void		Graphic::setPlayerPosition(int id, int x, int y, int dir)
{
  if (dir > 3 || x > map.width || y > map.height)
    return;
  if (x < map.width && y < map.height)
    {
      for (std::vector<t_team>::iterator it = teams.begin(); it != teams.end(); ++it)
	{
	  for (std::vector<t_player>::iterator it2 = it->players.begin();
	       it2 != it->players.end(); ++it2)
	    {
	      if (it2->id == id)
		{
		  it2->X = x;
		  it2->Y = y;
		  it2->dir = static_cast<e_dir>(dir);
		  return;
		}
	    }	  
	}
    }
}

void		Graphic::playerBroadcast(int id)
{
  for (std::vector<t_team>::iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  if (it2->id == id)
	    {
	      // ANIMATE BROADCAST
	      return;
	    }
	}
    }  
}

void		Graphic::setLevel(int id, int level)
{
  for (std::vector<t_team>::iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  if (it2->id == id)
	    {
	      it2->L = level;
	      return;
	    }
	}
    }
}

void		Graphic::setFrequence(int f)
{
  frequency = f;
}

void                  Graphic::addEgg(int egg_id, int player_id, int x, int y)
{
  if (x > map.width || y > map.height)
    return;
  t_egg			egg;

  egg.id = egg_id;
  egg.parent_id = player_id;
  map.arr[x][y].eggs.push_back(egg);
}

void                  Graphic::hatchEgg(int id)
{
  for (int y = 0; y < map.height; y++)
    {
      for (int x = 0; x < map.width;x++)
	{
	  for (std::vector<t_egg>::iterator it = map.arr[x][y].eggs.begin();
	       it != map.arr[x][y].eggs.end(); ++it)
	    {
	      if (it->id == id)
		{
		  map.arr[x][y].eggs.erase(it);
		  return;
		}
	    }
	}
    }
}

void		Graphic::addResource(int player_id, int resourceType)
{
  if (resourceType > 6)
    return;
  for (std::vector<t_team>::iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  if (it2->id == player_id)
	    {
	      map.arr[it2->X][it2->Y].resources[resourceType]++;
	      return;
	    }
	}
    }
}

void		Graphic::removeResource(int player_id, int resourceType)
{
  if (resourceType > 6)
    return;
  for (std::vector<t_team>::iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  if (it2->id == player_id)
	    {
	      if (map.arr[it2->X][it2->Y].resources[resourceType] > 0)
		map.arr[it2->X][it2->Y].resources[resourceType]--;
	      return;
	    }
	}
    }
}

int                  Graphic::endGame(std::string teamName)
{
  for (std::vector<t_team>::iterator it = teams.begin();it != teams.end(); ++it)
    {
      if (it->teamName == teamName)
	{
	  // WINNER SCREEN
	  return (0);
	}
    }
  return (-1);
}

void                  Graphic::startIncantation(int id)
{
  for (std::vector<t_team>::iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  if (it2->id == id)
	    {
	      // INCANTATION ANIMATION
	      return;
	    }
	}
    }
}

void                  Graphic::endIncantation(int x, int y)
{
  (void)x;
  (void)y;
  // END INCANTATION ANIMATION AT X Y
}

void		Graphic::killPlayer(int id)
{
  for (std::vector<t_team>::iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  if (it2->id == id)
	    {
	      it->players.erase(it2);
	      return;
	    }
	}
    }
}
