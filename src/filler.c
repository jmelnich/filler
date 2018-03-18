/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:49:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/18 16:43:24 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ perror
// ◦ strerror
#include "filler.h"

int	main(void)
{
	t_db db;
	char *line;
	int i;

	line = NULL;
	ft_bzero(&db, sizeof(t_db));
	if (set_players(&db) == -1)
		return(1); 
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
		}
		else
			printf("0 0");
		get_next_line(STDIN_FILENO, &line);
		if (!ft_strcmp(line, "exit")) //del it later
		{
			ft_strdel(&line);
			ft_arrdel(db.map);
			ft_arrdel(db.piece);
			system("var=$(ps | grep ./imelnych.filler | grep -v grep | cut -d' ' -f1); leaks $var");
			return (0);
		}
		//ft_strdel(&line);
	 }
	ft_arrdel(db.map);
	ft_arrdel(db.piece);
	return (0);
}
