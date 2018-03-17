/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:49:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/16 11:23:51 by imelnych         ###   ########.fr       */
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
    if (set_players(&db) == -1)
		return(1); //invalid player name
 	if (denote_map(&db) == -1)
 	    return(2); //invalid map coords (0 0)
	 i = 0;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	 {
	 	read_save_map(line, &db);
	 	if (!i)
	 	{
    		find_player_coord(&db);
	 		i = 1;
	 	}
		denote_piece(line, &db);
		if(place_piece(&db)) {
			ft_putnbr(db.push_y);
			write(1, " ", 1);
			ft_putnbr(db.push_x);
			write(1, "\n", 1);
			//printf("%d %d\n", db.push_y, db.push_x);
		}
		else
			printf("0 0");
		get_next_line(STDIN_FILENO, &line);
		//ft_strdel(&line);
	 }
 //    ft_arrdel(db.map);
	// ft_arrdel(db.piece);
	return (0);
}
