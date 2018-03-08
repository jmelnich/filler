/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:42:39 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/03 15:16:46 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static int		save_spec(const char **fmt, va_list *args, t_list_spec *cr)
{
	int			res;

	fill_align(*fmt, cr);
	fill_width(*fmt, cr, args);
	fill_mod(*fmt, cr);
	res = fill_type(fmt, cr);
	if (!res)
		return (0);
	else if (res == 2)
	{
		cr->type = 'y';
		cr->str = ft_strdup(" ");
		cr->str[0] = **fmt;
	}
	return (1);
}

int				main_call(const char **fmt, va_list *args, t_list_spec *cr)
{
	if (!(save_spec(fmt, args, cr)))
		return (0);
	if (cr->type == 'd' || cr->type == 'i' || cr->type == 'D')
		print_digits(args, cr);
	if (cr->type == 'u' || cr->type == 'U' || cr->type == 'o' || cr->type == 'O'
		|| cr->type == 'X' || cr->type == 'b' || cr->type == 'x')
		print_digits_unsigned(args, cr, (int)cr->type);
	if (cr->type == 'p')
		print_address(args, cr);
	if (cr->type == 's' && cr->mod != 3)
		print_str(args, cr);
	if (cr->type == 'S' || cr->type == 'C' || (cr->type == 'c' && cr->mod == 3)
		|| (cr->type == 's' && cr->mod == 3))
		print_unicode(args, cr);
	if ((cr->type == 'c' && cr->mod != 3) || cr->type == 'y')
		print_c(args, cr);
	return (1);
}
