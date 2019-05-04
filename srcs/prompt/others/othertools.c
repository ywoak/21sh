/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othertools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <mbellaic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:19:04 by aleduc            #+#    #+#             */
/*   Updated: 2019/04/17 16:52:04 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		welcome(void)
{
	ft_putstr("\033[1;32m\n");
	ft_putstr("██████╗  ██╗███████╗██╗  ██╗\n");
	usleep(150000);
	ft_putstr("╚════██╗███║██╔════╝██║  ██║\n");
	usleep(150000);
	ft_putstr(" █████╔╝╚██║███████╗███████║\n");
	usleep(150000);
	ft_putstr("██╔═══╝  ██║╚════██║██╔══██║\n");
	usleep(150000);
	ft_putstr("███████╗ ██║███████║██║  ██║\n");
	usleep(150000);
	ft_putstr("╚══════╝ ╚═╝╚══════╝╚═╝  ╚═╝\n\n");
	ft_putstr("\033[0m");
}

char		*reverse_str(char *inputstr)
{
	char	*start;
	int		len;
	char	*end;

	start = inputstr;
	len = ft_strlen(inputstr);
	end = (inputstr + len - 1);
	while (start < end )
	{
		*start = *start ^ *end;
		*end = *end ^ *start;
		*start = *end ^ *start;
		start++;
		end--;
	}
	return (inputstr);
}

t_node		*find_tail(t_node *lstcursor, t_pos *pos)
{
	int		backup;

	backup = 0;
	savecursor(pos);
	while (lstcursor->prev != NULL)
	{
		stalk_cursor(pos);
		if (pos->column != pos->termsize.ws_col)
			ft_putstr(tgetstr("nd", NULL));
		else
			go_downleft(pos);
		backup++;
		lstcursor = lstcursor->prev;
	}
	while (backup-- > 1)
		lstcursor = lstcursor->next;
	stalk_cursor(pos);
	pos->tailcolumn = pos->column;
	pos->tailrow = pos->row;
	cursorback(pos);
	return (lstcursor);
}

char		*lst_to_str(t_multi **multi, char *inputstr)
{
	t_multi	*lstcursor;
	t_node	*cpycursor;
	char	*finalstr;
	char	*temp;
	char	*trash;
	int		i;
	int		len;

	inputstr = ft_strdup("\0");
	lstcursor = *multi;
	while (lstcursor->next)
		lstcursor = lstcursor->next;
	while (lstcursor)
	{
		i = 0;
		len = 0;
		//
		cpycursor = lstcursor->input->next;
		while (cpycursor)
		{
			len++;
			cpycursor = cpycursor->next;
		}
		cpycursor = lstcursor->input->next;
		//
		temp = malloc(sizeof(char) * len + 2);
		///
		while (cpycursor)
		{
			temp[i] = cpycursor->key;
			cpycursor = cpycursor->next;
			i++;
		}
		temp[i++] = '\n';
		temp[i] = '\0';
		temp = reverse_str(temp);
		trash = inputstr;
		inputstr = ft_strjoin(inputstr, temp);
		free(temp);
		if (trash != NULL)
			free(trash);
		///
		lstcursor = lstcursor->prev;
	}
	inputstr++;
	finalstr = strdup(inputstr);
	inputstr--;
	free(inputstr);
	return (finalstr);
}
