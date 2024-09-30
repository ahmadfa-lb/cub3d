/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:06:25 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/29 01:05:07 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_file_extension(struct s_cub3d_data *data)
{
	char	*extension;

	extension = ft_strrchr(data->utils.map_path, '.');
	if (!extension || ft_strcmp(extension, FILE_EXTENTION) != 0)
	{
		cub3d_exit(BAD_FILE_EXTENTION, data);
	}
}

void	parsing(struct s_cub3d_data *data)
{
	init_data(data);
	if (data->utils.argc != ARGUMENTS_REQUIRED)
	{
		cub3d_exit(BAD_ARGUMENTS, data);
	}
	data->utils.map_path = data->utils.argv[1];
	check_file_extension(data);
	extract_settings(data);
}