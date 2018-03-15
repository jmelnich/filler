/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:49:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/15 15:19:31 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ perror
// ◦ strerror
#include "filler.h"

int main(void)
{
	t_db db;
	char *line;
	//int i;

    line = NULL;
	ft_bzero(&db, sizeof(t_db));
    if (set_players(&db) == -1)
		return(1); //invalid player name
 	if (denote_map(&db) == -1)
 	    return(2); //invalid map coords (0 0)
	while (get_next_line(STDIN_FILENO, &line) > 0)
	 {
	 	read_save_map(line, &db);
	 	// i = 0;
	 	// printf("\n");
	 	// while (db.map[i])
	 	// {
	 	// 	printf("Map == %s\n", db.map[i++]);
	 	// }
    	find_player_coord(&db);
		denote_piece(line, &db);
		// i = 0;
		// while (db.piece[i])
	 // 	{
	 // 		printf("Piece == %s\n", db.piece[i++]);
	 // 	}
	 // 	printf("out");
		place_piece(&db);
		ft_printf("%d %d\n", db.push_y, db.push_x);
		get_next_line(STDIN_FILENO, &line);
		ft_strdel(&line);
		get_next_line(STDIN_FILENO, &line);
		ft_strdel(&line);
	 }
 //    ft_arrdel(db.map);
	// ft_arrdel(db.piece);
	return (0);
}
