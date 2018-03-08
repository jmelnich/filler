/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:18:07 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/02 20:04:35 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	check_type(char c)
{
	int i;

	i = 0;
	while (TP[i])
	{
		if (c == TP[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_flags(char c)
{
	int i;

	i = 0;
	while (FLAGS[i])
	{
		if (c == FLAGS[i])
			return (1);
		i++;
	}
	return (0);
}
