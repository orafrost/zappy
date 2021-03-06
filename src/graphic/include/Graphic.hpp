//
// zappy_graphic.hpp for zappy in /home/eric/tek2/zappy/graphic
//
// Made by Eric Amilhat
// Login   <eric.amilhat@epitech.eu>
//
// Started on  Tue Jun 20 14:09:49 2017 Eric Amilhat
// Last update Sun Jul  2 21:36:01 2017 Guillaume Verrier
//

#ifndef GRAPHIC_HPP_
# define GRAPHIC_HPP_

#include <list>
#include <iostream>
#include <alloca.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define WINDOW_SIZE 1000
#define EMPTY 7

typedef enum    e_dir
  {
    UP          = 0,
    RIGHT       = 1,
    DOWN        = 2,
    LEFT        = 3
  }             e_dir;

typedef enum    e_resources
  {
    Food = 0,
    Linemate = 1,
    Deraumere = 2,
    Sibur = 3,
    Mendiane = 4,
    Phiras = 5,
    Thystame = 6,
  }             e_resources;

typedef struct s_player
{
  int           X;
  int		Y;
  e_dir		dir;
  int		L;
  int		id;
  std::string	teamName;
}               t_player;

typedef struct	s_team
{
  std::string		teamName;
  std::vector<t_player>	players;
}		t_team;

typedef struct  s_egg
{
  int		id;
}               t_egg;

typedef struct s_block
{
  std::vector<t_egg>		eggs;
  int				resources[7];
  float				n = 0;
  bool				incantation = false;
}		t_block;

typedef struct				s_map
{
  int					width;
  int					height;
  std::vector<std::vector<t_block>>	arr;
}					t_map;

typedef struct		s_assets
{
  sf::Texture	        hoverT;
  sf::Texture		multipleT;
  sf::Texture	        eggT;
  sf::Texture	        directionT;
  sf::Texture	        logoT;
  sf::Sprite		logo;
  sf::Texture	        cloudT;
  sf::Sprite		cloud;
  float			c;
  int			h;
  sf::Texture	        infoBackgroundT;
  sf::Sprite	        infoBackground;
  sf::Texture		backgroundT;
  sf::Sprite		background;
  sf::Font		font;
}			t_assets;

typedef struct                          s_playerId
{
  int					id;
  int                                   team;
}					t_playerId;

  class Graphic
{
private:
  sf::ContextSettings settings;
  std::vector<sf::Texture>  elevation;
  std::vector<sf::Texture>  textures;
  std::vector<sf::Texture>  texturesLarge;
  std::vector<std::vector<sf::Texture>>  characters;
  std::vector<t_team>	teams;
  t_map		        map;
  bool			mapIsSized;
  sf::RenderWindow      window;
  sf::Event		event;
  sf::Mouse		mouse;
  t_assets		assets;
  int			spriteSize;
  int			frequency;
  t_playerId		selectedPlayer;
  int			Error(const std::string &err) const;
  int		        getPerfectSquare(int sum);
  void			eventManager();
  int			sumOfBlock(int x, int y) const;
  void			drawPlayer(t_player const & player, int team);
  void			printPlayers();
  void			drawResource(int resource, int x , int y, int sum, int pos);
  void			expandTile();
  void			drawPlayerInfo(t_player const & player, int team);
  void		        printPlayerInfo();
  void		        printInfo();
  void			getSelectedPlayer();
  void			printEgg(int x, int y);
  void			animateElevation(int x, int y, int n);
  int       getMaxLevel(int team);
public:
  Graphic();
  ~Graphic();
  void			initWindow();
  void		        update();
  void			printMap();
  void			setBlock(int x, int y, std::vector<int> arg);
  void			setMapDimensions(int width, int height);

  void			addTeam(std::string name);
  void			addPlayer(int id, int x, int y, int dir, int level,
				  std::string teamName);
  void			setPlayerPosition(int id, int x, int y, int dir);
  void			playerBroadcast(int id);
  void			setLevel(int id, int level);
  void			setFrequence(int f);
  void			addEgg(int egg_id, int x, int y);
  void			hatchEgg(int id);
  void			addResource(int player_id, int resourceType);
  void			removeResource(int player_id, int resourceType);
  int			endGame(std::string teamName);
  void			startIncantation(int x, int y);
  void			endIncantation(int x, int y);
  void			killPlayer(int id);
};

#endif
