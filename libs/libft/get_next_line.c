/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:42:58 by imelnych          #+#    #+#             */
/*   Updated: 2017/12/22 18:15:58 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*find_relev_fd_list(t_list *scl, int fd)
{
	t_list	*temp;

	while (scl)
	{
		if ((int)scl->content_size == fd)
			return (scl);
		if (scl->next == NULL)
		{
			temp = ft_lstnew("\0", fd);
			scl->next = temp;
		}
		scl = scl->next;
	}
	return (scl);
}

int		get_line(t_list *current, char **line)
{
	char *pointer;
	char *tmp;

	if ((pointer = ft_strchr(current->content, '\n')) != NULL)
	{
		*pointer = '\0';
		*line = ft_strdup(current->content);
		tmp = current->content;
		current->content = ft_strdup(pointer + 1);
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

int		read_and_fill(t_list *current, int fd, char **line)
{
	int				bytes_read;
	char			*str;
	char			buff[BUFF_SIZE + 1];

	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		str = ft_strjoin(current->content, buff);
		free(current->content);
		current->content = NULL;
		current->content = str;
		if (get_line(current, line) == 1)
			return (1);
	}
	return ((bytes_read == -1) ? -1 : 0);
}

int		ft_check_errors(t_list *current, int fd, char **line)
{
	if (read_and_fill(current, fd, line) == 1)
		return (1);
	if (read_and_fill(current, fd, line) == -1)
		return (-1);
	if (!ft_strlen(current->content))
	{
		ft_strclr(*line);
		return (0);
	}
	if (get_line(current, line) == 1)
		return (1);
	*line = ft_strdup(current->content);
	ft_strclr(current->content);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*scl;
	t_list			*current;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || fd > 4096)
		return (-1);
	scl ? scl : (scl = ft_lstnew("\0", fd));
	current = find_relev_fd_list(scl, fd);
	return (ft_check_errors(current, fd, line));
}
