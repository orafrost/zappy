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

  selectedPlayer.id = -1;
  selectedPlayer.team = -1;

  assets.hoverT.loadFromFile("./assets/hover.png");
  assets.directionT.loadFromFile("./assets/Direction.png");
  assets.eggT.loadFromFile("./assets/egg.png");

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

  // --------- elevation creation

  elevation.resize(4);
  elevation[0].loadFromFile("./assets/charge_1.png");
  elevation[1].loadFromFile("./assets/charge_2.png");
  elevation[2].loadFromFile("./assets/charge_3.png");
  elevation[3].loadFromFile("./assets/charge_4.png");

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

  assets.multipleT.loadFromFile("./assets/Goku_1.png");
  assets.font.loadFromFile("./assets/font.ttf");

  textures.resize(8);
  textures[e_resources::Food].loadFromFile("./assets/Food.png");
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

  if (x < 0 || y < 0 || x >= map.width || y >= map.height)
    return;

  sf::Text		text;
  sf::RectangleShape	drawer;

  // Text
  text.setFont(assets.font);
  text.setCharacterSize(30);

  // Hover
  drawer.setTexture(&(assets.hoverT));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(x * spriteSize, y * spriteSize);
  drawer.setFillColor(sf::Color(255, 255, 255, 128));
  window.draw(drawer);
  drawer.setFillColor(sf::Color(255, 255, 255, 255));

  int off = 0;
  int off2 = 0;
  drawer.setSize(sf::Vector2f(100, 100));
  for (int i = 0; i < 7; i++)
    {
      if (map.arr[x][y].resources[i] > 0)
	{
	  // Resource Image
	  drawer.setTexture(&(texturesLarge[i]));
	  drawer.setPosition(WINDOW_SIZE + (off * 100),  800 + (off2 * 100));
	  window.draw(drawer);

	  // Resource count text

	  text.setFillColor(sf::Color(255,255,255));
    text.setOutlineThickness(1.0f);
    text.setOutlineColor(sf::Color(0, 0, 0));
    	  text.setPosition(WINDOW_SIZE + (off * 100) + 70,  800 + (off2 * 100) + 70);
	  text.setString(std::to_string(map.arr[x][y].resources[i]));
	  window.draw(text);

	  off++;
	  if (off == 5)
	    {
	      off2++;
	      off = 0;
	    }
	}
    }
}

void	Graphic::getSelectedPlayer()
{
  int x = mouse.getPosition(window).x / spriteSize;
  int y = mouse.getPosition(window).y / spriteSize;
  int	i = 0;

  if (x < 0 || y < 0 || x >= map.width || y >= map.height)
    return;
  for (std::vector<t_team>::const_iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::const_iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  if (it2->X == x && it2->Y == y)
	    {
	      selectedPlayer.id = it2->id;
	      selectedPlayer.team = i;
	      return;
	    }
	}
      i++;
    }
  selectedPlayer.id = -1;
  selectedPlayer.team = -1;

}

void	Graphic::eventManager()
{
  while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
	  window.close();
	  exit(0);
	}
      if (event.mouseButton.button == sf::Mouse::Left)
	  getSelectedPlayer();
    }
}

