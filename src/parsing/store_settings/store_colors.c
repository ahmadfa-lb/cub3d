/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:56:37 by afarachi          #+#    #+#             */
/*   Updated: 2024/12/05 13:35:30 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	check_for_duplicate_settings(t_cub_data *cub_data, char id,
		char **line_elements, int fd)
{
	if ((id == 'F' && cub_data->settings.floor_color != NULL))
	//|| (id == 'C' && cub_data->settings.ceiling_color != NULL)
	{
		free_double_array(&line_elements);
		reach_eof_to_avoid_leaks(NULL, fd);
		close(fd);
		cub_exit(DUPLICATED_SETTING, cub_data);
	}
}

static bool	are_only_digits(char **rgb)
{
	int	j;
	int	i;

	j = 0;
	while (rgb[j])
	{
		i = 0;
		while (rgb[j][i])
		{
			if (ft_isdigit(rgb[j][i]) == 0)
				return (false);
			i++;
		}
		j++;
	}
	return (true);
}

static bool	are_valid_rgb_values(char **rgb_strings)
{
	int	i;

	i = 0;
	if (double_array_len(rgb_strings) != 3 || !are_only_digits(rgb_strings))
		return (false);
	while (i < 3)
	{
		if (ft_strlen(rgb_strings[i]) > 3 || ft_atoi(rgb_strings[i]) > 255)
			return (false);
		i++;
	}
	return (true);
}

static int	check_color_format_and_store(t_cub_data *cub_data, char *color_code,
		t_color *color, char id)
{
	char	**rgb_strings;

	rgb_strings = ft_split(color_code, ',');
	if (!rgb_strings || !are_valid_rgb_values(rgb_strings))
	{
		free_double_array(&rgb_strings);
		free(color);
		return (1);
	}
	color->r = ft_atoi(rgb_strings[0]);
	color->g = ft_atoi(rgb_strings[1]);
	color->b = ft_atoi(rgb_strings[2]);
	free_double_array(&rgb_strings);
	if (id == 'C')
		cub_data->settings.ceiling_color = color;
	else
		cub_data->settings.floor_color = color;
	return (0);
}

int	store_colors(t_cub_data *cub_data, char **line_elements, int fd, char id)
{
	t_color *color;

	if (ft_strcmp("F", line_elements[0]) == 0 || ft_strcmp("C",
			line_elements[0]) == 0)
	{
		id = line_elements[0][0];
		check_for_duplicate_settings(cub_data, id, line_elements, fd);
		color = malloc(sizeof(t_color));
		if (!color)
		{
			free_double_array(&line_elements);
			reach_eof_to_avoid_leaks(NULL, fd);
			close(fd);
			cub_exit(OTHER, cub_data);
		}
		if (check_color_format_and_store(cub_data, line_elements[1], color, id))
		{
			free_double_array(&line_elements);
			reach_eof_to_avoid_leaks(NULL, fd);
			close(fd);
			cub_exit(BAD_COLOR_CODE_FORMAT, cub_data);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}