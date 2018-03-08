/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:02:05 by imelnych          #+#    #+#             */
/*   Updated: 2017/10/29 02:58:24 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Similar to strchr, this function locates the LAST occurrence of c (converted
** to a char) in the string pointed to by s.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	str = (char*)s;
	len = ft_strlen(str);
	if (c == '\0')
		return (str + len);
	while (len--)
	{
		if (str[len] == (char)c)
			return (str + len);
	}
	return (NULL);
}
