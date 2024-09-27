/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:55:54 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/27 15:58:18 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_release(int keycode, t_cub3d_data *data)
{
	if (keycode == W)
		data->keys.keys[KEY_W] = false;
	else if (keycode == A)
		data->keys.keys[KEY_A] = false;
	else if (keycode == S)
		data->keys.keys[KEY_S] = false;
	else if (keycode == D)
		data->keys.keys[KEY_D] = false;
	else if (keycode == LEFT_ARROW)
		data->keys.keys[KEY_LEFT] = false;
	else if (keycode == RIGHT_ARROW)
		data->keys.keys[KEY_RIGHT] = false;
	return (0);
}

int	key_press(int keycode, t_cub3d_data *data)
{
	if (keycode == ESC)
		cub_exit(SUCCESS, data);
	if (keycode == W)
		data->keys.keys[KEY_W] = true;
	else if (keycode == A)
		data->keys.keys[KEY_A] = true;
	else if (keycode == S)
		data->keys.keys[KEY_S] = true;
	else if (keycode == D)
		data->keys.keys[KEY_D] = true;
	else if (keycode == LEFT_ARROW)
		data->keys.keys[KEY_LEFT] = true;
	else if (keycode == RIGHT_ARROW)
		data->keys.keys[KEY_RIGHT] = true;
	// else if (keycode == E)
	// 	open_or_close_door(data);
	return (0);
}

void	handle_keys(t_cub3d_data *data)
{
	if (data->keys.keys[KEY_W])
		move_forward(data);
	if (data->keys.keys[KEY_S])
		move_backward(data);
	if (data->keys.keys[KEY_A])
		move_left(data);
	if (data->keys.keys[KEY_D])
		move_right(data);
	if (data->keys.keys[KEY_LEFT])
		turn_left(data);
	if (data->keys.keys[KEY_RIGHT])
		turn_right(data);
}
