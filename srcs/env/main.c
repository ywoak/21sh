/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:49:50 by sbelondr          #+#    #+#             */
/*   Updated: 2019/05/03 20:32:38 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void	free_std(t_std **std)
{
	if (std && (*std))
	{
		ft_strdel(&((*std)->filename));
		free(*std);
		(*std) = NULL;
	}
}

void	free_cmd(t_cmd **cmd)
{
	if ((!cmd) || (!(*cmd)))
		return ;
	if ((*cmd)->next)
		free_cmd(&((*cmd)->next));
	free_std(&((*cmd)->in));
	free_std(&((*cmd)->out));
	free_std(&((*cmd)->err));
	ft_arraydel(&((*cmd)->argv));
	free(*cmd);
	(*cmd) = NULL;
}

int		main(int ac, char **av)
{
	t_cmd	*cmd;
	char	*testa[3] = {"cat", "-e", NULL};
	char	*testb[2] = {"wc", NULL};
	t_env	*env;
	int		i;

	if (ac == -1)
		return (0);
	i = 0;
	env = init_env();

	int	test;

	cmd = init_cmd();
	cmd->argv = ft_arraydup(av + 1);
	parser_var(&(cmd->argv), env);

	cmd->end_pipe = 0;
//	cmd->out->fd = -1;
//	cmd->out->append = 0;
//	ft_strdel(&((cmd->out->filename)));
//	cmd->out->filename = ft_strdup("cc");

	test = ft_pipe(cmd, &env);

	//ft_printf("la\n");

	cmd->next = init_cmd();
	cmd->next->argv = ft_arraydup(testa);
	parser_var(&(cmd->next->argv), env);

	cmd->next->in->fd = test;

//	cmd->next->out->fd = -1;
//	cmd->next->out->append = 0;
//	ft_strdel(&((cmd->next->out->filename)));
//	cmd->next->out->filename = ft_strdup("cc");

	cmd->next->end_pipe = 0;
	test = ft_pipe(cmd->next, &env);

	//ft_printf("laaaa\n");

	cmd->next->next = init_cmd();
	cmd->next->next->argv = ft_arraydup(testb);
	parser_var(&(cmd->next->next->argv), env);
	cmd->next->next->end_pipe = 1;
	cmd->next->next->in->fd = test;
//	cmd->next->next->out->fd = -1;
//	cmd->next->next->out->append = 0;
//	ft_strdel(&((cmd->next->next->out->filename)));
//	cmd->next->next->out->filename = ft_strdup("cc");
	ft_pipe(cmd->next->next, &env);
	

	//ft_printf("ci\n");
//	i = ft_simple_command(cmd, &env);
//	i = ft_pipe_old(cmd, 3, &env);
//	i = ft_pipe_double(cmd, &env);
//	i = ft_ampersand(cmd, 1, &env);
//	i = ft_ampersand_double(cmd, &env);
	
	gest_return(i, &env);
	if (i == -1)
		ft_dprintf(2, "21sh: command not found: %s\n", cmd->argv[0]);

	free_cmd(&cmd);
	gest_return(i, &env);
	free_env(&env);
	return (0);
}
