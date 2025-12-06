/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:08:35 by theo              #+#    #+#             */
/*   Updated: 2025/12/06 23:20:05 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	tokenizer_squotes(char *cmd_line, int start, t_minishell *minishell)
{
	int	index;

	index = start;
}

static int	tokenizer_dquotes(char *cmd_line, int start, t_minishell *minishell)
{
	int	in_dquotes;
	int	index;

	in_dquotes = 0;
	index = start;
	printf("%s\n", cmd_line);
	while (cmd_line[index])
	{
		if (cmd_line[index] == '"')
			in_dquotes = !in_dquotes;
		if (is_separator(cmd_line, index) && in_dquotes == 1)
			break ;
		if (cmd_line[index] != '"')
			write (1, cmd_line + index, 1);
		index ++;
	}
	if (in_dquotes == 1)
	{
		printf("%d", in_dquotes);
		printf("Error: a double quote must be closed");
		return (0);
	}
	return (1);
}

int	tokenizer(char *cmd_line, t_minishell *minishell)
{
	int	index;

	index = 0;
	// while (cmd_line[index])
	// {
	// 	if (cmd_line[index] == '"')
	// 		tokenizer_dquotes(cmd_line, index, minishell);
	// 	if (cmd_line[index] == 39);
	// 		tokenizer_squotes(cmd_line, index, minishell);
	// 	index ++;
	// }
	tokenizer_dquotes(cmd_line, 0, NULL);
}
