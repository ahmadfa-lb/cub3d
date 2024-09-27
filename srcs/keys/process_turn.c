/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:34:27 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/27 16:39:28 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(t_cub3d_data *data)
{
	float	radian_step;

	radian_step = SENSITIVITY * M_PI / 180;
	data->player_data.angle -= radian_step;
	if (data->player_data.angle < 0)
		data->player_data.angle += 2 * M_PI;
}

void	turn_right(t_cub3d_data *data)
{
	float	radian_step;

	radian_step = SENSITIVITY * M_PI / 180;
	data->player_data.angle += radian_step;
	if (data->player_data.angle >= 2 * M_PI)
		data->player_data.angle -= 2 * M_PI;
}
