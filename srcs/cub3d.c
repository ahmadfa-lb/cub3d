/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:00:22 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/28 19:56:29 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d_data	cub_data;

	cub_data.utils.argc = argc;
	cub_data.utils.argv = argv;
	parsing(&cub_data);
	load_mlx(&cub_data);
	game_loop(&cub_data);
	return (0);
}