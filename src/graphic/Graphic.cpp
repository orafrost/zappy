//
// zappy_graphic.cpp for zappy in /home/eric/tek2/zappy/graphic
// 
// Made by Eric Amilhat
// Login   <eric.amilhat@epitech.eu>
// 
// Started on  Tue Jun 20 14:14:46 2017 Eric Amilhat
//

#include "Graphic.hpp"

Graphic::Graphic() : mapIsSized(false), spriteSize(0), frequency(0)
{
  map.width = 0;
  map.height = 0;
  assets.hoverT.loadFromFile("./assets/hover.png");

  // Background creation

  assets.backgroundT.loadFromFile("./assets/zappy_background.png");
  assets.background.setTexture(assets.backgroundT);
  assets.background.setPosition(0,0);

  // Cloud creation

  assets.cloudT.loadFromFile("./assets/cloud2.png");
  assets.cloud.setTexture(assets.cloudT);
  assets.cloud.setPosition(0,0);
  assets.c = 0;
  assets.h = (rand() % WINDOW_SIZE) - (assets.cloudT.getSize().y / 2);

  // Info background creation
  
  assets.infoBackgroundT.loadFromFile("./assets/info_background.png");
  assets.infoBackground.setTexture(assets.infoBackgroundT);
  assets.infoBackground.setPosition(WINDOW_SIZE, 00);

  // ---------- LOGO creation
  
  assets.logoT.loadFromFile("./assets/logo.png");
  assets.logo.setTexture(assets.logoT);
  assets.logo.setPosition(WINDOW_SIZE + 5, 10);

  // ---------- Characters creation

  characters.resize(5);
  
  characters[0].resize(3);
  characters[0][0].loadFromFile("./assets/Goku_0.png");
  characters[0][1].loadFromFile("./assets/Goku_1.png");
  characters[0][2].loadFromFile("./assets/Goku_2.png");

  characters[1].resize(3);
  characters[1][0].loadFromFile("./assets/Boo_0.png");
  characters[1][1].loadFromFile("./assets/Boo_1.png");
  characters[1][2].loadFromFile("./assets/Boo_2.png");

  characters[2].resize(3);
  characters[2][0].loadFromFile("./assets/Gohan_0.png");
  characters[2][1].loadFromFile("./assets/Gohan_1.png");
  characters[2][2].loadFromFile("./assets/Gohan_2.png");

  characters[3].resize(3);
  characters[3][0].loadFromFile("./assets/Frieza_0.png");
  characters[3][1].loadFromFile("./assets/Frieza_1.png");
  characters[3][2].loadFromFile("./assets/Frieza_2.png");

  characters[4].resize(3);
  characters[4][0].loadFromFile("./assets/Vegeta_0.png");
  characters[4][1].loadFromFile("./assets/Vegeta_1.png");
  characters[4][2].loadFromFile("./assets/Vegeta_2.png");
  
  assets.multipleT.loadFromFile("./assets/goku_1.png");
  assets.font.loadFromFile("./assets/font.ttf");

  textures.resize(8);
  textures[e_resources::Food].loadFromFile("./assets/Food2.png");
  textures[e_resources::Linemate].loadFromFile("./assets/Linemate.png");
  textures[e_resources::Deraumere].loadFromFile("./assets/Deraumere.png");
  textures[e_resources::Sibur].loadFromFile("./assets/Sibur.png");
  textures[e_resources::Mendiane].loadFromFile("./assets/Mendiane.png");
  textures[e_resources::Phiras].loadFromFile("./assets/Phiras.png");
  textures[e_resources::Thystame].loadFromFile("./assets/Thystame.png");

  texturesLarge.resize(8);
  texturesLarge[e_resources::Food].loadFromFile("./assets/Food_large.png");
  texturesLarge[e_resources::Linemate].loadFromFile("./assets/Linemate_large.png");
  texturesLarge[e_resources::Deraumere].loadFromFile("./assets/Deraumere_large.png");
  texturesLarge[e_resources::Sibur].loadFromFile("./assets/Sibur_large.png");
  texturesLarge[e_resources::Mendiane].loadFromFile("./assets/Mendiane_large.png");
  texturesLarge[e_resources::Phiras].loadFromFile("./assets/Phiras_large.png");
  texturesLarge[e_resources::Thystame].loadFromFile("./assets/Thystame_large.png");
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

int                   Graphic::getPerfectSquare(int sum)
{
  int			i = 1;
  while ((i * i) < sum)
    {
      i++;
    }
  return (i);
}

void	Graphic::expandTile()
{
  int x = mouse.getPosition(window).x / spriteSize;
  int y = mouse.getPosition(window).y / spriteSize;

  if (x >= map.width || y >= map.height)
    return;

  sf::Text		text;
  sf::RectangleShape	drawer;
  int			left;

  // Text
  text.setFont(assets.font);
  text.setCharacterSize(35);
  text.setPosition(WINDOW_SIZE  + 30, 200);
  text.setString("Position:\nx = " + std::to_string(x) + "  y = " + std::to_string(y));
  window.draw(text);

  // Hover
  drawer.setTexture(&(assets.hoverT));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(x * spriteSize, y * spriteSize);
  drawer.setFillColor(sf::Color(255, 255, 255, 128));
  window.draw(drawer);
  drawer.setFillColor(sf::Color(255, 255, 255, 255));
  
  int off = 0;
  int off2 = 0;
  for (int i = 0; i < 7; i++)
    {
      left = map.arr[x][y].resources[i];
      while (left != 0)
	{
	  drawer.setTexture(&(texturesLarge[i]));
	  drawer.setPosition(WINDOW_SIZE + (off * 100),  400 + (off2 * 100));
	  window.draw(drawer);
	  off++;
	  if (off == 5)
	    {
	      off2++;
	      off = 0;
	    }
	  left--;
	}
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
      printMap();
      printPlayers();
      printInfo();
      expandTile();
      window.display();      
    }
}

int	Graphic::sumOfBlock(int x, int y) const
{
  int	sum = 0;
  if (x >= map.width || y >= map.height || x < 0 || y < 0)
    return (0);
  //if (map.arr[x][y].resources[0] > 0)
  //sum++;
  for (int i = 0; i < 7;i++)
    sum += map.arr[x][y].resources[i];
  return (sum);
}

void                  Graphic::drawPlayer(t_player const & player, int team)
{
  sf::RectangleShape    drawer;

  drawer.setTexture(&(characters[team][player.L / 2]));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(player.X * spriteSize, player.Y * spriteSize);
  window.draw(drawer);
}

void                  Graphic::printPlayers()
{
  int	i = 0;
  for (std::vector<t_team>::const_iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::const_iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  drawPlayer(*it2, i);
	}
      i++;
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
  int			sq = getPerfectSquare(sum);
  int			offy = (spriteSize/sq) * (pos / sq);
  int			offx = (spriteSize/sq) * (pos % sq);

  drawer.setTexture(&(textures[resource]));
  drawer.setSize(sf::Vector2f(spriteSize/sq, spriteSize/sq));
  drawer.setPosition((x * spriteSize) + offx, (y * spriteSize) + offy );
  window.draw(drawer);
}

void    Graphic::drawResource(int resource, int x , int y, int sum, int pos)
{
  sf::RectangleShape	drawer;

  drawer.setTexture(&(textures[resource]));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition((x * spriteSize) + spriteSize/2, (y * spriteSize) + spriteSize/2);
  drawer.setOrigin(spriteSize/2, spriteSize/2);
  drawer.setRotation(((360/sum) * pos) + (int)map.arr[x][y].n);
  window.draw(drawer);
}

void    Graphic::printInfo()
{
  window.draw(assets.infoBackground);
  window.draw(assets.logo);
  
}
  
void	Graphic::printMap()
{
  int	sum;
  int	pos;
  int	left;

  window.draw(assets.background);
  assets.c += 0.2f;
  assets.cloud.setPosition((int)assets.c, assets.h);
  window.draw(assets.cloud);
  if (assets.c > assets.cloudT.getSize().x - WINDOW_SIZE)
    {
      assets.c = -3109;
      assets.h = (rand() % WINDOW_SIZE) - (assets.cloudT.getSize().y / 2);
    }
  for (int y = 0; y < map.height; y++)
    {
      for (int x = 0; x < map.width;x++)
	{
	  sum = sumOfBlock(x, y);
	  pos = 0;
	  map.arr[x][y].n += 0.2f;
	  if (map.arr[x][y].n >= 360)
	    map.arr[x][y].n = 0;
	  /*if (map.arr[x][y].resources[0] > 0)
	    {
	      drawResource(0, x, y, sum, pos);
	      pos++;
	    }*/
	  for (int i = 0; i < 7;i++)
	    {
	      left = map.arr[x][y].resources[i];
	      while (left != 0)
		{
		  drawResource((e_resources)i, x, y, sum, pos);
		  pos++;
		  left--;
		}
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
  if (dir > 3 || x > map.width || y > map.height)
    return;

  t_player	player;

  player.id = id;
  player.X = x;
  player.Y = y;
  player.dir = static_cast<e_dir>(dir);
  player.L = level;
  player.teamName = teamName;
  for (std::vector<t_team>::iterator it = teams.begin();it != teams.end(); ++it)
    {
      if (it->teamName == teamName) {
	it->players.push_back(player);
	return ;
      }
    }
}

void		Graphic::setPlayerPosition(int id, int x, int y, int dir)
{
  if (dir > 3 || x > map.width || y > map.height)
    return;

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
