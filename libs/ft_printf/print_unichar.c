/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unichar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:34:41 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/03 15:47:40 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static int	find_bit(int len)
{
	if (len > 16)
		return (4);
	else if (len > 11)
		return (3);
	else if (len > 7)
		return (2);
	return (0);
}

static char	*fill_first_mask(int bit)
{
	int		i;
	char	*first_mask;

	i = 0;
	first_mask = ft_strdup("00000000");
	while (i < bit)
		first_mask[i++] = '1';
	return (first_mask);
}

static char	*fill_sub_mask(char *str, int bit, int len, char *f_mask)
{
	int		i;
	char	*sub_mask;
	int		j;
	char	*res;

	if (!(res = ft_strnew(bit)))
		return (0);
	i = bit - 1;
	while (bit-- > 1)
	{
		sub_mask = ft_strdup("10000000");
		j = 8;
		while (j-- > 2 && len >= 0)
			sub_mask[j] = str[--len];
		res[i--] = (char)ft_atoibase(sub_mask);
		free(sub_mask);
	}
	i = 0;
	j = 8;
	while (len--)
		f_mask[--j] = str[len];
	res[i] = (char)ft_atoibase(f_mask);
	return (res);
}

char		*print_unichar(int symb)
{
	char	*res;
	char	*str;
	char	*f_mask;
	int		bit;
	int		len;

	bit = 0;
	str = ft_itoabase(symb, 2, 'b');
	len = (int)ft_strlen(str);
	bit = find_bit(len);
	f_mask = fill_first_mask(bit);
	res = fill_sub_mask(str, bit, len, f_mask);
	free(str);
	free(f_mask);
	return (res);
}
