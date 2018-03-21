/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:22:59 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 14:02:06 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	find_place(int y, int x, t_db *db)
{
	int place;
	int r;
	int c;

	place = 0;
	r = 0;
	while (r < db->piece_rows - (db->trup + db->trbm))
	{
		c = 0;
		while (c < db->piece_cols - (db->tcl + db->tcr))
		{
			if ((db->piece[r + db->trup][c + db->tcl] == '*') && (db->map[y + r]
			[x + c] == db->player || db->map[y + r][x + c] == db->player + 32))
				place++;
			if (place > 1 || ((db->piece[r + db->trup][c + db->tcl] == '*') &&
			(db->map[y + r][x + c] == db->opponent || db->map[y + r][x + c]
			== db->opponent + 32)))
				return (0);
			c++;
		}
		r++;
	}
	if (place == 1)
		return (1);
	return (0);
}

int			check_piece_fit(int y, int x, t_db *db)
{
	if (y + db->piece_rows - (db->trup + db->trbm) > db->mp_rows)
		return (0);
	if (x + db->piece_cols - (db->tcl + db->tcr) > db->mp_cols)
		return (0);
	if (find_place(y, x, db))
		return (1);
	return (0);
}
