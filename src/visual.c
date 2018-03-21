/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:52:25 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 13:09:59 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void visualize(t_visual *vs, char *line)
{
	int	y;
	int	x;

	system("clear");
	ft_printf("💧 : player 0 == %s\n🔥 : player X == %s\n%s\n", vs->player1, vs->player2, line);
	ft_strdel(&line);
	y = 0;
	while (y < vs->mp_rows)
	{
		get_next_line(STDIN_FILENO, &line);
		x = 0;
		while (line[x])
		{
			if (line[x] == 'O' || line[x] == 'o')
				write(1, "💧", 4);
			else if (line[x] == 'X' || line[x] == 'x')
				write(1, "🔥", 4);
			else
				write(1, &line[x], 1);
			x++;
		}
		write(1, "\n", 1);
		ft_strdel(&line);
		y++;
	}
}

static void denote_piece_heigth(t_visual *vs, char *line)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (arr[1] && arr[2])
		vs->pc_rows = ft_atoi(arr[1]);
	ft_arrdel(&arr);
}

static void denote_map_heigth(t_visual *vs, char *line)
{
	char	**arr;

	get_next_line(STDIN_FILENO, &line);
	arr = ft_strsplit(line, ' ');
	ft_strdel(&line);
	if (arr[1] && arr[2])
		vs->mp_rows = ft_atoi(arr[1]);
	ft_arrdel(&arr);
}

static void skip_line(char *line, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strdel(&line);
		i++;
	}
}

static void read_players(t_visual *vs, char *line)
{

	int lst;
	get_next_line(STDIN_FILENO, &line);
	vs->player1 = ft_strdup(line + 23);
	ft_strdel(&line);
	lst = ft_strlen(vs->player1);
	vs->player1[lst - 1] = 0;
	skip_line(line, 1);
	get_next_line(STDIN_FILENO, &line);
	vs->player2 = ft_strdup(line + 23);
	ft_strdel(&line);
	lst = ft_strlen(vs->player2);
	vs->player2[lst - 1] = 0;
}

int check_line(t_visual *vs, char *line)
{
	if (line[0] == ' ')
	{
		visualize(vs, line);
		get_next_line(STDIN_FILENO, &line);
	}
	if (line[1] == 'i')
	{
		denote_piece_heigth(vs, line);
		skip_line(line, vs->pc_rows);
	}
	if (line[1] == 'g')
		get_next_line(STDIN_FILENO, &line);
	if (line[0] == '=')
	{
		if (!line)
			return (0);
		ft_printf("💧 :%s\n", line);
		ft_strdel(&line);
		get_next_line(STDIN_FILENO, &line);
		ft_printf("🔥 :%s\n", line);
		ft_strdel(&line);
		return (0);
	}
	return (1);
}

int	main(void)
{
	t_visual vs;

	char *line;
	line = NULL;
	skip_line(line, 6);
	read_players(&vs, line);
	denote_map_heigth(&vs, line);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!check_line(&vs, line))
			break ;
	}
	return (0);
}