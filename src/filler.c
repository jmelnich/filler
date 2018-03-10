/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:49:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/09 19:47:56 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ perror
// ◦ strerror
#include "filler.h"

static void borders_map(t_db *db)
{
	int i;

	i = 0;
	db->map = (char**)malloc(sizeof(char*) * (db->mp_rows + 1));
	while(i < db->mp_rows)
		db->map[i++] = ft_strnew(db->mp_cols);
}

static int denote_map(char *line, t_db *db)
{
	char **arr;

	arr = ft_strsplit(line, ' ');
	db->mp_rows = ft_atoi(arr[1]);
	db->mp_cols = ft_atoi(arr[2]);
	ft_strdel(&line);
	while(*arr)
		ft_strdel(arr++);
	if (!(db->mp_rows) || !(db->mp_cols))
	{
		ft_printf("Error: Invalid map\n");
		return (-1);
	}
	borders_map(db);
	ft_strdel(&line);
	return (1);
}

static int set_players(char *line, t_db *db)
{
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
		ft_printf("Error: Bad player info\n");
		return (-1);
	}
	ft_strdel(&line);
	return (1);

}

int main(void)
{
	t_db db;
	char *line;

	ft_bzero(&db, sizeof(t_db));
    get_next_line(STDIN_FILENO, &line);
    if (set_players(line, &db) == -1)
		return(1); //invalid player name
	get_next_line(STDIN_FILENO, &line);
	if (denote_map(line, &db) == -1)
		return(2); //invalid map
	get_next_line(STDIN_FILENO, &line);
	draw_map(line);//нарисвоать карту?

	return (0);
}

