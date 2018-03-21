/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:49:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 19:45:24 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fillit(t_db *db)
{
	if (place_piece(db) == 1)
	{
		ft_putnbr(db->push_y);
		write(1, " ", 1);
		ft_putnbr(db->push_x);
		write(1, "\n", 1);
	}
	else
		ft_printf("0 0\n");
}

int			main(void)
{
	t_db	db;
	char	*line;

	line = NULL;
	ft_bzero(&db, sizeof(t_db));
	if (set_players(line, &db) == -1)
		return (1);
	if (denote_map(line, &db) == -1)
		return (2);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		read_save_map(line, &db);
		if (db.found_pl == 0)
			find_player_coord(&db);
		if (denote_piece(line, &db) == -1)
			return (1);
		fillit(&db);
		get_next_line(STDIN_FILENO, &line);
		if (line[1] == 'l')
			ft_strdel(&line);
	}
	ft_arrdel(&db.map);
	ft_arrdel(&db.piece);
	return (0);
}
