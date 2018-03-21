/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:02:02 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 17:07:07 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		detect_best_direction(t_db *db)
{
	if (db->pl_coord_y >= db->mp_rows / 2 &&
		db->pl_coord_x >= db->mp_cols / 2)
		db->direction = 1;
	else if (db->pl_coord_y >= db->mp_rows / 2 &&
		db->pl_coord_x <= db->mp_cols / 2)
		db->direction = 2;
	else if (db->pl_coord_y <= db->mp_rows / 2 &&
		db->pl_coord_x >= db->mp_cols / 2)
		db->direction = 3;
	else if (db->pl_coord_y <= db->mp_rows / 2 &&
		db->pl_coord_x <= db->mp_cols / 2)
		db->direction = 4;
	else
		db->direction = 5;
}

void		find_player_coord(t_db *db)
{
	int		x;
	int		y;

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
				db->found_pl = 1;
				break ;
			}
			x++;
		}
		y++;
	}
	detect_best_direction(db);
}

int			read_save_map(char *line, t_db *db)
{
	int		i;

	i = 0;
	ft_strdel(&line);
	while (i < db->mp_rows)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strcpy(db->map[i++], line + 4);
		ft_strdel(&line);
	}
	return (0);
}

static int	get_data_map(char *line, t_db *db)
{
	char **arr;

	arr = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (arr[1] && arr[2])
	{
		db->mp_rows = ft_atoi(arr[1]);
		db->mp_cols = ft_atoi(arr[2]);
	}
	else
	{
		if (arr)
			ft_arrdel(&arr);
		ft_putstr("Error: Invalid map coordinates\n");
		return (-1);
	}
	ft_arrdel(&arr);
	return (1);
}

int			denote_map(char *line, t_db *db)
{
	get_next_line(STDIN_FILENO, &line);
	if (get_data_map(line, db) == -1)
		return (-1);
	if (!(db->mp_rows) || !(db->mp_cols))
	{
		ft_putstr("Error: Map coordinates can't be null\n");
		return (-1);
	}
	db->map = ft_arrnew(db->mp_rows, db->mp_cols);
	return (1);
}
