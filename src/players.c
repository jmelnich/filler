/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:24:49 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/13 14:24:52 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
}

void find_opponent_coord(t_db *db)
{
    int x;
    int y;

    y = 0;
    while (db->map[y])
    {
        x = 0;
        while (db->map[y][x])
        {
            if (db->map[y][x] == db->opponent)
            {
                db->op_coord_x = x;
                db->op_coord_y = y;
            }
            x++;
        }
        y++;
    }
}

int set_players(char *line, t_db *db)
{
    get_next_line(STDIN_FILENO, &line);
    if (ft_strlen(line) < 10)
    {
        ft_printf("Error: Bad player name. Too short name.\n");
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
        ft_printf("Error: Bad player name\n");
        ft_strdel(&line);
        return (-1);
    }
    ft_strdel(&line);
    return (1);
}