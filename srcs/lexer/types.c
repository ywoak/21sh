/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleduc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:21:37 by aleduc            #+#    #+#             */
/*   Updated: 2019/03/12 17:21:39 by aleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	set_tab_types(t_ptrf **fptr)
{
	(*fptr) = (t_ptrf *)ft_memalloc(sizeof(t_ptrf) * 34);
	(*fptr)[0].str = "(";
	(*fptr)[0].f = &lpar;
	(*fptr)[1].str = ")";
	(*fptr)[1].f = &rpar;
	(*fptr)[2].str = "[";
	(*fptr)[2].f = &lbracket;
	(*fptr)[3].str = "]";
	(*fptr)[3].f = &rbracket;
	(*fptr)[4].str = "{";
	(*fptr)[4].f = &lbrace;
	(*fptr)[5].str = "}";
	(*fptr)[5].f = &rbrace;
	(*fptr)[6].str = "&";
	(*fptr)[6].f = &ampersand;
	(*fptr)[7].str = "&&";
	(*fptr)[7].f = &dampersand;
	(*fptr)[8].str = "|";
	(*fptr)[8].f = &spipe;
	(*fptr)[9].str = "||";
	(*fptr)[9].f = &dpipe;
	(*fptr)[10].str = ";";
	(*fptr)[10].f = &scolon;
	(*fptr)[11].str = ";;";
	(*fptr)[11].f = &dscolon;
	(*fptr)[12].str = "<";
	(*fptr)[12].f = &less;
	(*fptr)[13].str = "<<";
	(*fptr)[13].f = &dless;
	(*fptr)[14].str = "<&";
	(*fptr)[14].f = &lessamp;
	(*fptr)[15].str = "<<-";
	(*fptr)[15].f = &dlesshyph;
	(*fptr)[16].str = ">";
	(*fptr)[16].f = &great;
	(*fptr)[17].str = ">>";
	(*fptr)[17].f = &dgreat;
	(*fptr)[18].str = ">|";
	(*fptr)[18].f = &greatpipe;
	(*fptr)[19].str = ">&";
	(*fptr)[19].f = &greatamp;
	(*fptr)[20].str = "<>";
	(*fptr)[20].f = &lessgreat;
	(*fptr)[21].str = "'";
	(*fptr)[21].f = &squote;
	(*fptr)[22].str = "\"";
	(*fptr)[22].f = &dquote;
	(*fptr)[23].str = "`";
	(*fptr)[23].f = &tquote;
	(*fptr)[24].str = "~";
	(*fptr)[24].f = &tilde;
	(*fptr)[25].str = "$";
	(*fptr)[25].f = &dollars;
	(*fptr)[26].str = "*";
	(*fptr)[26].f = &asterix;
	(*fptr)[27].str = "#";
	(*fptr)[27].f = &hashtag;
	(*fptr)[28].str = "/";
	(*fptr)[28].f = &slash;
	(*fptr)[29].str = "\\";
	(*fptr)[29].f = &backslash;
	(*fptr)[30].str = "\n";
	(*fptr)[30].f = &newline;
	(*fptr)[31].str = "\t";
	(*fptr)[31].f = &tab;
	(*fptr)[32].str = " ";
	(*fptr)[32].f = &space;
	(*fptr)[33].str = "\0";
	(*fptr)[33].f = NULL;
}
