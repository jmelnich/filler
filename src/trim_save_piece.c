/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_save_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:58:20 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 13:55:08 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	trim_piece_rows_up(t_db *db)
{
	int	y;
	int	x;

	db->trup = 0;
	y = 0;
	x = 0;
	while (y < db->piece_rows - 1)
	{
		if (db->piece[y][x] == '.')
			x++;
		else if (!db->piece[y][x])
		{
			y++;
			db->trup++;
			x = 0;
		}
		else
			break ;
	}
}

static void	trim_piece_rows_bottom(t_db *db)
{
	int	y;
	int	x;

	db->trbm = 0;
	y = db->piece_rows - 1;
	x = 0;
	while (y)
	{
		if (db->piece[y][x] == '.')
			x++;
		else if (!db->piece[y][x])
		{
			y--;
			db->trbm++;
			x = 0;
		}
		else
			break ;
	}
}

static void	trim_piece_cols_left(t_db *db)
{
	int	y;
	int	x;

	db->tcl = 0;
	y = 0;
	x = 0;
	while (x < db->piece_cols - 1)
	{
		if (db->piece[y][x] == '.' && (y != db->piece_rows - 1))
			y++;
		else if (db->piece[y][x] == '.' && (y == db->piece_rows - 1))
		{
			x++;
			db->tcl++;
			y = 0;
		}
		else
			break ;
	}
}

static void	trim_piece_cols_right(t_db *db)
{
	int	y;
	int	x;

	db->tcr = 0;
	x = db->piece_cols - 1;
	y = 0;
	while (x)
	{
		if (db->piece[y][x] == '.' && (y != db->piece_rows - 1))
			y++;
		else if (db->piece[y][x] == '.' && (y == db->piece_rows - 1))
		{
			x--;
			db->tcr++;
			y = 0;
		}
		else
			break ;
	}
}

int			read_save_piece(t_db *db)
{
	char	*line;
	int		i;

	i = 0;
	while (i < db->piece_rows)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strcpy(db->piece[i++], line);
		ft_strdel(&line);
	}
	trim_piece_rows_up(db);
	trim_piece_rows_bottom(db);
	trim_piece_cols_left(db);
	trim_piece_cols_right(db);
	return (1);
}
