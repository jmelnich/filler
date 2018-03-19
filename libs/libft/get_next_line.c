/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:42:58 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/19 12:59:25 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl_struct	*ft_create(t_gnl_struct **list, const int fd)
{
	t_gnl_struct	*tmp_list;

	tmp_list = *list;
	while (tmp_list)
	{
		if (tmp_list->fd == fd)
			return (tmp_list);
		tmp_list = tmp_list->next;
	}
	tmp_list = (t_gnl_struct *)malloc(sizeof(t_gnl_struct));
	tmp_list->pos = 0;
	tmp_list->fd = fd;
	tmp_list->content = ft_strdup("");
	tmp_list->next = *list;
	*list = tmp_list;
	return (tmp_list);
}

static void			ft_read(t_gnl_struct **list, const int fd)
{
	int		i;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	if (ft_strchr((*list)->content, '\n') != NULL)
		return ;
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		tmp = ft_strjoin((*list)->content, buf);
		free((*list)->content);
		(*list)->content = tmp;
		if (ft_strchr((*list)->content, '\n') != NULL)
			break ;
	}
}

static void			ft_print(t_gnl_struct **list, char **line)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	while ((*list)->content[i] != '\n' && (*list)->content[i] != '\0')
		i++;
	(*line) = ft_strsub((*list)->content, 0, i);
	if ((str = ft_strchr((*list)->content, '\n')) != NULL)
	{
		str++;
		tmp = ft_strdup(str);
		free((*list)->content);
		(*list)->content = tmp;
	}
	else
	{
		(*list)->content = ft_strdup("");
	}
}

int					get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	t_gnl_struct		*tmp_list;
	static t_gnl_struct	*list;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	tmp_list = ft_create(&list, fd);
	tmp_list = ft_create(&tmp_list, fd);
	ft_read(&tmp_list, fd);
	if (ft_strlen(tmp_list->content) == 0)
		return (0);
	ft_print(&tmp_list, line);
	return (1);
}
