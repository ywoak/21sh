/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:00:16 by apruvost          #+#    #+#             */
/*   Updated: 2019/06/11 14:04:11 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static t_alias	g_ht_deleted = {NULL, NULL};
extern t_ht_alias	*g_alias_table;

static int			bt_alias_show(void)
{
	int	i;

	if (g_alias_table == NULL)
		return (1);
	i = 0;
	while (i < g_alias_table->size)
	{
		if (g_alias_table->alias[i] != NULL
								&& g_alias_table->alias[i] != &g_ht_deleted)
			ft_printf("%s=%s\n", g_alias_table->alias[i]->key,
								g_alias_table->alias[i]->value);
		++i;
	}
	return (0);
}

static int			bt_showalias(char **av, int i, int ret)
{
	char	*val;

	val = ht_alias_search(g_alias_table, av[i]);
	if (val == NULL)
		return (1);
	ft_printf("%s=%s\n", av[i], val);
	return (ret);
}

static void				bt_addalias(char **av, int i)
{
	char	*tmp;
	t_alias *curr;

	tmp = ft_strchr('=', av[i]);
	*tmp = '\0';
	ht_alias_insert(g_alias_table, av[i], &(tmp[1]));
	*tmp = '=';
}

int					bt_alias(char **av)
{
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	if (!av[1])
		ret = bt_alias_show();
	while (av[i])
	{
		if (ft_strchr_exist('=', av[i]))
			bt_addalias(av, i);
		else
			ret = bt_showalias(av, i, ret);
		++i;
	}
	return (ret);
}
