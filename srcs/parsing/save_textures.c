/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:35:36 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/25 16:52:26 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	texture_file_opening_test(t_cub3d_data *data, int settings_fd, char **line_elements, char direction)
{
	int fd;

	fd = open(line_elements[1], O_RDONLY);
	if (fd == -1)
	{
		free_double_array(&line_elements);
		reach_eof_to_avoid_leaks(NULL, settings_fd);
		close(settings_fd);
		if (direction == 'E')
			cub3d_exit(E_BAD_FILE_PATH, data);
		else if (direction == 'N')
			cub3e_exit(N_BAD_FILE_PATH, data);
		else if (direction == 'S')
			cub3e_exit(S_BAD_FILE_PATH, data);
		else if (direction == 'W')
			cub3d_exit(W_BAD_FILE_PATH, data);
	}
	close(fd);
}

static void	store_texture_path_ptr(t_cub3d_data *cub_data, char direction, char *path)
{
	if (direction == 'E')
		cub_data->settings.e_texture_path = path;
	else if (direction == 'N')
		cub_data->settings.n_texture_path = path;
	else if (direction == 'S')
		cub_data->settings.s_texture_path = path;
	else if (direction == 'W')
		cub_data->settings.w_texture_path = path;
}

static void	check_for_duplicate_settings(t_cub3d_data *cub_data, char direction, char **line_elements, int fd)
{
	if ((direction == 'E' && cub_data->settings.e_texture_path != NULL)
		|| (direction == 'N' && cub_data->settings.n_texture_path != NULL)
		|| (direction == 'S' && cub_data->settings.s_texture_path != NULL)
		|| (direction == 'W' && cub_data->settings.w_texture_path != NULL))
	{
		free_double_array(&line_elements);
		reach_eof_to_avoid_leaks(NULL, fd);
		close (fd);
		cub3d_exit(DUPLICATED_SETTING, cub_data);
	}
}

int	store_texture_path(t_cub3d_data *data, char **line_elements, int fd)
{
	char	direction;
	char	*path;

	path = NULL;
	if (ft_strcmp("EA", line_elements[0]) == 0
		|| ft_strcmp("NO", line_elements[0]) == 0
		|| ft_strcmp("SO", line_elements[0]) == 0
		|| ft_strcmp("WE", line_elements[0]) == 0)
	{
		direction = line_elements[0][0];
		check_for_duplicate_settings(data, direction, line_elements, fd);
		texture_file_opening_test(data, fd, line_elements, direction);
		path = ft_strdup(line_elements[1]);
		if (!path)
		{
			reach_eof_to_avoid_leaks(NULL, fd);
			close(fd);
			free_double_array(&line_elements);
			cub_exit(OTHER, data);
		}
		store_texture_path_ptr(data, direction, path);
		return (0);
	}
	return (1);
}