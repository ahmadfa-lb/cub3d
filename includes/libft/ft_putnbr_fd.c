/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:02:34 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:02:36 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int const	save = n;
	char		temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n <= 9 && n >= 0)
	{
		temp = n + '0';
		write (fd, &temp, 1);
	}
	else if (n > 9)
	{
		n = save / 10;
		ft_putnbr_fd(n, fd);
		n = save % 10;
		ft_putnbr_fd(n, fd);
	}
}
