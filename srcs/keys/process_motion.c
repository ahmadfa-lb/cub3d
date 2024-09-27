/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_motion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:21:17 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/27 16:32:56 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_cub3d_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x + PLAYER_SPEED * cos(data->player_data.angle);
	if (data->settings.map[(int)data->player_data.y][(int)new_x] != '1'
		&& data->settings.map[(int)data->player_data.y][(int)new_x] != 'C')
	{
		data->player_data.x = new_x;
	}
	new_y = data->player_data.y + PLAYER_SPEED * sin(data->player_data.angle);
	if (data->settings.map[(int)new_y][(int)data->player_data.x] != '1'
		&& data->settings.map[(int)new_y][(int)data->player_data.x] != 'C')
	{
		data->player_data.y = new_y;
	}
}


void	move_backward(t_cub3d_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x - PLAYER_SPEED * cos(data->player_data.angle);
	if (data->settings.map[(int)data->player_data.y][(int)new_x] != '1'
		&& data->settings.map[(int)data->player_data.y][(int)new_x] != 'C')
	{
		data->player_data.x = new_x;
	}
	new_y = data->player_data.y - PLAYER_SPEED * sin(data->player_data.angle);
	if (data->settings.map[(int)new_y][(int)data->player_data.x] != '1'
		&& data->settings.map[(int)new_y][(int)data->player_data.x] != 'C')
	{
		data->player_data.y = new_y;
	}
}

void	move_left(t_cub3d_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x + STRAFE_SPEED * sin(data->player_data.angle);
	if (data->settings.map[(int)data->player_data.y][(int)new_x] != '1'
		&& data->settings.map[(int)data->player_data.y][(int)new_x] != 'C')
	{
		data->player_data.x = new_x;
	}
	new_y = data->player_data.y - STRAFE_SPEED * cos(data->player_data.angle);
	if (data->settings.map[(int)new_y][(int)data->player_data.x] != '1'
		&& data->settings.map[(int)new_y][(int)data->player_data.x] != 'C')
	{
		data->player_data.y = new_y;
	}
}

void	move_right(t_cub3d_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x - STRAFE_SPEED * sin(data->player_data.angle);
	if (data->settings.map[(int)data->player_data.y][(int)new_x] != '1'
		&& data->settings.map[(int)data->player_data.y][(int)new_x] != 'C')
	{
		data->player_data.x = new_x;
	}
	new_y = data->player_data.y + STRAFE_SPEED * cos(data->player_data.angle);
	if (data->settings.map[(int)new_y][(int)data->player_data.x] != '1'
		&& data->settings.map[(int)new_y][(int)data->player_data.x] != 'C')
	{
		data->player_data.y = new_y;
	}
}

