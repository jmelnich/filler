/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:13 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/24 19:56:14 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_unumlenmax(uintmax_t n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_numlenmax(intmax_t n, int c)
{
	int	len;

	if (!c)
		return (ft_unumlenmax(n));
	len = 1;
	if (n < -9223372036854775807)
		return (20);
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
