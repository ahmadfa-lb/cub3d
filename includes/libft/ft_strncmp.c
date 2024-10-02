/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:03:34 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:36 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	if (first[0] == '\0' && second[0] == '\0')
		return (0);
	while ((first[i] || second[i]) && i != length)
	{
		if (second[i] != first[i])
			return (((unsigned char)first[i] - (unsigned char)second[i]));
		i++;
	}
	return (0);
}
