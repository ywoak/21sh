#include "parser.h"

int				get_argc(t_lex *cursor)
{
	int len;

	len = 0;
	while (cursor)
	{
		if(cursor->token->type == WORD || cursor->token->type == NUMBER)
			len++;
		ft_putstr(cursor->token->data);
		ft_putstr(" ->");
		cursor = cursor->next;
	}
	ft_putstr("\n");
	return (len);
}
char			**get_argv(t_lex *cmd_list)
{
	char **argv;
	t_lex *cursor;
	int len;
	int i;

	i = 0;
	cursor = cmd_list->next->token->command; // REMEMBER TO CHANGE IT SO IT MAKES SENSE IN THE INTERPRETER
	len = get_argc(cursor);
	if(!(argv = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while(cursor)
	{
		if(cursor->token->type == WORD || cursor->token->type == NUMBER)
			argv[i++] = ft_strdup(cursor->token->data);
		cursor = cursor->next;
	}
	return (argv);
}

void			files_handler(t_lex *cmd_list, t_pos *pos)
{
	t_lex *cursor;

	cursor = cmd_list->next->token->command; // HERE TOO
	while(cursor)
	{
		if (cursor->token->type == REDIR)
				open_file_std(cursor->redir, pos);
		cursor = cursor->next;
	}
}

int			*run(t_lex *cmd_list, t_pos *pos)
{
	char	**argv;

	argv = get_argv(cmd_list);
	files_handler(cmd_list, pos);
	ft_simple_command(argv, cmd_list);
}
