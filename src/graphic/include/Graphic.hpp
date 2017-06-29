//
// zappy_graphic.hpp for zappy in /home/eric/tek2/zappy/graphic
// 
// Made by Eric Amilhat
// Login   <eric.amilhat@epitech.eu>
// 
// Started on  Tue Jun 20 14:09:49 2017 Eric Amilhat
// Last update Thu Jun 29 15:28:04 2017 kerma
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

#define WINDOW_SIZE 1024
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
  e_dir		O;
  int		L;
  int		id;
  std::string	teamName;
  e_resources	resources[7];
}               t_player;

typedef struct	s_team
{
  std::string		teamName;
  std::vector<t_player>	players;
}		t_team;

typedef struct s_block
{
  std::vector<t_player *>	players;
  int				resources[7];
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
  sf::Texture		backgroundT;
  sf::Sprite		background;
  sf::Font		font;
}			t_assets;

class Graphic
{
private:
  std::vector<sf::Texture>  textures;
  std::vector<t_team>	teams;
  t_map		        map;
  bool			mapIsSized = false;
  sf::RenderWindow      window;
  sf::Event		event;
  sf::Mouse		mouse;
  t_assets		assets;
  int			spriteSize = 0;
  int			Error(const std::string &err) const;
  void			eventManager();
  int			sumOfBlock(int x, int y) const;
  void			drawSprite(int ressource, int x, int y);
  void			drawMultiple(int x, int y);
  void			expandTile();
public:
  Graphic();
  ~Graphic();
  void		        update();
  void			printMap();
  void			setMapDimensions(int width, int height);
};

#endif 
