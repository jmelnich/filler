/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:22:59 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/15 17:40:25 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int find_place(int y, int x, t_db *db)
{
	int place;
	int r;
	int c;

	place = 0;
	r = 0;
	while (r < db->piece_rows)
	{
		c = 0;
		while (c < db->piece_cols)
		{
			if ((db->map[y + r][x + c] == db->player || db->map[y + r][x + c] == db->player + 32) && (db->piece[r][c] == '*'))
			{
					place++;
			}
			if ((db->map[y + r][x + c] == db->opponent || db->map[y + r][x + c] == db->opponent + 32) && (db->piece[r][c] == '*'))
				return (0);
			c++;
		}
		r++;
	}
    if (place == 1)
        return (1);
    return  (0);

}

int check_piece_fit(int y, int x, t_db *db) //if 0, everything is failed, we go back to move and iterate, trying again
{
	if (y + db->piece_rows > db->mp_rows) // maybe better check not the figure h/w but only *** (so I have to trim it before in another fnc)
		return (0);
	if (x + db->piece_cols > db->mp_cols)
		return (0);
	if(find_place(y, x, db))
		return (1);
	return (0);
}

int	detect_best_direction(t_db *db)
{
	if (db->pl_coord_y >= db->mp_rows / 2 && db->pl_coord_x >= db->mp_cols / 2)
		return (1); //going up and left
	else if (db->pl_coord_y >= db->mp_rows / 2 && db->pl_coord_x <= db->mp_cols / 2)
		return (2); //going up and right
	else if (db->pl_coord_y <= db->mp_rows / 2 && db->pl_coord_x >= db->mp_cols / 2)
		return (3); //going down and left
	else if (db->pl_coord_y <= db->mp_rows / 2 && db->pl_coord_x <= db->mp_cols / 2)
		return (4); //going down and right
	else
		return (5); //doesn't matter
}