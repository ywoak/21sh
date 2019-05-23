/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <sbelondr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:01:05 by sbelondr          #+#    #+#             */
/*   Updated: 2019/05/23 12:06:34 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef BUILTINS_H
#	define BUILTINS_H

#include "env.h"

typedef struct		s_cd
{
	int		arg__;
	char	*directory;
	char	*curpath;
}					t_cd;

int					bt_exit(char **av);
int					bt_echo(char **av, t_redirection *r);

/*
** bt_jobs.c
*/

int					bt_jobs(t_redirection *r);
int					bt_bg(t_redirection *r);
int					bt_fg(t_redirection *r);

#	endif
