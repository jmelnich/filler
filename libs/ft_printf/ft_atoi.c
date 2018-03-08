/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 09:48:45 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/27 10:28:45 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static int	ft_isdelim(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
		c == '\v' || c == '\r' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		is_negative;
	long	num;
	int		numlen;

	i = 0;
	num = 0;
	numlen = 0;
	while (ft_isdelim(str[i]))
		i++;
	is_negative = (str[i] == '-') ? 1 : 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < 48 || str[i] > 57)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + str[i++] - '0';
		numlen++;
	}
	num = (is_negative) ? num * (-1) : num;
	if (numlen > 19 || num > 9223372036854775807)
		return ((is_negative) ? 0 : -1);
	return ((int)num);
}
