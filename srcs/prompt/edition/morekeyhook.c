/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morekeyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellaic <mbellaic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:18:42 by aleduc            #+#    #+#             */
/*   Updated: 2019/04/05 12:21:39 by mbellaic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

t_node      *backwardmod(t_node *lstcursor, t_pos *pos)
{
    if(lstcursor->next && lstcursor->key != ' ' && lstcursor->next->key == ' ')
    {
        stalk_cursor(pos);
        if (pos->column == 1)
            go_upright(pos);
        else
            ft_putstr(tgetstr("le", NULL));
            
        lstcursor = lstcursor->next;   
    }
    if (lstcursor->next && lstcursor->key == ' ')
    {
        while (lstcursor->next && lstcursor->key == ' ')
        {
            stalk_cursor(pos);
            if (pos->column == 1)
                go_upright(pos);
            else
                ft_putstr(tgetstr("le", NULL));
            lstcursor = lstcursor->next;
        }
    }
    return(lstcursor);
}

t_node      *backwardjump(t_node *lstcursor, char buffer[], t_pos *pos)
{
    if (PG_DOWN)
    {
        lstcursor = backwardmod(lstcursor, pos);
        while (lstcursor->next && lstcursor->next->key != ' ')
        {
            stalk_cursor(pos);
            if (pos->column == 1)
                go_upright(pos);
            else
                ft_putstr(tgetstr("le", NULL));
            lstcursor = lstcursor->next;
        }
    }
    return(lstcursor);
}

t_node      *forwardjump(t_node *lstcursor, char buffer[], t_pos *pos)
{
    if(PG_UP)
    {
        while (lstcursor->prev && lstcursor->key != ' ')
        {
            lstcursor = lstcursor->prev;
            stalk_cursor(pos);
            if (pos->column == pos->termsize.ws_col)
                go_downleft(pos);
            else
                ft_putstr(tgetstr("nd", NULL));
        }
        while (lstcursor->prev && lstcursor->key == ' ')
        {
            lstcursor = lstcursor->prev;
            if(pos->column == pos->termsize.ws_col)
                go_downleft(pos);
            else
                ft_putstr(tgetstr("nd", NULL));
        }

    }
    return(lstcursor);
}

t_node      *home_end(t_node *lstcursor, char buffer[], t_pos * pos)
{
    if (HOME)
    {
        while (pos->column > 1 && lstcursor->next != NULL)
        {
            ft_putstr(tgetstr("le", NULL));
            lstcursor = lstcursor->next;
            stalk_cursor(pos);
        }
    }
    if (END)
    {
       while (lstcursor->prev != NULL)
        {
            ft_putstr(tgetstr("nd", NULL));
            lstcursor = lstcursor->prev;
            stalk_cursor(pos);
        }
    }
    return (lstcursor);
}