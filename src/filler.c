/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:49:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/13 15:02:31 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ perror
// ◦ strerror
#include "filler.h"

int main(void)
{
	t_db db;
	char *line;
	int i;

    line = NULL;
	ft_bzero(&db, sizeof(t_db));
    if (set_players(line, &db) == -1)
		return(0); //invalid player name
	if (denote_map(line, &db) == -1)
		return(0); //invalid map coords (0 0)
	find_player_coord(&db);
    find_opponent_coord(&db);
	denote_piece(line, &db);
	i = 0;
	printf("PIECE ==== %s\n", db.piece[i]);
	return (1);
}

