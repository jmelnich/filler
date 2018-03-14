/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:48:14 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/13 20:26:30 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	move_up_left(t_db *db)
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
				db->push_y = y;
				db->push_x = x;
				return (1); // we can place piece, return success
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	move_up_right(t_db *db)
{

}

static int	move_down_left(t_db *db)
{

}

static int	move_down_right(t_db *db)
{

}

void	place_piece(t_db *db)
{
	int direction;

	direction = detect_best_direction(db);
	printf("\nWE GO %i\n", direction);
	if (direction == 1 || direction == 5)
		move_up_left(db);
	if (direction == 2)
		move_up_right(db);
	if (direction == 3)
		move_down_left(db);
	if (direction == 4)
		move_down_right(db);
}