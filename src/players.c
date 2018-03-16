/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:24:49 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/13 17:00:03 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	detect_best_direction(t_db *db)
{
	if (db->pl_coord_y >= db->mp_rows / 2 && db->pl_coord_x >= db->mp_cols / 2)
		db->direction = 1; //going up and left
	else if (db->pl_coord_y >= db->mp_rows / 2 && db->pl_coord_x <= db->mp_cols / 2)
		db->direction = 2; //going up and right
	else if (db->pl_coord_y <= db->mp_rows / 2 && db->pl_coord_x >= db->mp_cols / 2)
		db->direction = 3; //going down and left
	else if (db->pl_coord_y <= db->mp_rows / 2 && db->pl_coord_x <= db->mp_cols / 2)
		db->direction = 4; //going down and right
	else
		db->direction = 5; //doesn't matter
}

void find_player_coord(t_db *db)
{
    int x;
    int y;

    y = 0;
    while (db->map[y])
    {
        x = 0;
        while (db->map[y][x])
        {
            if (db->map[y][x] == db->player)
            {
                db->pl_coord_x = x;
                db->pl_coord_y = y;
            }
            x++;
        }
        y++;
    }
    detect_best_direction(db);
}

int set_players(t_db *db)
{
    char *line;

    get_next_line(STDIN_FILENO, &line);
    if (ft_strlen(line) < 10)
    {
        printf("Error: Bad player name. Too short name.\n");
        ft_strdel(&line);
        return (-1);
    }
    if (line[10] == '1')
    {
        db->player = 'O';
        db->opponent = 'X';
    }
    else if (line[10] == '2')
    {
        db->player = 'X';
        db->opponent = 'O';
    }
    else
    {
        printf("Error: Bad player name\n");
        ft_strdel(&line);
        return (-1);
    }
    ft_strdel(&line);
    return (1);
}