/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:02:02 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/19 14:28:35 by imelnych         ###   ########.fr       */
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

void	find_player_coord(t_db *db)
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

int	read_save_map(char *line, t_db *db)
{
	int	i;

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

int denote_map(t_db *db)
{
	char	*line;
	char	**arr;

	get_next_line(STDIN_FILENO, &line);
	arr = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (arr[1] && arr[2])
	{
		db->mp_rows = ft_atoi(arr[1]);
		db->mp_cols = ft_atoi(arr[2]);
	}
	else
	{
		ft_putstr("Error: Invalid map coordinates\n");
		ft_arrdel(arr);
		free(arr);
		return (-1);
	}
	if (!(db->mp_rows) || !(db->mp_cols))
	{
		ft_putstr("Error: Map coordinates can't be null\n");
		ft_arrdel(arr);
		free(arr);
		return (-1);
	}
	ft_arrdel(arr);
	free(arr);
	db->map = ft_arrnew(db->mp_rows, db->mp_cols);
	return (1);
}