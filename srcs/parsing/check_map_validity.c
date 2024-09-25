/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:24:51 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/25 19:28:46 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_explorable(char **map, int i, int j)
{
	return (map[j][i] == '0'
		|| is_player_spawn_pos(map[j][i])
		|| map[j][i] == 'O'
		|| map[j][i] == 'C');
}

static bool	is_valid_char(char c)
{
	return (c != '0' && c != '1' && c != ' ' && c != 'O' && c != 'C');
}

static bool	check_neighbours(char **map, int i, int j, int map_height)
{
	int	y;
	int	x;
	int	ni;
	int	nj;

	y = -1;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			ni = i + x;
			nj = j + y;
			if (nj < 0 || nj >= map_height || ni < 0
				|| ni >= ft_strlen(map[nj]) || !map[nj][ni]
				|| map[nj][ni] == ' ')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static void	check_map_closed(
	t_cub3d_data *data,
	char **map,
	int map_height,
	int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map_height)
	{
		i = 0;
		while (map[j][i])
		{
			if (is_valid_char(map[j][i]) && !is_player_spawn_pos(map[j][i]))
			{
				close(fd);
				cub3d_exit(MAP_WRONG_CHARACTER, data);
			}
			if (is_explorable(map, i, j)
				&& !check_neighbours(map, i, j, map_height))
			{
				close(fd);
				cub3d_exit(MAP_UNCLOSED, data);
			}
			i++;
		}
		j++;
	}
}

void	check_map_validity(t_cub3d_data *data, int fd)
{
	if (!data->settings.map)
	{
		close(fd);
		cub3d_exit(MAP_MISSING, data);
	}
	check_map_closed(
		data,
		data->settings.map,
		double_array_len(data->settings.map),
		fd);
}
