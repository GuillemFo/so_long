/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_to_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:14:10 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/05 13:56:29 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

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
	return (1);
}

int	moves(int keycode, void *param)
{
	int	flag;
	t_game *game;
	
	flag = 0;
	game = (t_game *)param;
	if (keycode == W_KEY)
	{
		if (check_move(game, 0) == 1)
			flag = apply_move(game, 0);
	}
	else if (keycode == S_KEY)
	{
		if (check_move(game, 1) == 1)
			flag = apply_move(game, 1);
	}
	else if (keycode == A_KEY)
	{
		if (check_move(game, 2) == 1)
			flag = apply_move(game, 2);
	}
	else if (keycode == D_KEY)
	{
		if (check_move(game, 3) == 1)
			flag = apply_move(game, 3);
	}
	if (flag == 2)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		game->mlx_win = mlx_new_window(game->mlx, 1920, 1080,
		"so_long-win gforns-s");
		img_win(game->mlx, game->mlx_win, game->img[7].img_ptr,
		0, 0);
		ft_printf("HOlaaaa\n");
		//mlx_hook(game->mlx_win, DESTROY, 0, close_window, game);
		//mlx_hook(game->mlx_win, ESC_KEY, 0, esc_window, game);
		//mlx_loop(game->mlx);
	}
	return (1); //pending to count moves.
}
