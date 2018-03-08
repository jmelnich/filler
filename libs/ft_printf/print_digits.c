/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:43:07 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/02 13:20:01 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static char			*trans_type_digit(va_list *args, t_list_spec cr)
{
	if (cr.mod == 4)
		cr.str = ft_itoabase(va_arg(*args, intmax_t), 1, 0);
	else if (cr.mod == 3 || cr.type == 'D')
		cr.str = ft_itoabase(va_arg(*args, long), 1, 0);
	else if (cr.mod == 0)
		cr.str = ft_itoabase(va_arg(*args, int), 1, 0);
	else if (cr.mod == 2)
		cr.str = ft_itoabase((short)va_arg(*args, int), 1, 0);
	else if (cr.mod == 1)
		cr.str = ft_itoabase((char)va_arg(*args, int), 1, 0);
	return (cr.str);
}

static t_list_spec	if_precision(t_list_spec cr)
{
	if (cr.flag[0] == 2)
		cr.flag[0] = 0;
	if (*cr.str == '-' && cr.precs > (int)ft_strlen(cr.str) - 1)
	{
		*cr.str = '0';
		while (cr.precs > (int)ft_strlen(cr.str))
			cr.str = ft_strjoin_free("0", cr.str, 2);
		cr.str = ft_strjoin_free("-", cr.str, 2);
	}
	else
	{
		while (cr.precs > (int)ft_strlen(cr.str))
			cr.str = ft_strjoin_free("0", cr.str, 2);
	}
	return (cr);
}

static	char		*if_width(t_list_spec cr)
{
	int		i;
	char	c[2];

	c[0] = '0';
	c[1] = '\0';
	i = 0;
	while (cr.flag[0] == 1 && cr.width > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin_free(cr.str, " ", 1);
	while (cr.flag[0] != 2 && cr.width > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin_free(" ", cr.str, 2);
	if (cr.flag[0] == 2)
	{
		if ((*cr.str == ' ' || *cr.str == '-' || *cr.str == '+')
			&& cr.width > (int)ft_strlen(cr.str))
		{
			i = 1;
			c[0] = *cr.str;
			*cr.str = '0';
		}
		while (cr.width > (int)ft_strlen(cr.str) + i)
			cr.str = ft_strjoin_free("0", cr.str, 2);
		if (cr.width > (int)ft_strlen(cr.str))
			cr.str = ft_strjoin_free(c, cr.str, 2);
	}
	return (cr.str);
}

void				print_digits(va_list *args, t_list_spec *cr)
{
	cr->str = trans_type_digit(args, *cr);
	if (!cr->precs && cr->str[0] == '0')
	{
		free(cr->str);
		cr->str = ft_strdup("");
	}
	if (cr->precs > -1)
		*cr = if_precision(*cr);
	if (cr->flag[1] == 1 && *cr->str != '-')
		cr->str = ft_strjoin_free("+", cr->str, 2);
	if (cr->flag[1] == 2 && *cr->str != '-')
		cr->str = ft_strjoin_free(" ", cr->str, 2);
	if (cr->width)
		cr->str = if_width(*cr);
	cr->count += write(1, cr->str, ft_strlen(cr->str));
	free(cr->str);
}
