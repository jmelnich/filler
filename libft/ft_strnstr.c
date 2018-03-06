/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:00:15 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/08 20:24:23 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t haystack_len;
	size_t needle_len;
	size_t i;
	size_t k;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len > haystack_len)
		return (NULL);
	if (needle_len == 0)
		return ((char*)haystack);
	while (haystack[i] && (needle_len + i) <= n)
	{
		k = 0;
		while (haystack[k + i] == needle[k])
		{
			if (k == (needle_len - 1))
				return ((char*)haystack + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
