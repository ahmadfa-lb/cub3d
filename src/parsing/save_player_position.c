/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:58:46 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/25 19:14:09 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_if_player_pos(t_cub3d_data *data, bool *set, int i, int j)
{
	if (is_player_spawn_pos(data->settings.map[j][i]))
	{
		if (*set)
			cub3d_exit(MAP_DUPLICATED_PLAYER_SPAWN_POS, data);
		data->player_data.pole = data->settings.map[j][i];
		if (data->player_data.pole == 'N')
			data->player_data.angle = 3 * M_PI / 2;
		else if (data->player_data.pole == 'E')
			data->player_data.angle = 0.0f;
		else if (data->player_data.pole == 'S')
			data->player_data.angle = M_PI / 2;
		else if (data->player_data.pole == 'W')
			data->player_data.angle = M_PI;
		data->player_data.x = i + 0.5;
		data->player_data.y = j + 0.5;
		*set = true;
	}
}

static void	get_map_height_and_width(t_cub3d_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->utils.map_width = 0;
	while (data->settings.map[j])
	{
		i = 0;
		while (data->settings.map[j][i])
		{
			i++;
		}
		if (data->utils.map_width < i)
			data->utils.map_width = i;
		j++;
	}
	data->utils.map_height = j;
}

void	store_player_pos(t_cub3d_data *data)
{
	int		i;
	int		j;
	bool	set;

	i = 0;
	j = 0;
	set = false;
	get_map_height_and_width(data);
	while (data->settings.map[j])
	{
		while (data->settings.map[j][i])
		{
			check_if_player_pos(data, &set, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	if (!set)
		cub3d_exit(MAP_MISSING_PLAYER_SPAWN_POS, data);
}