/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:05:36 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/11 14:56:08 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compare strings. Return an integer greater than, equal to, or less than 0,
** according as the string s1 is greater than, equal to, or less than s2.
*/

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
		i++;
	return (str1[i] - str2[i]);
}
