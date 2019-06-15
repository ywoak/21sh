/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <sbelondr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 23:23:34 by sbelondr          #+#    #+#             */
/*   Updated: 2019/05/17 14:02:50 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int		send_dev_null(void)
{
	int	fd;

	fd = file_exist("/dev/null");
	if (fd > -1)
		fd = open("/dev/null", O_RDWR);
	return (fd);
}

t_redirection	*init_redirection(void)
{
	t_redirection	*r;

	if (!(r = (t_redirection*)malloc(sizeof(t_redirection) * 1)))
		return (NULL);
	r->in = STDIN_FILENO;
	r->out = STDOUT_FILENO;
	r->error = STDERR_FILENO;
	r->fd_pipe = -1;
	r->redirect = ft_init_redirect();
	return (r);
}

static void		ft_apply_redirection(t_lex *h, t_redirection *r)
{
	int	num_src;
	int	num_dest;

	num_src = ft_atoi(h->redir->src_fd[0]);
	num_dest = h->redir->dest_fd ? ft_atoi(h->redir->dest_fd) : -1;
	if (num_dest == -1)
		num_dest = send_dev_null();
	if (num_src == STDIN_FILENO)
	{
		r->in = num_dest;
		ft_create_maillon_redirect(r->redirect, STDIN_FILENO, num_dest);
	}
	else if (num_src == STDOUT_FILENO)
	{
		r->out = num_dest;
		ft_create_maillon_redirect(r->redirect, STDOUT_FILENO, num_dest);
	}
	else if (num_src == STDERR_FILENO)
	{
		r->error = num_dest;
		ft_create_maillon_redirect(r->redirect, STDERR_FILENO, num_dest);
	}
}

t_redirection	*fill_redirection(t_token *t)
{
	t_lex			*h;
	t_redirection	*r;

	h = t->command;
	r = init_redirection();
	while (h)
	{
		if (h->token->type == REDIR && h->redir)
			ft_apply_redirection(h, r);
		h = h->next;
	}
	return (r);
}

void			delete_redirection(t_redirection **r)
{
	t_redirect	*next;

	next = NULL;
	while ((*r)->redirect)
	{
		next = ((*r)->redirect->next) ? (*r)->redirect->next : NULL;
		free((*r)->redirect);
		(*r)->redirect = NULL;
		if (next)
			(*r)->redirect = next;
	}
	free(*r);
	(*r) = NULL;
}