/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:15:37 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/06 20:37:41 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Same as strcpy (copy src to dest and terminates with '\0' most n characters.
** If src is less than len characters long, the remainder of dst is filled with
** `\0' characters. OTHERWISE, STRING IS NOT TERMINATED!
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
