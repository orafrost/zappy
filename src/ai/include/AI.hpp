//
// AI.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 18:29:44 2017 Guillaume Verrier
//

#ifndef AI_HPP_
# define AI_HPP_


# include <vector>

# include "Commands.hpp"
class Commands;

enum res
{
  FOOD = 0,
  LINEMATE = 1,
  DERAUMERE = 2,
  SIBUR = 3,
  MENDIANE = 4,
  PHIRAS = 5,
  THYSTANE = 6
}

typedef bool (AI::* act)();

class	AI
{
private:
  Commands	*_sender;
  bool      _wait;
  std::string _vision;
  int       _inventaire[7];
  int       _level;
  int       _step[7][7];
  std::string vision;
  enum AiMode _mode;


public:
  void		SetSender(Commands *sender);
  int     findNbElem(std::string elem);
  int     getSomme(); //OK
  int    resource();
  void    clean();
  void    forward(); // ok
  void    up(); //OK
  void    vision(); //OK
  bool    wait(); //OK
  enum    AiMode
  {
    FEED = 0,
    FOLOW = 1,
    GET = 2,
    UP = 3

  };
public:
  AI();
  ~AI();
};

#endif
