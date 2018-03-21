/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:12:59 by imelnych          #+#    #+#             */
/*   Updated: 2018/03/21 14:17:04 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libs/libft/libft.h"

typedef struct	s_db
{
	char	player;
	char	opponent;
	int		pl_coord_x;
	int		pl_coord_y;
	int		found_pl;
	int		direction;
	int		mp_rows;
	int		mp_cols;
	char	**map;
	int		piece_rows;
	int		piece_cols;
	char	**piece;
	int		trup;
	int		trbm;
	int		tcl;
	int		tcr;
	int		push_x;
	int		push_y;
}				t_db;

typedef struct	s_visual
{
	char	*player1;
	char	*player2;
	int		mp_rows;
	int		pc_rows;
}				t_visual;

int				set_players(char *line, t_db *db);
int				denote_map(char *line, t_db *db);
int				read_save_map(char *line, t_db *db);
void			find_player_coord(t_db *db);
void			detect_best_direction(t_db *db);
int				denote_piece(char *line, t_db *db);
int				read_save_piece(t_db *db);
int				place_piece(t_db *db);
int				check_piece_fit(int y, int x, t_db *db);

#endif
