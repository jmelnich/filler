/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:32:28 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 12:58:03 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int denote_piece(char *line, t_db *db)
{
	char **arr;

	if (db->piece)
		ft_arrdel(&db->piece);
	get_next_line(STDIN_FILENO, &line);
	arr = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (arr[1] && arr[2])
	{
		db->piece_rows = ft_atoi(arr[1]);
		db->piece_cols = ft_atoi(arr[2]);
	}
	else
	{
		if (arr)
			ft_arrdel(&arr);
		ft_putstr("Error: Invalid token coordinates\n");
		return (-1);
	}
	if (!(db->piece_rows) || !(db->piece_cols))
	{
		if (arr)
			ft_arrdel(&arr);
		ft_putstr("Error: Token coordinates can't be null\n");
		return (-1);
	}

	ft_arrdel(&arr);
	db->piece = ft_arrnew(db->piece_rows, db->piece_cols);
	read_save_piece(db);
	return (1);
}
