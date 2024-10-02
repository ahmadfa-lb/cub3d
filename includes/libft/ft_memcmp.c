/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:01:20 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:01:22 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*(unsigned char *)(pointer1 + i)
			!= *(unsigned char *)(pointer2 + i))
			return (*(unsigned char *)(pointer1 + i)
			- *(unsigned char *)(pointer2 + i));
		i++;
	}
	return (0);
}
