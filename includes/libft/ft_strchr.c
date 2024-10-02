/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:02:50 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:02:52 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	while (*string)
	{
		if (*string == (char)searchedChar)
			return ((char *)string);
		string++;
	}
	if (*string == (char)searchedChar)
		return ((char *)(string));
	return (NULL);
}
