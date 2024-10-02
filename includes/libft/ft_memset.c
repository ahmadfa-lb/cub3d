/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:02:12 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:02:13 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;
	char	*str;

	str = pointer;
	i = 0;
	while (i != count)
	{
		*str = (unsigned char)value;
		str++;
		i++;
	}
	return (pointer);
}
