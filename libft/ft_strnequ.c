/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 09:59:37 by imelnych          #+#    #+#             */
/*   Updated: 2017/10/22 09:59:39 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographical comparison between s1 & s2 up to n characters or until a '\0'
** is reached. If the 2 strings are identical - returns 1, 0 otherwise.
** Reuse of ft_strncmp: compares s1 & s2 up to n characters - returns
** differense if they are not identical, and (0) if they are identical.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) ? 0 : 1);
}
