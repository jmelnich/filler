/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:54:13 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/10 14:50:23 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Counts length of the number given. Return the lenght in size_t.
*/

#include "libft.h"

size_t	ft_numlen(int n)
{
	size_t	len;

	len = 1;
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
