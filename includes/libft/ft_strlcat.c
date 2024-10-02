/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:03:12 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:13 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sizedst;
	size_t	sizesrc;
	size_t	i;
	size_t	e;

	i = 0;
	e = 0;
	if (size == 0 && dst == NULL)
		return ((size_t)ft_strlen(src));
	sizedst = (size_t)ft_strlen(dst);
	sizesrc = (size_t)ft_strlen(src);
	if (size == 0)
		return (sizesrc);
	if (size < sizedst)
		return (sizesrc + size);
	if (size == sizedst)
		return (sizedst + sizesrc);
	i += sizedst;
	while ((size - sizedst - 1) > e && src[e])
		dst[i++] = src[e++];
	dst[i] = '\0';
	return (sizedst + sizesrc);
}
