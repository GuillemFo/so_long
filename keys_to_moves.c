/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_to_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:14:10 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/30 09:51:06 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

int	check_move(t_game *game, int x, int y, int dir)
{
	int	result;
	if (dir == 0)
	{
		if (game->map[y + 1][x] == '1')
			return (0);
	}
	else if (dir == 1)
	{
		if (game->map[y - 1][x] == '1')
			return (0);
	}
	else if (dir == 2)
	{
		if (game->map[y][x - 1] == '1')
			return (0);
	}
	else if (dir == 3)
	{
		if (game->map[y][x + 1] == '1')
			return (0);
	}
	return (1);
}


int	moves_test(int keycode, void *param)
{
	t_game *game;
	game = (t_game *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		ft_printf("The game has closed successfully\n");
		exit(ft_printf("The game has closed successfully\n"), 0);
	}
	return (0);
}
int	moves(int keycode, void *param)
{
	t_game *game;
	game = (t_game *)param;						//// DONT REMEMBER WHY I DO THIS INSTEAD OF USING THE ORIGINAL 😅😅😅😅😅 RECAST TO T_GAME??
	if (keycode == "W" || keycode == "ARROW_UP")
	{
		if (check_move(game, game->playerpos.x, game->playerpos.y, 0) == 1)
			apply_move(game, game->playerpos.x, game->playerpos.y, 0); // DELETIG * FROM *GAME
	}
	else if (keycode == "S" || keycode == "ARROW_DOWN")
	{
		if (check_move(game, game->playerpos.x, game->playerpos.y, 1) == 1)
			apply_move(game, game->playerpos.x, game->playerpos.y, 1);
	}
	else if (keycode == "A" || keycode == "ARROW_LEFT")
	{
		if (check_move(game, game->playerpos.x, game->playerpos.y, 2) == 1)
			apply_move(game, game->playerpos.x, game->playerpos.y, 2);
	}
	else if (keycode == "D" || keycode == "ARROW_RIGHT")
	{
		if (check_move(game, game->playerpos.x, game->playerpos.y, 3) == 1)
			apply_move(game, game->playerpos.x, game->playerpos.y, 3);
	}
}
