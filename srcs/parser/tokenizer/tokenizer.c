/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbouver <thbouver@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:08:35 by theo              #+#    #+#             */
/*   Updated: 2025/12/07 18:02:50 by thbouver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	string_cleaner(char *string, t_minishell *minishell)
{
	int	in_quotes;
	int	in_dquotes;
	int	index;

	index = 0;
	in_dquotes = 0;
	in_quotes = 0;
	ft_printf("Before : %s\n", string);
	ft_printf("[");
	while (string[index])
	{
		if (string[index] == '"' || string[index] == 39)
		{
			if (string[index] == '"' && in_quotes == 0)
				in_dquotes = !in_dquotes;
			if (string[index] == 39 && in_dquotes == 0)
				in_quotes = !in_quotes;
		}
		if ((string[index] == '"' && in_quotes == 1)
			|| (string[index] == 39 && in_dquotes == 1)
			|| string[index] != '"' && string[index] != 39)
		{
			write (1, string + index, 1);
		}
		index ++;
	}
	ft_printf("]\n\n");
	return (1);
}

static int	string_tokenizer(char *cmd_line, int index, t_minishell *minishell)
{
	char	*string;
	int		in_quotes;
	int		in_dquotes;
	int		current;

	current = index;
	in_quotes = 0;
	in_dquotes = 0;
	while (cmd_line[index])
	{
		if (cmd_line[index] == '"' || cmd_line[index] == 39)
		{
			if (cmd_line[index] == '"' && in_quotes == 0)
				in_dquotes = !in_dquotes;
			if (cmd_line[index] == 39 && in_dquotes == 0)
				in_quotes = !in_quotes;
		}
		if (is_separator(cmd_line, index) && in_quotes == 0 && in_dquotes == 0)
			break ;
		index ++;
	}
	string = ft_substr(cmd_line, current, (index - current));
	if (!string)
		return (-1);
	string_cleaner(string, minishell);
	return (index);
}

int	tokenizer(char *cmd_line, t_minishell *minishell)
{
	int	index;

	index = 0;
	while (cmd_line[index])
	{
		if (cmd_line[index] == '"' || cmd_line[index] == 39 || !is_separator(cmd_line, index))
				index = string_tokenizer(cmd_line, index, minishell);
		else
			index ++;
	}
}
