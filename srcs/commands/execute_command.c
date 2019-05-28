/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <sbelondr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 08:43:53 by sbelondr          #+#    #+#             */
/*   Updated: 2019/05/28 10:45:27 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void		sighandler(int signum)
{
	(void)signum;
	ft_putchar('\n');
}

void		handler_ctrl_z(int sig)
{
	pid_t	pid;

	(void)sig;
	if ((pid = tcgetpgrp(STDIN_FILENO)) < 0)
		ft_dprintf(STDERR_FILENO, "Error tcgetpgrp\n");
	else
	{
		ft_printf("suite pid = %d\n", getpid());
		if (setpgid(getpid(), 0) != 0)
			ft_dprintf(STDERR_FILENO, "Error setpgid\n");
		else
		{
			if (tcsetpgrp(STDIN_FILENO, getpid()) != 0)
				ft_dprintf(STDERR_FILENO, "Error tcsetpgrp\n");
			else if ((pid = tcgetpgrp(STDIN_FILENO)) < 0)
				ft_dprintf(STDERR_FILENO, "Error tcgetpgrp 2\n");
		}
	}
	tcgetpgrp(pid);
}

/*
** in -> STDIN_FILENO
** out -> STDOUT_FILENO
** error -> STDERR_FILLENO
*/

static void	open_redirection(t_redirection *r)
{
	dup2(r->in, STDIN_FILENO);
	dup2(r->out, STDOUT_FILENO);
	dup2(r->error, STDERR_FILENO);
}

int			add_process(char **cmd, int *returns_code, t_redirection *r)
{
	char	**env;
	int		pid;

	if (is_in_path(&cmd) != 1)
	{
		(*returns_code) = -1;
		ft_dprintf(r->error, "21sh: command not found: %s\n", cmd[0]);
		return (*returns_code);
	}
	env = create_list_env(get_env(0, NULL), 0);
	ft_arraydisplay(env);
	pid = fork();
	if (pid == 0)
	{
		//signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		open_redirection(r);
		execve(cmd[0], cmd, env);
		ft_dprintf(r->error, "21sh: command not found\n");
		execve("/bin/test", NULL, NULL);
		exit(pid);
	}
	ft_arraydel(&env);
	return (pid);
}

int			exec_fork(char **cmd, t_redirection *r)
{
	int	return_code;
	int	pid;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	signal(SIGTSTP, handler_ctrl_z);
	pid = add_process(cmd, &return_code, r);
	while (wait(&return_code) != -1)
		continue ;
	if (pid != -1)
		kill(pid, SIGINT);
	//signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	return (return_code);
}


int			ft_simple_command_env(char **argv, t_redirection *r)
{
	int	verif;

	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	get_env(1, NULL);
	get_env(0, NULL);
	if ((verif = is_builtin(argv, r)) == -1)
	{
		if (r->fd_pipe == -1)
			verif = exec_fork(argv, r);
		else
			verif = add_pipe_process(argv, r);
	}
	return (verif);
}
