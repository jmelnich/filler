/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 11:07:44 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/11 15:49:41 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it. The pointer may
** subsequently be used as an argument to the function free(3).
*/

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*dest;

	i = 0;
	len = ft_strlen(s1);
	dest = (char*)malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
