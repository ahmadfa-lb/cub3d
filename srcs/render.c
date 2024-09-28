/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:10:35 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/28 19:11:03 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render(t_cub3d_data *data)
{
	static long	last_time;
	static int	gun_frame;
	long		current_time;

	if (!last_time)
		last_time = 0;
	if (!gun_frame)
		gun_frame = 0;
	current_time = get_current_time_in_ms();

	return (0);
}