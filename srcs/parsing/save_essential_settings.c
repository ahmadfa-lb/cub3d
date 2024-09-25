/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_essential_settings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:32:28 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/25 16:56:08 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	save_essential_setting(struct s_cub3d_data *data, char **line_elements, int fd)
{
	if (store_texture_path(data, line_elements, fd) == 0)
		printf("Texture path stored successfully.\n");
	else if (store_colors(data, line_elements, fd, '0') == 0)
		printf("Color stored successfully.\n");
	else
	{
		free_double_array(&line_elements);
		reach_eof_to_avoid_leaks(NULL, fd);
		close(fd);
		cub3d_exit(BAD_IDENTIFIER, data);
	}
	data->utils.settings_already_set++;
	free_double_array(&line_elements);
}