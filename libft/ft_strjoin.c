/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 10:18:11 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/07 12:53:16 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
** result of the concatenation of s1 and s2. If the allocation fails the
** function returns NULL. Here, I'm trying to reuse ft_strcat for joining.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*dest;
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = ft_strnew(len_s1 + len_s2);
	if (!dest)
		return (NULL);
	while (i < len_s1)
	{
		dest[i] = s1[i];
		i++;
	}
	return (ft_strcat(dest, s2));
}
