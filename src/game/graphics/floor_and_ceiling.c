/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:33:43 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/29 01:07:05 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

static int	create_trgb(unsigned char r, unsigned char g, unsigned char b)
{
	int	t;

	t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	get_floor_color(t_cub_data *data)
{
	return (create_trgb(data->settings.floor_color->r,
			data->settings.floor_color->g, data->settings.floor_color->b));
}

static int	get_ceiling_color(t_cub_data *data)
{
	return (create_trgb(data->settings.ceiling_color->r,
			data->settings.ceiling_color->g, data->settings.ceiling_color->b));
}

void	fill_background(t_cub_data *data, int x, int y)
{
	while (y < data->mlx.win_height / 2)
	{
		x = 0;
		while (x < data->mlx.win_width)
		{
			ft_mlx_pixel_put(data, x, y, get_ceiling_color(data));
			x++;
		}
		y++;
	}
	y = data->mlx.win_height / 2;
	while (y < data->mlx.win_height)
	{
		x = 0;
		while (x < data->mlx.win_width)
		{
			ft_mlx_pixel_put(data, x, y, get_floor_color(data));
			x++;
		}
		y++;
	}
}
