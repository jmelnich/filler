#ifndef FILLER_H
# define FILLER_H

# include "../libs/libft/libft.h"
# include <stdio.h> //del later
//map.c players.c and filler.c -> change printf for ft_printf! add ft_printf to filler.h

typedef struct s_db
{
	char    player; //X or O
	char    opponent;
	int     pl_coord_x;
	int     pl_coord_y;
	int     direction;
	int     mp_rows;
	int     mp_cols;
	char    **map;
	int     piece_rows;
	int     piece_cols;
	char    **piece;
	int     trim_rows_up;
	int     trim_rows_bottom;
	int     trim_cols_left;
	int     trim_cols_right;
	int     push_x;
	int     push_y;
}              t_db;

typedef struct s_visual
{
	char        *player1;
	char        *player2;
	int         mp_rows;
	int         pc_rows;
}               t_visual;

int             set_players(t_db *db);
int             denote_map(t_db *db);
int	            read_save_map(char *line, t_db *db);
void            find_player_coord(t_db *db);
void	        detect_best_direction(t_db *db);
int             denote_piece(char *line, t_db *db);
int             place_piece(t_db *db);
int             check_piece_fit(int y, int x, t_db *db);

# endif