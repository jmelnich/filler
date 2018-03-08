/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:20 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/10 12:59:36 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	tmp;

	if (str)
	{
		i = 0;
		len = ft_strlen(str);
		j = len;
		while (i < j / 2)
		{
			tmp = str[--len];
			str[len] = str[i];
			str[i] = tmp;
			i++;
		}
	}
	return (str);
}
