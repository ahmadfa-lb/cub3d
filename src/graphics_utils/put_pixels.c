/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:20:35 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/28 18:59:39 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_sx_sy(int var1, int var2)
{
	if (var1 < var2)
		return (1);
	return (-1);
}

void	ft_mlx_pixel_put(t_cub3d_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data)
		return ;
	dst = data->mlx.addr + \
		(y * data->mlx.line_len + x * (data->mlx.bits / 8));
	if (dst < data->mlx.addr || dst >= data->mlx.addr + \
		data->mlx.line_len * data->mlx.win_height)
		return ;
	*(unsigned int *)dst = color;
}


void	bresenham_line_draw(t_cub3d_data *data, int x0_y0[2], int x1_y1[2])
{
	t_bresenham	var;

	var.dx_dy[0] = ft_abs(x1_y1[0] - x0_y0[0]);
	var.dx_dy[1] = -ft_abs(x1_y1[1] - x0_y0[1]);
	var.sx_sy[0] = get_sx_sy(x0_y0[0], x1_y1[0]);
	var.sx_sy[1] = get_sx_sy(x0_y0[1], x1_y1[1]);
	var.err = var.dx_dy[0] + var.dx_dy[1];
	while (1)
	{
		ft_mlx_pixel_put(data, x0_y0[0], x0_y0[1], RED);
		if (x0_y0[0] == x1_y1[0] && x0_y0[1] == x1_y1[1])
			break ;
		var.e2 = 2 * var.err;
		if (var.e2 >= var.dx_dy[1])
		{
			var.err += var.dx_dy[1];
			x0_y0[0] += var.sx_sy[0];
		}
		if (var.e2 <= var.dx_dy[0])
		{
			var.err += var.dx_dy[0];
			x0_y0[1] += var.sx_sy[1];
		}
	}
}
