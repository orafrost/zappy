//
// AI.cpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:40:38 2017 kerma
// Last update Sun Jul  2 17:57:05 2017 Guillaume Verrier
//

#include "AI.hpp"

AI::AI() {
  _wait = false;
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

int AI::findNbElem(std::string elem)
{
  std::istringstream st(_vision);
  std::string chunck;
  std::size_t  found;
  int  a;

  a = 0;
  found = 0;
  while ((found = chunck.find(elem, found))
  {
    a += 1;
  }
  return a;
}

void   AI::find_food()
{
  int pos = this->find_elem("food");

  _wait = true;
  if (pos != 0)
  {
    _sender.SendFORWARD()
  }
  else
  {
    _sender.SendTAKE("food");
  }
}

int AI::find_miss()
{
  for (int a = 1; a < 7; a++)
  {
    if (_step[_level - 1][a] != _inventaire[a])
      return a;
  }
  return -1;
}

void AI::find_resources()
{
  int miss;

  miss = find_miss();
  if (miss == -1)
    return false;
}

void AI::folow()
{

}

void AI::up()
{
}

void  AI::nbPers()
{
  std::istringstream st(_vision);
  std::string chunck;
  std::size_t found;
  int  a = 0;

  std::getline(st, chunck, ',');
  found = 0;
  while ((found = chunck.find("player", found))
  {
    a += 1;
  }
  return a;
}

void AI::sendVision()
{
  _sender->SendLOOK();
}

bool    SetMode(enum AI::AiMode md)
{
  if (_wait == true)
    return false;
  _mode = md;
  return true;
}

bool check_case()
{
  for (int a = 1; a < 7; a++)
  {
    _start[_level - 1][a]
  }
}

void actMode()
{

}
