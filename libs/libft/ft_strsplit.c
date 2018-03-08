/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 10:22:48 by imelnych          #+#    #+#             */
/*   Updated: 2017/11/10 17:54:32 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) obtained by spliting s using
** the character c as a delimiter. If the allocation fails the function returns
** NULL. Ex: ft_strsplit("*hello*fellow***students*", ’*’) returns the array
** ["hello", "fellow", "students"].
*/

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		k;

	i = 0;
	if (!s)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(*array) * ft_wordcount(s, c) + 1)))
		return (NULL);
	j = 0;
	while (i < ft_wordcount(s, c))
	{
		k = 0;
		array[i] = ft_strnew(ft_letters_length(&s[j], c) + 1);
		if (!array[i])
			return (NULL);
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			array[i][k++] = s[j++];
		array[i++][k] = '\0';
	}
	array[i] = 0;
	return (array);
}
