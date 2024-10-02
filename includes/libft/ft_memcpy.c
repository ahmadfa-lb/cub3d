/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:01:29 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:01:30 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;

	i = 0;
	if (!destination && !source && size > 0)
		return (NULL);
	if (size == 0)
		return (destination);
	while (i < size)
	{
		*(unsigned char *)(destination) = *(unsigned char *)(source);
		source++;
		destination++;
		i++;
	}
	return (destination - i);
}
