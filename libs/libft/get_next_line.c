/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:03:41 by vibondar          #+#    #+#             */
/*   Updated: 2018/02/14 13:01:31 by vibondar         ###   ########.fr       */
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

// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2017/11/24 15:42:58 by imelnych          #+#    #+#             */
// /*   Updated: 2017/12/22 18:15:58 by imelnych         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// t_list	*find_relev_fd_list(t_list *scl, int fd)
// {
// 	t_list	*temp;

// 	while (scl)
// 	{
// 		if ((int)scl->content_size == fd)
// 			return (scl);
// 		if (scl->next == NULL)
// 		{
// 			temp = ft_lstnew("\0", fd);
// 			scl->next = temp;
// 		}
// 		scl = scl->next;
// 	}
// 	return (scl);
// }

// int		get_line(t_list *current, char **line)
// {
// 	char *pointer;
// 	char *tmp;

// 	if ((pointer = ft_strchr(current->content, '\n')) != NULL)
// 	{
// 		*pointer = '\0';
// 		*line = ft_strdup(current->content);
// 		tmp = current->content;
// 		current->content = ft_strdup(pointer + 1);
// 		ft_strdel(&tmp);
// 		return (1);
// 	}
// 	return (0);
// }

// int		read_and_fill(t_list *current, int fd, char **line)
// {
// 	int				bytes_read;
// 	char			*str;
// 	char			buff[BUFF_SIZE + 1];

// 	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		buff[bytes_read] = '\0';
// 		str = ft_strjoin(current->content, buff);
// 		free(current->content);
// 		current->content = NULL;
// 		current->content = str;
// 		if (get_line(current, line) == 1)
// 			return (1);
// 	}
// 	return ((bytes_read == -1) ? -1 : 0);
// }

// int		ft_check_errors(t_list *current, int fd, char **line)
// {
// 	if (read_and_fill(current, fd, line) == 1)
// 		return (1);
// 	if (read_and_fill(current, fd, line) == -1)
// 		return (-1);
// 	if (!ft_strlen(current->content))
// 	{
// 		ft_strclr(*line);
// 		return (0);
// 	}
// 	if (get_line(current, line) == 1)
// 		return (1);
// 	*line = ft_strdup(current->content);
// 	ft_strclr(current->content);
// 	return (1);
// }

// int		get_next_line(const int fd, char **line)
// {
// 	static t_list	*scl;
// 	t_list			*current;

// 	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || fd > 4096)
// 		return (-1);
// 	scl ? scl : (scl = ft_lstnew("\0", fd));
// 	current = find_relev_fd_list(scl, fd);
// 	return (ft_check_errors(current, fd, line));
// }
