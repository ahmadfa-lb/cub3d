/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:43:59 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 19:44:01 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_exit(t_errors code, t_cub_data *cub_data)
{
	if (code < sizeof(cub_data->utils.exit_funcs)
		/ sizeof(cub_data->utils.exit_funcs[0]))
	{
		cub_data->utils.exit_funcs[code]();
	}
	free_everything(cub_data);
	if (code == SUCCESS)
		exit(SUCCESS);
	exit(EXIT_FAILURE);
}
