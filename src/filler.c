/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:49:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/13 17:03:31 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ perror
// ◦ strerror
#include "filler.h"

int main(void)
{
	t_db db;
	char *line;

    line = NULL;
	ft_bzero(&db, sizeof(t_db));
    if (set_players(line, &db) == -1)
		return(0); //invalid player name
	if (denote_map(line, &db) == -1)
		return(0); //invalid map coords (0 0)
	find_player_coord(&db);
    find_opponent_coord(&db);
	denote_piece(line, &db);
    place_piece(&db);
    //ft_printf("coord y == %d\n coord x == %d\n", db.push_y, db.push_x);
	ft_printf("%d %d\n", db.push_y, db.push_x);
	return (1);
}
