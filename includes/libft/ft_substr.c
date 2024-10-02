/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:04:00 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:04:01 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start < (unsigned int)ft_strlen(s) && len > 0)
	{
		while (s[start++] && i < len)
			i++;
		array = malloc(sizeof(char) * i + sizeof(char));
		if (array == NULL)
			return (NULL);
		start -= i + 1;
		i = 0;
		while (s[start] && i < len)
			array[i++] = s[start++];
		array[i] = '\0';
		return (array);
	}
	array = malloc(sizeof(char));
	if (array == NULL)
		return (NULL);
	array[i] = '\0';
	return (array);
}
