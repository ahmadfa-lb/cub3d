/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:01:36 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:01:42 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (destination);
	if (!destination && !source && size > 0)
		return (destination);
	if (destination > source)
	{
		i = (int)size - 1;
		while (i < size)
		{
			*(unsigned char *)(destination + i)
				= *(unsigned char *)(source + i);
			i--;
		}
		return (destination);
	}
	while (i < size)
	{
		*(unsigned char *)(destination + i)
			= *(unsigned char *)(source + i);
		i++;
	}
	return (destination);
}
