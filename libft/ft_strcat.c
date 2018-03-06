/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:45:41 by imelnych          #+#    #+#             */
/*   Updated: 2017/10/29 02:21:04 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends a copy of the null-terminated string s2 to the end of the
** null-terminated string s1, then add a terminating '\0'.
** The string s1 must have sufficient space to hold the result.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t len1;

	i = 0;
	len1 = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[len1] = s2[i];
		len1++;
		i++;
	}
	s1[len1] = '\0';
	return (s1);
}
