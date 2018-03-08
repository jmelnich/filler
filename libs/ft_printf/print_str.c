/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:04:47 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/03 15:31:14 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static void	wr_zero_or_space(t_list_spec *cr)
{
	while (cr->flag[0] == 2 && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free("0", cr->str, 2);
	while (cr->flag[0] == 1 && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(cr->str, " ", 1);
	while (!cr->flag[0] && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(" ", cr->str, 2);
	cr->count += write(1, cr->str, ft_strlen(cr->str));
	free(cr->str);
}

void		print_str(va_list *args, t_list_spec *cr)
{
	char *buff;

	buff = 0;
	if (!(cr->str = va_arg(*args, char*)))
		cr->str = ft_strdup("(null)");
	else
		cr->str = ft_strdup(cr->str);
	if (cr->precs != -1)
	{
		if (cr->precs < (int)ft_strlen(cr->str))
		{
			buff = ft_strdup(cr->str);
			buff[cr->precs] = '\0';
			free(cr->str);
			cr->str = ft_strdup(buff);
			free(buff);
		}
	}
	wr_zero_or_space(cr);
}

void		print_c(va_list *args, t_list_spec *cr)
{
	char c;

	if (cr->type == 'y')
	{
		c = cr->str[0];
		free(cr->str);
	}
	else
	{
		if (!(c = (char)va_arg(*args, int)))
			cr->width -= 1;
	}
	cr->str = ft_strnew(1);
	cr->str[0] = c;
	if (!c && cr->flag[0] == 1)
		cr->count += write(1, "", 1);
	wr_zero_or_space(cr);
	if (!c && cr->flag[0] != 1)
		cr->count += write(1, "", 1);
}
