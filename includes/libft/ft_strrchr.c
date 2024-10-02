/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:03:44 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:45 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	string += i;
	while (i != 0)
	{
		if (*string == (char)searchedChar)
			return ((char *)string);
		string--;
		i--;
	}
	if (*string == (char)searchedChar)
		return ((char *)string);
	return (NULL);
}
