/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:47:25 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/12 03:40:50 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/get_next_line.h"
# include "libft.h"
# include "../MiniLibX/mlx.h"

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
	char		**map;
	int			row_x;
	int			col_y;
	char		player;
	char		coin;
	char		exit;
	t_point		playerpos;
	t_point		coinpos;
	t_point		exitpos;
	t_point		tools;
	t_count		counter;
}				t_game;

int	check_args(int argc, char **argv, t_game *game);
void	message(char *msg, t_game *game);
void	ft_start_game(t_game *game);
void	*ft_freemalloc(char **s2, int k);
int	ft_strlen_n(const char *var);

#endif