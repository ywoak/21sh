/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <sbelondr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:36:44 by sbelondr          #+#    #+#             */
/*   Updated: 2019/05/16 15:28:51 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
** Gerer l'environnement vide
** env -i dd=ff
*/

static int	ft_simple_command_r(char **argv, t_redirection *r)
{
	int	verif;

	if ((verif = is_builtin(argv, r)) == -1)
		verif = exec_fork(argv, r);
	return (verif);
}

static int	builtin_env_display(t_redirection *r)
{
	t_env	*lst;
	t_env	*my_env;

	my_env = get_env(0, NULL);
	lst = my_env;
	while (lst->next)
	{
		if (lst->see_env == 1)
			ft_dprintf(r->out, "%s=%s\n", lst->key, lst->value);
		lst = lst->next;
	}
	return (0);
}

// static void	blt_env_opt_i(t_env **my_env)
// {
// 	free_env(&(*my_env));
// }

static int	builtin_env_s(t_redirection *r, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	pid = fork();
	if (pid == 0)
	{
		while (argv[++i])
		{
			if (ft_strchr_exist(argv[i], '='))
				edit_set_command_env(argv[i]);
			else if (ft_strchr_exist(argv[i], '>') == 0 ||
					ft_strchr_exist(argv[i], '<') == 0)
				break ;
		}
		if (!argv[i])
			builtin_env_display(r);
		else
			ft_simple_command_r(argv + i, r);
		execve("/bin/test", NULL, NULL);
		exit(pid);
	}
	return (pid);
}

int			builtin_env(t_redirection *r, char **argv)
{
	int	pid;
	int	rt;

	pid = builtin_env_s(r, argv);
	while (wait(&rt) != -1)
		continue ;
	return (rt);
}

int			builtin_set(t_redirection *r)
{
	int		i;
	char	**lst_env;

	lst_env = create_list_env(get_env(0, NULL), 0);
	i = -1;
	while (lst_env[++i])
		ft_dprintf(r->out, "%s\n", lst_env[i]);
	if (i == 0)
		ft_dprintf(r->error, "You are nothing value in env\n");
	ft_arraydel(&lst_env);
	return (0);
}
