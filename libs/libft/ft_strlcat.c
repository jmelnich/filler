/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:14:01 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/10 14:46:28 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstln;
	size_t	i;
	size_t	ret;
	size_t	strln;

	i = 0;
	strln = ft_strlen(src);
	dstln = ft_strlen(dst);
	if (size <= dstln)
		return (size + strln);
	ret = dstln + strln;
	while (src[i] != '\0')
	{
		if (dstln < size - 1)
		{
			dst[dstln] = src[i];
			dstln++;
		}
		i++;
	}
	dst[dstln] = '\0';
	return (ret);
}
