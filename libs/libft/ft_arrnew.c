/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:15:29 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 12:21:41 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(size_t y, size_t x)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * y + 1);
	if (!arr)
		return (NULL);
	while (i < (int)y)
		arr[i++] = ft_strnew(x);
	arr[i] = 0;
	return (arr);
}
