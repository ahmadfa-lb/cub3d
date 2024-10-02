/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:05:04 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/30 14:05:06 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);

char	*ft_strcpy(char *buffer);

char	*ft_strjoin_c(char *s1, char *s2);

int		ft_strlen_c(char *stash);

int		ft_compare(char	*s1, char *s2);

char	*ft_freestash(char *stash);

#endif