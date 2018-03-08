/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:08:58 by imelnych          #+#    #+#             */
/*   Updated: 2017/10/28 14:00:52 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Strncat appends a copy of the null-terminated string s2 to the end of the
** null-terminated string s1. The strncat() function appends not more than n
** characters from s2, and then adds a terminating `\0'.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t dstsize)
{
	int		i;
	size_t	len1;

	i = 0;
	len1 = ft_strlen(s1);
	while (dstsize-- && s2[i] != '\0')
	{
		s1[len1] = s2[i];
		len1++;
		i++;
	}
	s1[len1] = '\0';
	return (s1);
}
