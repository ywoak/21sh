#include "lexer.h"

t_lex	*dlldelfirst(t_lex **head)
{
	t_lex	*todel;

	todel = *head;
	(*head)->next->prev = NULL;
	*head = (*head)->next;
	todel->next = NULL;
	todel->prev = NULL;
	return (todel);
}


t_lex	*dlldellast(t_lex **tail)
{
	t_lex	*todel;

	todel = *tail;
	(*tail)->prev->next = NULL;
	*tail = (*tail)->prev;
	todel->next = NULL;
	todel->prev = NULL;
	return (todel);
}

t_lex 	*dlldelone(t_lex **head, char *data)
{
	t_lex	*ptr;
	t_lex	*todel;

	todel = NULL;
	ptr = *head;
	while (ptr)
	{
		if (ft_strcmp(ptr->token->data, data) == 0)
			todel = ptr;
		ptr = ptr->next;
	}
	return (todel);
}

void	dll_del_node(t_lex **node)
{
	(*node)->prev = NULL;
	(*node)->next = NULL;
	ft_memdel((void **)node);
}
