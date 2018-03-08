/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:07:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/27 10:25:20 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_atoibase(char *str)
{
	int i;
	int j;
	int res;

	j = 1;
	res = 0;
	i = ft_strlen(str);
	while (--i >= 0)
	{
		res += j * (str[i] - '0');
		j *= 2;
	}
	return (res);
}
