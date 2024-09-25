/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:24:52 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/25 14:54:04 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cub3d_exit(t_errors exit_code, t_cub3d_data *data)
{
	if (exit_code < sizeof(data->utils.exit_funcs)
		/ sizeof(data->utils.exit_funcs[0]))
	{
		data->utils.exit_funcs[exit_code]();
	}
	free_data(data);
	if (exit_code == SUCCESS)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}