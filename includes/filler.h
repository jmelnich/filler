#ifndef FILLER_H
# define FILLER_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/printflib.h"
# include <stdio.h> //del later

typedef struct  s_db
{
    char    player; //X or O
    char    opponent;
    int     pl_coord_x;
    int     pl_coord_y;
    int		mp_rows;
    int		mp_cols;
    char	**map;
    int     piece_rows;
    int     piece_cols;
    int     piece_x;
    int     piece_y;
    char    **piece;
    int     push_x;
    int     push_y;
}               t_db;

int             set_players(t_db *db);
int             denote_map(t_db *db);
int	            read_save_map(char *line, t_db *db);
void            find_player_coord(t_db *db);
int             denote_piece(char *line, t_db *db);
void	        place_piece(t_db *db);
int	            detect_best_direction(t_db *db);
int             check_piece_fit(int y, int x, t_db *db);

# endif