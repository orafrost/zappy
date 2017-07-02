//
// AI.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 21:41:11 2017 kerma
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
};


class	AI
{
public:
  enum    AiMode
  {
    FEED = 0,
    FOLOW = 1,
    GET = 2,
    UP = 3

  };

private:
  Commands	*_sender;
  bool      _wait;
  std::string _vision;
  int       _inventaire[7];
  int       _level;
  int       _step[7][7];
  enum AiMode _mode;


public:
  void	  SetWait();
  void	  SetSender(Commands *sender);
  int     findNbElem(std::string elem) const;
  int     resource() const;
  void    clean();
  void    forward(); // ok
  void    up(); //OK
  void    vision(); //OK
  bool    wait() const; //OK
  void    reset(const std::string &arg);
  void    getVision(const std::string &arg);
public:
  AI();
  ~AI();
};

#endif
