/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:00:10 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/28 19:09:17 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	game_algorithm(t_cub3d_data *data)
{
	fill_background(data, 0, 0);
	raycasting(data);
	draw_minimap(data, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx_ptr,
		data->mlx.win_ptr, data->mlx.img, 0, 0);
	mlx_loop_hook(data->mlx.mlx_ptr, render, data);
}

void	game_loop(t_cub3d_data *data)
{
	game_algorithm(data);
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx.win_ptr, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx.win_ptr, 17, 1L << 17,
		(void *)free_everything, &(*data));
	//mlx_hook(data->mlx.win_ptr, 6, 1L << 6, mouse_hook_turn, data);
	//mlx_mouse_hook(data->mlx.win_ptr, mouse_hook_shoot, data);
	mlx_loop(data->mlx.mlx_ptr);
}