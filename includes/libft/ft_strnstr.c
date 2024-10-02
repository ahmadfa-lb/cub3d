/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:03:39 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:03:41 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	e;
	int	j;

	j = 0;
	e = 0;
	if ((int)len < 0)
		len = (size_t)ft_strlen(big);
	if ((big == NULL && len == 0) || (ft_strlen(little) > ft_strlen(big)))
		return (NULL);
	if (!*little)
		return ((char *)big);
	while (big[e] && e < (int)len)
	{
		j = 0;
		while (big[j + e] && little[j] && e + j < (int)len
			&& big[j + e] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)(big + e));
		e++;
	}
	return (NULL);
}
