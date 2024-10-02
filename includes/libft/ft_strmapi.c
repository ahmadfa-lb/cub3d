/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:03:30 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:31 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*array;

	i = 0;
	if (!s || !f)
		return (NULL);
	array = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (array == NULL)
		return (NULL);
	while (s[i])
	{
		array[i] = (*f)(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
