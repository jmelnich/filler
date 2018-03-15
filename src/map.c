/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:02:02 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/15 14:46:38 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
    return (1);
}

static void space_alloc_map(t_db *db)
{
	int i;

	i = 0;
	db->map = (char**)malloc(sizeof(char*) * (db->mp_rows + 1)); //free at the end
	while(i < db->mp_rows)
		db->map[i++] = ft_strnew(db->mp_cols);
	db->map[i] = 0;
}

int denote_map(t_db *db)
{
    char *line;
	char **arr;

    get_next_line(STDIN_FILENO, &line);
	arr = ft_strsplit(line, ' ');
	db->mp_rows = ft_atoi(arr[1]);
	db->mp_cols = ft_atoi(arr[2]); //should i free them at the end?
	ft_strdel(&line);
    ft_arrdel(arr);
	if (!(db->mp_rows) || !(db->mp_cols))
	{
		ft_printf("Error: Invalid map\n");
		return (-1);
	}
	space_alloc_map(db);
    return (1);
}