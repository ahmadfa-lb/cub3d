/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:06:25 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/25 14:23:29 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_file_extension(struct s_cub3d_data *data)
{
	char	*extension;

	extension = ft_strrchr(data->utils.map_path, '.');
	if (!extension || ft_strcmp(extension, FILE_EXTENTION) != 0)
	{
		
	}
}
