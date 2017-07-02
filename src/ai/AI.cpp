//
// AI.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Sun Jul  2 21:56:48 2017 kerma
//

#include "AI.hpp"

AI::AI() {
  _wait = true;
  this->_inventaire[0] = 10;
  for (int a = 1; a < 7; a++)
  {
    this->_inventaire[a] = 0;
  }
  this->_level = 0;
  for (int a = 0; a < 7;  a++)
  {
    for(int b = 0; b < 8; b++)
    {
      this->_step[a][b] = 0;
    }
  }
  this->_step[0][0] = 1;
  this->_step[0][1] = 1;
  this->_step[1][0] = 3;
  this->_step[1][1] = 1;
  this->_step[1][2] = 1;
  this->_step[1][3] = 1;
  this->_step[2][0] = 2;
  this->_step[2][1] = 2;
  this->_step[2][3] = 1;
  this->_step[2][5] = 2;
  this->_step[3][0] = 4;
  this->_step[3][1] = 1;
  this->_step[3][2] = 1;
  this->_step[3][3] = 2;
  this->_step[3][5] = 1;
  this->_step[4][0] = 4;
  this->_step[4][1] = 1;
  this->_step[4][2] = 2;
  this->_step[4][3] = 1;
  this->_step[4][4] = 3;
  this->_step[5][0] = 6;
  this->_step[5][1] = 1;
  this->_step[5][2] = 2;
  this->_step[5][3] = 3;
  this->_step[5][5] = 1;
  this->_step[6][0] = 6;
  this->_step[6][1] = 2;
  this->_step[6][2] = 2;
  this->_step[6][3] = 2;
  this->_step[6][4] = 2;
  this->_step[6][5] = 2;
  this->_step[6][6] = 1;
}

AI::~AI() {}

void	AI::SetSender(Commands *sender) { _sender = sender; }
void	AI::SetWait() { _wait = false; }

void AI::reset(const std::string &arg)
{
  static_cast<void>(arg);
  _wait = false;
}

void AI::getVision(const std::string &arg)
{
  _vision = arg;
  this->reset(arg);
}

int AI::findNbElem(std::string elem) const
{
  std::istringstream st(_vision);
  std::string chunck;
  std::size_t  found;
  int  a;

  a = 0;
  found = 0;
  while ((found = chunck.find(elem, found)))
    {
      a += 1;
    }
  return a;
}

int    AI::resource() const
{
  bool	high = false;
  std::string name[7];

  name[0] = "linemate";
  name[1] = "deraumere";
  name[2] = "sibur";
  name[3] = "mendiane";
  name[4] = "phiras";
  name[5] = "thystane";
  for (int a = 0; a < 6; a++)
    {
      int nb = findNbElem(name[a]);
      if (nb > _step[_level - 1][a + 1])
	high = true;
      else if (nb  + _inventaire[a + 1] < _step[_level - 1][a + 1])
	return (0);
    }
  if (high == true)
    return (1);
  return (2);
}

void AI::clean()
{
  std::string name[7];

  name[0] = "linemate";
  name[1] = "deraumere";
  name[2] = "sibur";
  name[3] = "mendiane";
  name[4] = "phiras";
  name[5] = "thystane";
  if (findNbElem("food") > 1)
  {
    _sender->SendTAKE("food");
    _wait = true;
    return ;
  }
  for (int a = 0; a < 6; a++)
  {
      int nb = findNbElem(name[a]);
      if (nb > _step[_level][a + 1])
      {
        _sender->SendTAKE(name[a]);
        _wait = true;
        return ;
      }
      if (nb < 0 && _inventaire[a + 1] > 1)
      {
        _sender->SendSET(name[a]);
        _wait = true;
        return ;
      }
  }
}

void AI::forward()
{
  _sender->SendFORWARD();
  _wait = true;
}

void AI::up()
{
  _sender->SendINCANTATION();
  _wait = true;
}

void AI::vision()
{
  _sender->SendLOOK();
  _wait = true;
}

bool AI::wait() const
{
  return _wait;
}
