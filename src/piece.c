/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:32:28 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/17 11:04:14 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	trim_piece_rows(t_db *db)
{
	int y;
	int x;

	db->trim_rows_up = 0;
	db->trim_rows_bottom = 0;
	y = 0;
	x = 0;
	while (y < db->piece_rows - 1)
	{
		if (db->piece[y][x] == '.')
		{
			x++;
		}
		else if (!db->piece[y][x])
		{
			y++;
			db->trim_rows_up++;
			x = 0;
		}
		else
		{
			break ;
		}
	}
	y = db->piece_rows - 1;
	x = 0;
	while (y)
	{
		if (db->piece[y][x] == '.')
		{
			x++;
		}
		else if (!db->piece[y][x])
		{
			y--;
			db->trim_rows_bottom++;
			x = 0;
		}
		else
			break ;
	}

}

static void	trim_piece_cols(t_db *db)
{
	int y;
	int x;

	db->trim_cols_left = 0;
	db->trim_cols_right = 0;
	y = 0;
	x = 0;
	while (x < db->piece_cols - 1) // 0 < 2 // 0 < 1
	{
		if (db->piece[y][x] == '.' && (y != db->piece_rows - 1))
		{
			y++;
		}
		else if (y == db->piece_rows - 1)
		{
			x++;
			db->trim_cols_left++;
			y = 0;
		}
		else
			break ;
	}
	x = db->piece_cols - 1;
	y = 0;
	while (x)
	{
		if (db->piece[y][x] == '.' && (y != db->piece_rows - 1))
			y++;
		else if (y == db->piece_rows - 1)
		{
			x--;
			db->trim_cols_right++;
			y = 0;
		}
		else
			break ;
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
    }
    trim_piece_rows(db);
    trim_piece_cols(db);
    printf("\ntrim up = %d\n, trim bottom = %d\n, trim left = %d\n, trim right = %d\n", db->trim_rows_up, db->trim_rows_bottom, db->trim_cols_left, db->trim_cols_right);
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

    //ft_arrdel(arr);
    //ft_strdel(&line);
    space_alloc_piece(db);
    read_save_piece(line, db);
    return (1);
}
