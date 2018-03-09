/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:49:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/09 18:46:12 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ perror
// ◦ strerror
#include "filler.h"

static int set_map(char *line, t_db *db)
{
	char **arr;

	arr = ft_strsplit(line, ' ');
	db->mp_rows = ft_atoi(arr[1]);
	db->mp_cols = ft_atoi(arr[2]);
	ft_strdel(&line);
	while(*arr)
		ft_strdel(arr++);
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
		return(1);
	get_next_line(STDIN_FILENO, &line);
	set_map(line, &db);

	return (1);
}

