/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:48:14 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 17:14:07 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	move_from_up_left(t_db *db)
{
	int x;
	int y;

	y = 0;
	while (y < db->mp_rows)
	{
		x = 0;
		while (x < db->mp_cols)
		{
			if (check_piece_fit(y, x, db))
			{
				db->push_x = x - db->tcl;
				db->push_y = y - db->trup;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	move_from_up_right(t_db *db)
{
	int x;
	int y;

	y = 0;
	while (y < db->mp_rows)
	{
		x = db->mp_cols;
		while (x > 0)
		{
			if (check_piece_fit(y, x, db))
			{
				db->push_x = x - db->tcl;
				db->push_y = y - db->trup;
				return (1);
			}
			x--;
		}
		y++;
	}
	return (0);
}

static int	move_from_down_left(t_db *db)
{
	int x;
	int y;

	y = db->mp_rows;
	while (y > 0)
	{
		x = 0;
		while (x < db->mp_cols)
		{
			if (check_piece_fit(y, x, db))
			{
				db->push_x = x - db->tcl;
				db->push_y = y - db->trup;
				return (1);
			}
			x++;
		}
		y--;
	}
	return (0);
}

static int	move_from_down_right(t_db *db)
{
	int x;
	int y;

	y = db->mp_rows;
	while (y > 0)
	{
		x = db->mp_cols;
		while (x > 0)
		{
			if (check_piece_fit(y, x, db))
			{
				db->push_x = x - db->tcl;
				db->push_y = y - db->trup;
				return (1);
			}
			x--;
		}
		y--;
	}
	return (0);
}

int			place_piece(t_db *db)
{
	int direction;

	direction = db->direction;
	if (direction == 1 || direction == 5)
		(move_from_up_left(db) == 1) ? return (1) : return (0); //добавить рекурсивно вызов других сторон
	if (direction == 2)
		(move_from_up_right(db) == 1) ? return (1) : return (0);
	if (direction == 3)
		(move_from_down_left(db) == 1) ? return (1) : return (0);
	if (direction == 4)
		(move_from_down_right(db) == 1) ? return (1) : return (0); //wtf???
}
