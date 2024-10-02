/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:48:23 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 13:48:25 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementcount, size_t elementsize)
{
	void	*array;

	if ((long)elementcount == 0 || (long)elementsize == 0)
		return (malloc(1));
	if (((elementcount * elementsize) / elementcount) != elementsize)
		return (NULL);
	array = malloc(elementcount * elementsize);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (elementcount * elementsize));
	return (array);
}
