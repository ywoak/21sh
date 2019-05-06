/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_end_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelondr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:48:31 by sbelondr          #+#    #+#             */
/*   Updated: 2019/05/06 05:04:56 by sbelondr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <fcntl.h>

int		get_end_line(char *file)
{
	int		fd;
	int		verif;
	char	*str;

		printf("verif = \n");
	fd = open(file, O_RDWR);
	verif = 0;
	while ((verif = get_next_line(fd, &str)) > 0)
		ft_strdel(&str);
	return (fd);
}
