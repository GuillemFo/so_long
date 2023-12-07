/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_to_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:14:10 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/07 11:17:22 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

void	ft_thanos(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	game->mlx_win = mlx_new_window(game->mlx, 1252, 1252,
			"so_long-win gforns-s");
	img_win(game->mlx, game->mlx_win, game->img[8].img_ptr, 0, 0);
	mlx_hook(game->mlx_win, DESTROY, 0, close_window, game);
	mlx_hook(game->mlx_win, KEYDOWN, 0, esc_window, game);
	mlx_loop(game->mlx);
}

int	check_move(t_game *game, int dir)
{
	if (dir == 0)
	{
		if (game->map[game->ppos.y - 1][game->ppos.x] == '1')
			return (0);
	}
	else if (dir == 1)
	{
		if (game->map[game->ppos.y + 1][game->ppos.x] == '1')
			return (0);
	}
	else if (dir == 2)
	{
		if (game->map[game->ppos.y][game->ppos.x - 1] == '1')
			return (0);
	}
	else if (dir == 3)
	{
		if (game->map[game->ppos.y][game->ppos.x + 1] == '1')
			return (0);
	}
	printf("Moves: %d\n ", game->counter.moves++);
	return (1);
}

int	moves(int keycode, void *param)
{
	int		end;
	t_game	*game;

	end = 0;
	game = (t_game *)param;
	if (keycode == W_KEY && (check_move(game, 0) == 1))
		end = apply_move(game, 0);
	else if (keycode == S_KEY && (check_move(game, 1) == 1))
		end = apply_move(game, 1);
	else if (keycode == A_KEY && (check_move(game, 2) == 1))
		end = apply_move(game, 2);
	else if (keycode == D_KEY && (check_move(game, 3) == 1))
		end = apply_move(game, 3);
	else if (keycode == ESC_KEY)
		exit(mlx_destroy_window(game->mlx, game->mlx_win));
	if (end == 2)
		ft_thanos(game);
	return (1);
}
