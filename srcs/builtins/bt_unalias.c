/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_unalias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:00:29 by apruvost          #+#    #+#             */
/*   Updated: 2019/06/07 15:32:06 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		bt_unalias(char **av)
{
	t_alias	*alias;
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	alias = ft_get_alias();
}