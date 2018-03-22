/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:55:01 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/22 10:58:38 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	skip_line(char *line, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strdel(&line);
		i++;
	}
}

void	read_players(t_visual *vs, char *line)
{
	int lst;

	get_next_line(STDIN_FILENO, &line);
	vs->player1 = ft_strdup(line + 23);
	ft_strdel(&line);
	lst = ft_strlen(vs->player1);
	vs->player1[lst - 1] = 0;
	skip_line(line, 1);
	get_next_line(STDIN_FILENO, &line);
	vs->player2 = ft_strdup(line + 23);
	ft_strdel(&line);
	lst = ft_strlen(vs->player2);
	vs->player2[lst - 1] = 0;
}
