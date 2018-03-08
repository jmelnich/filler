/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:12:00 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/03 15:47:16 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static char		*print_unistr(va_list *args, t_list_spec *cr)
{
	wchar_t	*s;
	char	*res;
	char	*tmp;

	if (!(res = ft_strnew(1)))
		return (0);
	s = va_arg(*args, wchar_t *);
	while (*s)
	{
		tmp = print_unichar((int)*s++);
		if (cr->precs == -1 ||
			cr->precs >= (int)ft_strlen(res) + (int)ft_strlen(tmp))
			res = ft_strjoin_free(res, tmp, 3);
		else
			break ;
	}
	return (res);
}

static char		*unicode_s(va_list *args, t_list_spec *cr)
{
	va_list cp;
	wchar_t	*s;

	va_copy(cp, *args);
	if (!(s = va_arg(cp, wchar_t *)))
	{
		cr->str = ft_strdup("(null)");
		va_arg(*args, void *);
		if (cr->precs)
			cr->str[cr->precs] = '\0';
	}
	else
		cr->str = print_unistr(args, cr);
	return (cr->str);
}

void			print_unicode(va_list *args, t_list_spec *cr)
{
	int		sb;

	if (cr->type == 'C' || cr->type == 'c')
	{
		if (!(sb = va_arg(*args, int)))
			cr->count += write(1, "", 1);
		cr->str = print_unichar(sb);
	}
	if (cr->type == 'S' || cr->type == 's')
		unicode_s(args, cr);
	while (cr->flag[0] == 2 && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free("0", cr->str, 2);
	while (cr->flag[0] == 1 && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(cr->str, " ", 1);
	while (!cr->flag[0] && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(" ", cr->str, 2);
	cr->count += write(1, cr->str, ft_strlen(cr->str));
	free(cr->str);
}