void	Graphic::initWindow()
{
  this->settings.antialiasingLevel = 8;
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
      //map.arr[2][2].incantation = true;
      eventManager();
      window.clear();
      printMap();
      printPlayers();
      printInfo();
      printPlayerInfo();
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
  sf::RectangleShape    drawer2;
  int			level;

  level = player.L - 1;

  if (level > 2)
    level = 2;
  if (team > 4)
    team = team % 4;

  drawer.setTexture(&(characters[team][level]));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(player.X * spriteSize, player.Y * spriteSize);
  window.draw(drawer);


  drawer2.setTexture(&(assets.directionT));
  drawer2.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer2.setPosition((player.X * spriteSize) + spriteSize/2, (player.Y * spriteSize) + spriteSize/2);
  drawer2.setOrigin(spriteSize/2, spriteSize/2);
  drawer2.setRotation(player.dir * 90);
  drawer2.setFillColor(sf::Color(255, 255, 255, 128));
  window.draw(drawer2);
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

void		Graphic::drawPlayerInfo(t_player const & player, int team)
{
  sf::RectangleShape    drawer;
  sf::Text              text;
  int                   level;

  level = player.L - 1;

  if (level > 2)
    level = 2;
  if (team > 4)
    team = team % 4;
    //IMAGE
  drawer.setTexture(&(characters[team][level]));
  drawer.setSize(sf::Vector2f(320, 320));
  drawer.setPosition(WINDOW_SIZE, 480);
  window.draw(drawer);

  //TEXT
  text.setFont(assets.font);
  text.setCharacterSize(30);
  text.setFillColor(sf::Color(255,50,0));
  text.setOutlineThickness(1.0f);
  text.setOutlineColor(sf::Color(0, 0, 0));


  text.setPosition(WINDOW_SIZE + 350,  550);
  text.setString(player.teamName);
  window.draw(text);

  text.setFillColor(sf::Color(255,100,0));
  text.setPosition(WINDOW_SIZE + 350,  600);
  text.setString("Level " + std::to_string(player.L));
  window.draw(text);

  text.setFillColor(sf::Color(255,150,0));
  text.setPosition(WINDOW_SIZE + 350,  650);
  text.setString("x:" + std::to_string(player.X) + " y:" + std::to_string(player.Y));
  window.draw(text);
}

void                  Graphic::printPlayerInfo()
{
  int	i = 0;
  if (selectedPlayer.id == -1)
    return;
  for (std::vector<t_team>::const_iterator it = teams.begin(); it != teams.end(); ++it)
    {
      for (std::vector<t_player>::const_iterator it2 = it->players.begin();
	   it2 != it->players.end(); ++it2)
	{
	  if (i == this->selectedPlayer.team && it2->id == this->selectedPlayer.id)
	    {
	      drawPlayerInfo(*it2, i);
	      return;
	    }
	}
      i++;
    }
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

int       Graphic::getMaxLevel(int team)
{
  int     max = 0;
    for (unsigned int i = 0;i < teams[team].players.size();i++)
    {
      if (teams[team].players[i].L > max)
        max = teams[team].players[i].L;
    }
  return max;
}


void    Graphic::printInfo()
{
  sf::Text		text;
  sf::RectangleShape	drawer;

  window.draw(assets.infoBackground);
  window.draw(assets.logo);

  text.setFont(assets.font);

  // Frequency Text

  text.setCharacterSize(20);

  text.setFillColor(sf::Color(255, 90, 0));
  text.setOutlineThickness(1.0f);
  text.setOutlineColor(sf::Color(0, 0, 0));
  text.setPosition(WINDOW_SIZE  + 25, 180);
  text.setString("Frequency : " + std::to_string(frequency));
  window.draw(text);

  // Teams text
  /*
  text.setCharacterSize(40);
  text.setFillColor(sf::Color(255, 50, 0));
  text.setPosition(WINDOW_SIZE  + 10, 216);
  text.setString("TEAMS");
  window.draw(text);

  text.setFillColor(sf::Color(255, 150, 0));
  text.setPosition(WINDOW_SIZE  + 10, 220);
  text.setString("TEAMS");
  window.draw(text);

  text.setCharacterSize(15);
  text.setFillColor(sf::Color(255, 150, 0));
  text.setPosition(WINDOW_SIZE  + 330, 230);
  text.setString("Players");
  window.draw(text);

  text.setPosition(WINDOW_SIZE  + 420, 230);
  text.setString("Max lvl");
  window.draw(text);

  */
  text.setCharacterSize(35);

  for (unsigned int i = 0; i < teams.size();i++)
    {

      text.setFillColor(sf::Color(255, 200, 0));
      text.setPosition(WINDOW_SIZE  + 60, 230 + ((i + 1) * 40));
      text.setString(teams[i].teamName);
      window.draw(text);

      text.setFillColor(sf::Color(255, 250, 0));
      text.setPosition(WINDOW_SIZE  + 350, 230 + ((i + 1) * 40));
      text.setString(std::to_string(teams[i].players.size()));
      window.draw(text);

      text.setFillColor(sf::Color(255, 250, 0));
      text.setPosition(WINDOW_SIZE  + 445, 230 + ((i + 1) * 40));
      text.setString(std::to_string(getMaxLevel(i)));
      window.draw(text);

      drawer.setTexture(&(characters[i][0]));
      drawer.setSize(sf::Vector2f(38, 38));
      drawer.setPosition(WINDOW_SIZE  + 10, 230 + ((i + 1) * 40));
      window.draw(drawer);

    }
}

void	Graphic::printEgg(int x, int y)
{
    sf::RectangleShape	drawer;

  drawer.setTexture(&(assets.eggT));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(x * spriteSize, y * spriteSize);
  window.draw(drawer);
}

void	Graphic::animateElevation(int x, int y, int n)
{
  sf::RectangleShape	drawer;

  drawer.setTexture(&(elevation[n % 4]));
  drawer.setSize(sf::Vector2f(spriteSize, spriteSize));
  drawer.setPosition(x * spriteSize, y * spriteSize);
  window.draw(drawer);
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
	  if (map.arr[x][y].eggs.size() > 0)
	    printEgg(x, y);
	  if (map.arr[x][y].incantation)
	    animateElevation(x, y, map.arr[x][y].n);
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

void                  Graphic::addEgg(int egg_id, int x, int y)
{
  if (x > map.width || y > map.height)
    return;
  t_egg			egg;

  egg.id = egg_id;
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

void                  Graphic::startIncantation(int x, int y)
{
  map.arr[x][y].incantation = true;
}

void                  Graphic::endIncantation(int x, int y)
{
  map.arr[x][y].incantation = false;
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
