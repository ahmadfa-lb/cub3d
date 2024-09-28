/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:05:31 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/29 01:02:50 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

bool	is_space(char check)
{
	if (check != ' ' && check != '\n' && check != '\t')
		return (false);
	return (true);
}

int	ft_strcmp1(const char *first, const char *second)
{
	while (*first && (*first == *second))
	{
		first++;
		second++;
	}
	return (*(unsigned char *)first - *(unsigned char *)second);
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

bool	is_player_spawn_pos(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}