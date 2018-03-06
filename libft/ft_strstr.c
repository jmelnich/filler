/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:15:55 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/08 20:24:00 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Looking for a first occurence of substring in a string. If the substring is
** longer the string, return NULL. If needle is an empty string, haystack is
** returned; if needle occurs nowhere in haystack, NULL is returned; otherwise a
** pointer to the first character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t haystack_len;
	size_t needle_len;
	size_t i;
	size_t j;
	size_t k;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len > haystack_len)
		return (NULL);
	if (needle_len == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = i;
		k = 0;
		while (haystack[j++] == needle[k++])
		{
			if (needle[k] == '\0')
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
