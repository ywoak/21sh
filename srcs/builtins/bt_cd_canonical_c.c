/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_cd_canonical_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apruvost <apruvost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:20:14 by apruvost          #+#    #+#             */
/*   Updated: 2019/05/07 16:28:39 by apruvost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		cd_canonical_getslash(t_cd *cd, size_t *a, size_t *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (cd->curpath[i] != '\0')
	{
		if (cd->curpath[i] == '/')
		{
			if (cd->curpath[i + j] == '/' || (cd->curpath[i + j] == '\0' && i != 0))
			{
				ft_printf("Bonsoir, trouvé '/' a %d + %d dans %s\n", i, j, cd->curpath);
				while (cd->curpath[i + j] == '/')
					j++;
				if (i == 0)
					j--;
				*a = i;
				*b = i + j;
				return (1);
			}
		}
		if (cd->curpath[i] != '\0')
			i++;
		while (cd->curpath[i] != '\0' && cd->curpath[i] != '/')
			i++;
	}
	return (0);
}

/*
** c. An implementation ma further simplify curpath b removing any trailng '/' that are not also leading '/',
**    replacing multiple consecutive '/' by a single '/', and replacing three or more leading '/' by a single '/'
*/

int		cd_canonical_c(t_cd *cd)
{
	size_t	a;
	size_t	b;
	size_t	len;

	a = 0;
	b = 0;
	while (cd_canonical_getslash(cd, &a, &b))
	{
		len = ft_strlen(cd->curpath);
		len -= b - a;
		if (!cd_canonical_del(cd, a, b, len))
		{
			dprintf(2,"21sh: cd: error malloc\n");
			return (1);
		}
	}
	return (0);
}
