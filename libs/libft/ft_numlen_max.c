/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:13 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 11:41:31 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unumlen_max(uintmax_t n)
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

int			ft_numlen_max(intmax_t n, int c)
{
	int	len;

	if (!c)
		return (ft_unumlen_max(n));
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
