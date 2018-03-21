/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:14:41 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 11:40:34 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*transbase(uintmax_t nbr, int base, int reg)
{
	int			i;
	int			tmp;
	int			ost;
	char		buf[65];

	tmp = 0;
	tmp = ((reg < 91 && reg > 64) ? 65 : 97);
	if (base < 2 && base > 36)
		return (0);
	i = 64;
	buf[i] = '\0';
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		ost = nbr % base;
		nbr = nbr / base;
		i--;
		if (ost > 9)
			buf[i] = ost + tmp - 10;
		else
			buf[i] = ost + '0';
	}
	return (ft_strdup(buf + i));
}

static	char	*sigitoa(intmax_t nb, char *res, int i)
{
	i = ft_numlen_max(nb, 1);
	if (nb < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	if (nb < 0 && (nb = -nb))
	{
		res[0] = '-';
		while (i-- > 1)
		{
			res[i] = nb % 10 + '0';
			nb /= 10;
		}
	}
	else
	{
		while (i--)
		{
			res[i] = nb % 10 + '0';
			nb /= 10;
		}
	}
	return (res);
}

char			*ft_itoabase(uintmax_t nb, int sys, int rg)
{
	int			i;
	char		*res;

	res = NULL;
	if (sys == 1)
		return (sigitoa(nb, res, 0));
	else if (sys)
		return (transbase(nb, sys, rg));
	i = ft_numlen_max(nb, 0);
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	while (i--)
	{
		res[i] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
