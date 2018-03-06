/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:27:04 by imelnych          #+#    #+#             */
/*   Updated: 2017/10/29 02:54:18 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The function locates the first occurrence of c (converted to a char) in
** the string pointed to by s. If c is '\0', func returns a pointer to the end
** of the string. If locates c, func returns pointer to the located character.
** If the character does not appear in the string - return NULL.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	if (c == '\0')
		return (str + ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (str + i);
		else
			i++;
	}
	return (NULL);
}
