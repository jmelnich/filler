/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:15:17 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/09 14:09:26 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL.
*/

#include "libft.h"

char		*ft_itoa(int n)
{
	int		is_negative;
	size_t	len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = 0;
	len = ft_numlen(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		is_negative = 1;
	}
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (is_negative)
		str[len + 1] = '-';
	return (str);
}
