/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:58:03 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/05 14:49:38 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The function locates the first occurrence of c (converted to an unsigned
** char) in string s. Returns a pointer to the byte located, or NULL if no such
** byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
