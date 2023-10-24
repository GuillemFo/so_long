/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:47:25 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/24 16:26:15 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "../MiniLibX/mlx.h"

typedef struct s_game
{
	int		row;
	int		col;
	int		player;
	int		coins;
	int		exit;
	char	**game_test;
	char	**game_ok;
}			t_game;

char	**check_args(int argc, char **argv, t_game *game);

#endif