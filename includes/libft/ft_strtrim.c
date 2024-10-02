/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:03:51 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:53 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char achar, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (achar == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*array;
	int		start;
	int		end;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && isinset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && isinset(s1[end], set))
		end--;
	len = end - start + 1;
	array = malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (start <= end)
		array[i++] = s1[start++];
	array[i] = '\0';
	return (array);
}
