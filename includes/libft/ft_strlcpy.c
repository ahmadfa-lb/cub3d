/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:03:16 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:18 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		len;

	len = 0;
	i = 0;
	len = ft_strlen(src);
	if (!src)
	{
		*dst = '\0';
		return (0);
	}
	if (size > 0)
	{
		while (i < size - 1 && *src)
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
		*dst = '\0';
		return (len);
	}
	return (len);
}
