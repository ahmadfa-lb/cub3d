/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:33:43 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/29 01:07:05 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	handle_error_and_exit(char **line_elements, int fd, t_cub3d_data *cub_data)
{
	free_double_array(&line_elements);
	reach_eof_to_avoid_leaks(NULL, fd);
	close(fd);
	cub3d_exit(BAD_SETTING_FORMAT, cub_data);
}

static void	handle_line(struct s_cub3d_data *data, char *line, int fd, int line_length)
{
	char	**elements;
	char	*last_element;

	elements = ft_split(line, ' ');
	free(line);
	if (!elements)
		handle_error_and_exit(elements, fd, data);
	line_length = double_array_len(elements);
	last_element = elements[line_length - 1];
	elements[line_length - 1] = ft_strtrim(elements[line_length - 1], "\n");
	if (!elements[line_length - 1])
	{
		free(last_element);
		handle_error_and_exit(elements, fd, data);
	}
	free(last_element);
	if (data->utils.settings_already_set != BASE_SETTINGS_REQUIRED)
	{
		if(line_length != EXPECTED_SETTING_PARTS)
			handle_error_and_exit(elements, fd, data);
		save_essential_setting(data, elements, fd);
	}
}

void	extract_settings(struct s_cub3d_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->utils.map_path, O_RDONLY);
	if (fd == -1)
		cub3d_exit(OTHER, data);
	line = get_next_line(fd);
	while (line
		&& data->utils.settings_already_set != BASE_SETTINGS_REQUIRED)
	{
		if (!is_only_spaces(line))
			handle_line(data, line, fd, 0);
		else
			free(line);
		line = get_next_line(fd);
	}
	if (!line && data->utils.settings_already_set != BASE_SETTINGS_REQUIRED)
	{
		close (fd);
		cub3d_exit(MISSING_SETTING, data);
	}
	store_map(data, line, fd);
	close(fd);
}
