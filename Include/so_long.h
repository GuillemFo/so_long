/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:47:25 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:15:52 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/get_next_line.h"
# include "libft.h"
# include "../MiniLibX/mlx.h"


/*###	KEY MAPPING	###*/
# define ESC_KEY 0x35
# define PLUS_KEY 0x45
# define MINUS_KEY 0x4E
# define ONE_KEY 0x12
# define TWO_KEY 0x13
# define THREE_KEY 0x14
# define O_KEY 0x1F
# define P_KEY 0x23
# define A_KEY 0x00
# define S_KEY 0x01
# define D_KEY 0x02
# define W_KEY 0x0D
# define T_KEY 0x11
# define X_KEY 0x07
# define Y_KEY 0x10
# define Z_KEY 0x06
# define N_KEY 0x2D
# define M_KEY 0x2E
# define G_KEY 0x05
# define C_KEY 0x08
# define I_KEY 0x22
# define H_KEY 0x04

/*###	X11 EVENTS SUPPORTED BY MINILIBX	###*/
# define KEYDOWN 2
# define KEYUP 3
# define MOUSEDOWN 4
# define MOUSEUP 5
# define MOUSEMOVE 6
# define EXPOSE 12
# define DESTROY 17

/*###	MOUSE EVENTS	###*/
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MID_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef	struct s_data
{
	void	*img_ptr;
	int		size_l;
	int		endian;
}			t_data;


typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_count
{
	int	coin;
	int	player;
	int	exit;
	int	moves;
}		t_count;

typedef struct s_game		//donde meto la poss de diferentes monedas?
{
	void		*mlx;
	void		*mlx_win;
	void		*nw_img;
	char		**map;
	int			col_x;
	int			row_y;
	char		player;
	char		coin;
	char		exit;
	t_point		playerpos;
	t_point		next_pos;
	t_point		coinpos;
	t_point		exitpos;
	t_point		tools;
	t_count		counter;
	t_data		img[20];
}				t_game;

int	check_args(int argc, char **argv, t_game *game);
void	message(char *msg, t_game *game);
void	ft_start_game(t_game *game);
void	*ft_freemalloc(char **s2, int k);
int	ft_strlen_n(const char *var);
int		apply_move(t_game *game, int dir);
int	moves(int keycode, void *param);

/*IMAGES*/

void	put_images(t_game game);
/*Tools*/
void print_matrix(char **matrix, int rows, int cols);

#endif