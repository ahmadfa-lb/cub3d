/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:36:02 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/25 15:51:50 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_double_array(char ***array_ptr)
{
	int	i;

	i = 0;
	if (*array_ptr)
	{
		while ((*array_ptr)[i])
		{
			free((*array_ptr)[i]);
			(*array_ptr)[i] = NULL;
			i++;
		}
		free(*array_ptr);
		*array_ptr = NULL;
	}
}

void	reach_eof_to_avoid_leaks(char *line, int fd)
{
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			return ;
		free(line);
		line = get_next_line(fd);
	}
}

int	double_array_len(char **dArray)
{
	int	i;
	
	i = 0;
	if (dArray)
	{
		while (dArray[i])
			i++;
	}
		return (i);
}