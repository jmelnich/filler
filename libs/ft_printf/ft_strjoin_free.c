/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 10:18:11 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/24 19:55:14 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

char	*ft_strjoin_free(char *s1, char *s2, int opt)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*dest;
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = ft_strnew(len_s1 + len_s2);
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	if (opt == 1 || opt == 3)
		free(s1);
	if (opt == 2 || opt == 3)
		free(s2);
	return (dest);
}
