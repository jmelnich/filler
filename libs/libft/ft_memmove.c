/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 10:53:58 by imelnych          #+#    #+#             */
/*   Updated: 2017/10/28 13:46:15 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copy byte string fron src to dst. The two strings may overlap; the copy is
** always done in a non-destructive manner. Returns the original value of dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	int		i;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	if (s > d)
		return (ft_memcpy(d, s, len));
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (d);
}
