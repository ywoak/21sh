/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deplace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:04:53 by sbelondr          #+#    #+#             */
/*   Updated: 2019/04/08 11:05:56 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilib.h"

/*
** deplace |0123
**         |00123
*/

void	ft_deplace(char (*lst)[BUF_S])
{
	int		i;

	i = ft_strlen(*lst);
	while (--i >= 0)
		(*lst)[i + 1] = (*lst)[i];
	(*lst)[0] = '0';
}