/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:35:07 by theo              #+#    #+#             */
/*   Updated: 2025/12/06 22:53:50 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_wspace(int c)
{
	if (c >= 9 && c <= 13 || c == 32)
		return (1);
	else
		return (0);
}

int	is_separator(char *str, int	index)
{
	if (is_wspace(str[index]))
		return (1);
	else
	{
		if (str[index] == '&' && str[index + 1] == '&')
			return (1);
		if (str[index] == '|' && str[index + 1] == '|')
			return (1);
		if (str[index] == '|')
			return (1);
	}
	return (0);
}
