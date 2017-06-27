/*
** buffer.c for zappy in /home/kerma/Projets/Epitech/PSU/zappy/src/server/sock
**
** Made by kerma
** Login   <kerma@epitech.net>
**
** Started on  Mon Jun 26 22:13:34 2017 kerma
** Last update Tue Jun 27 20:27:08 2017 kerma
*/

#include "zappy.h"

static t_buffer	*init_msg(char *msg)
{
  t_buffer	*new;

  if ((new = malloc(sizeof(t_buffer))) == NULL)
    return (pputerr("Function \'malloc\' failed."));
  if ((new->msg = strdup(msg)) == NULL)
    return (pputerr("Function \'strdup\' failed."));
  new->next = NULL;
  return (new);
}

void		free_buffer(t_buffer *buffer)
{
  while (buffer != NULL)
    del_msg(&buffer);
}

void		del_msg(t_buffer **buffer)
{
  t_buffer	*tmp;

  if ((tmp = *buffer) != NULL)
    {
      *buffer = (*buffer)->next;
      free(tmp->msg);
      free(tmp);
    }
}

int		add_msg(t_buffer **buffer, char *msg)
{
  t_buffer	*tmp;
  t_buffer	*new;

  if ((new = init_msg(msg)) == NULL)
    return (ERROR);
  if (*buffer == NULL)
    {
      *buffer = new;
      return (0);
    }
  tmp = *buffer;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (0);
}
