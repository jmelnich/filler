/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:24:49 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 14:04:46 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set_players(char *line, t_db *db)
{
	get_next_line(STDIN_FILENO, &line);
	if (ft_strlen(line) < 10)
	{
		ft_putstr("Error: Bad player name. Use: -p1 NAME or -p2 NAME\n");
		ft_strdel(&line);
		return (-1);
	}
	if (line[10] == '1')
	{
		db->player = 'O';
		db->opponent = 'X';
	}
	else if (line[10] == '2')
	{
		db->player = 'X';
		db->opponent = 'O';
	}
	else
	{
		ft_putstr("Error: Bad player name. Use: -p1 NAME or -p2 NAME\n");
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (1);
}
