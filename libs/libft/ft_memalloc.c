/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 10:51:43 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/09 13:45:32 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area (no need to
** reserve memory for '\0'. The memory allocated is initialized to 0.
** If the allocation fails, the function returns NULL (protection).
*/

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *str;

	str = (void*)malloc(sizeof(str) * (size));
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
