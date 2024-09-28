/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:00:10 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/28 19:01:11 by afarachi         ###   ########.fr       */
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