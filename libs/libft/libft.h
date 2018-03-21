/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 10:53:58 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 12:26:35 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <locale.h>
# define BUFF_SIZE 100
# define FL 3
# define TP "sSpdDioOuUxXcCb"
# define FLAGS "lh0123456789-+ #*.zj"

/*
** Color palette for ft_printf
*/

# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define LBLUE "\033[1;36m"
# define RESET "\033[0m"

/*
** Standart libft functions
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strncat(char *s1, const char *s2, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int nb, int fd);

/*
** List functions
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Additional functions
*/
int				ft_isdelim(char c);
size_t			ft_numlen(int n);
char			*ft_strrev(char *str);
char			**ft_arrnew(size_t y, size_t x);
void			ft_arrdel(char ***arr);
int				get_next_line(const int fd, char **line);

/*
** Gnl structure
*/
typedef struct	s_gnl_struct
{
	char					*content;
	char					*posle;
	int						fd;
	int						pos;
	char					**ret;
	struct s_gnl_struct		*next;
}				t_gnl_struct;

/*
** Ft_printf structure
*/
typedef	struct	s_list_spec
{
	int		flag[FL];
	int		width;
	int		precs;
	int		mod;
	char	type;
	char	*str;
	int		count;
}				t_list_spec;

/*
** Ft_printf functions
*/
int				ft_isdigit_char(char c);
int				ft_numlen_max(intmax_t n, int c);
char			*ft_strjoin_free(char *s1, char *s2, int opt);
void			print_address(va_list *args, t_list_spec *cr);
int				ft_printf(const char *fmt, ...);
void			print_digits(va_list *args, t_list_spec *cr);
void			print_digits_unsigned(va_list *args, t_list_spec *cr, int type);
void			print_str(va_list *args, t_list_spec *cr);
void			print_c(va_list *args, t_list_spec *cr);
char			*print_unichar(int symb);
void			print_unicode(va_list *args, t_list_spec *cr);
int				main_call(const char **fmt, va_list *args, t_list_spec *cr);
int				check_type(char c);
int				check_flags(char c);
void			fill_align(const char *fmt, t_list_spec *cr);
void			fill_width(const char *fmt, t_list_spec *cr, va_list *args);
void			fill_mod(const char *fmt, t_list_spec *cr);
int				fill_type(const char **fmt, t_list_spec *cr);
char			*ft_itoabase(uintmax_t c, int sys, int rg);
int				ft_atoibase(char *str);

#endif
