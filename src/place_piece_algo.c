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
	while (r < db->piece_rows - (db->trim_rows_up + db->trim_rows_bottom)) 
	{
		c = 0;
		while (c < db->piece_cols - (db->trim_cols_left + db->trim_cols_right)) // .**.
		{
			if ((db->piece[r + db->trim_rows_up][c + db->trim_cols_left] == '*') && (db->map[y + r][x + c] == db->player || db->map[y + r][x + c] == db->player + 32))
			{
				place++;
			}
			if (place > 1 || ((db->piece[r + db->trim_rows_up][c + db->trim_cols_left] == '*') && (db->map[y + r][x + c] == db->opponent || db->map[y + r][x + c] == db->opponent + 32)))
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
	if (y + db->piece_rows - (db->trim_rows_up + db->trim_rows_bottom) > db->mp_rows) 
		return (0);
	if (x + db->piece_cols - (db->trim_cols_left + db->trim_cols_right) > db->mp_cols)
		return (0);
	if(find_place(y, x, db))
		return (1);
	return (0);
}


