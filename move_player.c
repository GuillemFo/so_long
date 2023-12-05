/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:54:44 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/05 15:13:13 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

void	gen_print(t_game *game, t_point floor, t_point player1)
{
	img_win(game->mlx, game->mlx_win, game->img[0].img_ptr, floor.x * 32,
		floor.y * 32);
	img_win(game->mlx, game->mlx_win, game->img[4].img_ptr, player1.x * 32,
		player1.y * 32);
}

void	print_new_player(t_game *game, int dir)
{
	if (dir == 0)
		gen_print(game, (t_point){game->ppos.x, game->ppos.y + 1}, game->ppos);
	else if (dir == 1)
		gen_print(game, (t_point){game->ppos.x, game->ppos.y - 1}, game->ppos);
	else if (dir == 2)
		gen_print(game, (t_point){game->ppos.x + 1, game->ppos.y}, game->ppos);
	else if (dir == 3)
		gen_print(game, (t_point){game->ppos.x - 1, game->ppos.y}, game->ppos);
}

int	apply_move(t_game *game, int dir)
{
	precal_next_mv(game, dir);
	if_prev_door(game);
	if (game->map[game->next_pos.y][game->next_pos.x] == 'E')
	{
		write_move_on_map(game, dir);
		if (if_prev_door(game) == 0)
			print_new_player(game, dir);
		if (game->counter.coin == 0)
			return (2);
	}
	else if (game->map[game->next_pos.y][game->next_pos.x] == '0')
	{
		write_move_on_map(game, dir);
		if (if_prev_door(game) == 0)
			print_new_player(game, dir);
	}
	else if (game->map[game->next_pos.y][game->next_pos.x] == 'C')
	{
		game->counter.coin--;
		write_move_on_map(game, dir);
		if (if_prev_door(game) == 0)
			print_new_player(game, dir);
	}
	return (1);
}
