/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 10:18:11 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/09 19:07:25 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of the string given as argument
** without whitespaces at the beginning or at the end of the string. Will be
** considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s
** has no whitespaces at the beginning or at the end, the function returns a
** copy of s. If the allocation fails the function returns NULL.
*/

#include "libft.h"

static size_t	ft_len_aft_strimback(const char *s)
{
	size_t	len;

	len = ft_strlen(s);
	while (ft_isdelim(s[len - 1]))
		len--;
	return (len);
}

char			*ft_strtrim(const char *s)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	newlen;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (ft_isdelim(s[i]))
		i++;
	if (len == i)
		return (ft_strdup(""));
	newlen = ft_len_aft_strimback(s) - i;
	dest = ft_strnew(newlen);
	if (!dest)
		return (NULL);
	while (j < newlen)
		dest[j++] = s[i++];
	dest[j] = '\0';
	return (dest);
}
