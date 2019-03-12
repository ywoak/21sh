#include "libft.h"

t_dlist	*ft_dlstdelfirst(t_dlist **head)
{
	t_dlist	*todel;

	todel = *head;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	todel->next = NULL;
	todel->prev = NULL;
	return (todel);
}


t_dlist	*ft_dlstdellast(t_dlist **tail)
{
	t_dlist	*todel;

	todel = *tail;
	(*tail)->prev->next = NULL;
	*tail = (*tail)->prev;
	todel->next = NULL;
	todel->prev = NULL;
	return (todel);
}

t_dlist *ft_dlstdelone(t_dlist **head, void *data)
{
	t_dlist	*ptr;
	t_dlist	*todel;

	todel = NULL;
	ptr = *head;
	while (ptr)
	{
		if (ft_strcmp((char *)ptr->data, (char *)data))
			todel = ptr;
		ptr = ptr->next;
	}
	return (todel);
}
