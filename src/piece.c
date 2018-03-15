/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:32:28 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/15 12:09:36 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

 static void	find_piece_start(t_db *db)
{
    int y;
    int x;

    y = 0;
    db->piece_y = -1;
    db->piece_x = -1;
    while (y < db->piece_rows)
    {
        x = 0;
        while (x < db->piece_cols)
        {
            if (db->piece[y][x] == '*')
            {
                if (db->piece_y == -1)
                    db->piece_y = y;
                if (db->piece_x == -1 || db->piece_x > x)
                    db->piece_x = x;
            }
            x++;
        }
        y++;
    }
}

static int read_save_piece(char *line, t_db *db)
{
    int i;

    i = 0;
    while (i < db->piece_rows)
    {
        get_next_line(STDIN_FILENO, &line);
        ft_strcpy(db->piece[i++], line);
        ft_strdel(&line);
        find_piece_start(db);
    }
    return (1);
}

static void space_alloc_piece(t_db *db)
{
    int i;

    i = 0;
    db->piece = (char**)malloc(sizeof(char*) * (db->piece_rows + 1)); //free at the end?
    while(i < db->piece_rows)
        db->piece[i++] = ft_strnew(db->piece_cols);
    db->piece[i] = 0;
}

int denote_piece(char *line, t_db *db)
{
    char **arr;
    if (!(get_next_line(STDIN_FILENO, &line)))
        return (0);
    arr = ft_strsplit(line, ' ');
    db->piece_rows = ft_atoi(arr[1]);
    db->piece_cols = ft_atoi(arr[2]);
    ft_arrdel(arr);
    ft_strdel(&line);
    space_alloc_piece(db);
    read_save_piece(line, db);
    return (1);
}