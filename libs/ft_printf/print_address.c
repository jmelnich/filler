/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:18:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/05 12:32:14 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void		print_address(va_list *args, t_list_spec *cr)
{
	cr->str = ft_itoabase(va_arg(*args, uintmax_t), 16, 'a');
	if (cr->precs != -1)
	{
		if (cr->flag[0] == 2)
			cr->flag[0] = 0;
		while (cr->precs > (int)ft_strlen(cr->str))
			cr->str = ft_strjoin_free("0", cr->str, 2);
	}
	if (!cr->precs && cr->str[0] == '0')
		cr->str[0] = '\0';
	while (cr->flag[0] == 2 && cr->width - 2 > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free("0", cr->str, 2);
	cr->str = ft_strjoin_free("0x", cr->str, 2);
	if (cr->flag[0] == 1)
	{
		while (cr->width > (int)ft_strlen(cr->str))
			cr->str = ft_strjoin_free(cr->str, " ", 1);
	}
	else
	{
		while (cr->width > (int)ft_strlen(cr->str))
			cr->str = ft_strjoin_free(" ", cr->str, 2);
	}
	cr->count += write(1, cr->str, ft_strlen(cr->str));
	free(cr->str);
}
