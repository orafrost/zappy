//
// AI.hpp for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/graphic/include
//
// Made by kerma
// Login   <kerma@epitech.net>
//
// Started on  Wed Jun 28 17:41:22 2017 kerma
// Last update Sun Jul  2 13:00:59 2017 kerma
//

#ifndef AI_HPP_
# define AI_HPP_

# include "Commands.hpp"
class Commands;

class	AI
{  
private:
  Commands	*_sender;

public:
  void		SetSender(Commands *sender);
  
public:
  AI();
  ~AI();
};

#endif
