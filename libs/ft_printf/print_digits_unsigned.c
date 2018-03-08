/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:06:05 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/02 13:17:03 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static char	*trans_type_u_digit(va_list *args, t_list_spec cr, int type)
{
	int system;

	system = 0;
	if (type == 'o' || type == 'O')
		system = 8;
	else if (type == 'x' || type == 'X')
		system = 16;
	else if (type == 'b')
		system = 2;
	if (cr.mod == 4)
		cr.str = ft_itoabase(va_arg(*args, uintmax_t), system, type);
	else if (cr.mod == 3 || type == 'O' || type == 'U')
		cr.str = ft_itoabase(va_arg(*args, unsigned long), system, type);
	else if (cr.mod == 0)
		cr.str = ft_itoabase(va_arg(*args, unsigned int), system, type);
	else if (cr.mod == 2)
		cr.str = ft_itoabase((unsigned short)va_arg(*args, int), system, type);
	else if (cr.mod == 1)
		cr.str = ft_itoabase((unsigned char)va_arg(*args, int), system, type);
	return (cr.str);
}

static void	check_print(t_list_spec *cr, int type, char *c)
{
	while (cr->flag[0] == 2 && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free("0", cr->str, 2);
	if (cr->flag[2] == 1 && (type == 'o' || type == 'O') && *cr->str != '0')
		cr->str = ft_strjoin_free("0", cr->str, 2);
	while (cr->flag[0] == 1 && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(cr->str, " ", 1);
	if (cr->flag[2] == 1 && (type == 'x' || type == 'X'))
		cr->str = ft_strjoin_free(c, cr->str, 2);
	while (cr->flag[0] != 2 && cr->width && cr->flag[2] &&
		cr->width + 2 > (int)ft_strlen(cr->str)
		&& (type != 'o' && type != 'O'))
		cr->str = ft_strjoin_free(" ", cr->str, 2);
	while (cr->flag[0] != 2 && cr->width && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(" ", cr->str, 2);
	cr->count += write(1, cr->str, ft_strlen(cr->str));
	free(cr->str);
}

void		print_digits_unsigned(va_list *args, t_list_spec *cr, int type)
{
	char c[3];

	c[0] = '0';
	c[1] = (char)type;
	c[2] = '\0';
	cr->str = trans_type_u_digit(args, *cr, type);
	if (cr->str[0] == '0' && (cr->type == 'x' || cr->type == 'X'))
		cr->flag[2] = 0;
	if (!cr->precs && cr->str[0] == '0' && cr->flag[2] == 0)
	{
		free(cr->str);
		cr->str = ft_strdup("");
	}
	if (cr->precs != -1)
	{
		if (cr->flag[0] == 2)
			cr->flag[0] = 0;
		while (cr->precs > (int)ft_strlen(cr->str))
			cr->str = ft_strjoin_free("0", cr->str, 2);
	}
	if (cr->flag[2] == 1 && (type == 'x' || type == 'X'))
		cr->width -= 2;
	check_print(cr, type, c);
}
