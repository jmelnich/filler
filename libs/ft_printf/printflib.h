/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:40:26 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/03 13:54:39 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIB_H
# define PRINTFLIB_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <locale.h>
# define FL 3
# define TP "sSpdDioOuUxXcCb"
# define FLAGS "lh0123456789-+ #*.zj"

/*
** Color palette
*/

# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define LBLUE "\033[1;36m"
# define RESET "\033[0m"

typedef	struct
{
	int		flag[FL];
	int		width;
	int		precs;
	int		mod;
	char	type;
	char	*str;
	int		count;
}			t_list_spec;

void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *str);
void		ft_putchar(char c);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strnew(size_t size);
void		ft_putstr(char const *s);
int			ft_isdigitchar(char c);
int			ft_numlenmax(intmax_t n, int c);
char		*ft_strjoin_free(char *s1, char *s2, int opt);

void		print_address(va_list *args, t_list_spec *cr);
int			ft_printf(const char *fmt, ...);
void		print_digits(va_list *args, t_list_spec *cr);
void		print_digits_unsigned(va_list *args, t_list_spec *cr, int type);
void		print_str(va_list *args, t_list_spec *cr);
void		print_c(va_list *args, t_list_spec *cr);
char		*print_unichar(int symb);
void		print_unicode(va_list *args, t_list_spec *cr);
int			main_call(const char **fmt, va_list *args, t_list_spec *cr);
int			check_type(char c);
int			check_flags(char c);
void		fill_align(const char *fmt, t_list_spec *cr);
void		fill_width(const char *fmt, t_list_spec *cr, va_list *args);
void		fill_mod(const char *fmt, t_list_spec *cr);
int			fill_type(const char **fmt, t_list_spec *cr);
char		*ft_itoabase(uintmax_t c, int sys, int rg);
int			ft_atoibase(char *str);

#endif
