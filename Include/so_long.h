/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:47:25 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/12 11:07:38 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/get_next_line.h"
# include "../MiniLibX/mlx.h"
# include "libft.h"




/*### SIZE INSTRUCTIONS ###*/ 
/*### Screen resolution DIVIDE 128 and rounded to the smaller one ###*/
/*### Example: 1920x1080 = 15 W and 8.4 H (so you will round to 8) */
/*### Max accepted number is 120 in both options ###*/
/*### I will set the max lenght of map to the values set down ###*/
# define SCREEN_W 120
# define SCREEN_H 120



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

/*##	DEFINE TO SHORT CODE	##*/
# define IMG_WIN mlx_put_image_to_window

typedef struct s_data
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
	int		coin;
	int		player;
	int		exit;
	int		moves;
}			t_count;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*nw_img;
	char	**map;
	int		col_x;
	int		row_y;
	char	player;
	char	coin;
	char	exit;
	t_point	ppos;
	t_point	prepos;
	t_point	next_pos;
	t_point	coinpos;
	t_point	epos;
	t_point	tools;
	t_count	counter;
	t_data	img[20];
}			t_game;

int			check_args(int argc, char **argv, t_game *game);
void		message(char *msg);
void		ft_start_game(t_game *game);
void		*ft_freemalloc_2(char **s2, int k);
int			ft_strlen_n(const char *var);
int			apply_move(t_game *game, int dir);
int			moves(int keycode, void *param);
int			close_window(void *param);
int			esc_window(int keycode, void *param);
int			if_prev_door(t_game *game);
t_game		*precal_next_mv(t_game *game, int dir);
t_game		*write_move_on_map(t_game *game, int dir);
int			check_args(int argc, char **argv, t_game *game);
void		check_bounds(t_game *game, char **game_test);
void		find_pos(t_game *game, char **game_test);
void		count_obj(t_game *game, char **game_test);
void		ft_start_game(t_game *game);
int			check_ber(char *argv, char *text);
void		gen_print_up(t_game *game, t_point floor, t_point player1);
void		gen_print_down(t_game *game, t_point floor, t_point player1);
void		gen_print_left(t_game *game, t_point floor, t_point player1);
void		gen_print_right(t_game *game, t_point floor, t_point player1);

/*IMAGES*/

void		put_images(t_game game);

#endif