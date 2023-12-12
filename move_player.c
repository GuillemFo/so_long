/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:54:44 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/12 11:45:38 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_new_player(t_game *game, int dir)
{
	if (dir == 0)
		gen_print_up(game, (t_point){game->ppos.x, game->ppos.y + 1},
			game->ppos);
	else if (dir == 1)
		gen_print_down(game, (t_point){game->ppos.x, game->ppos.y - 1},
			game->ppos);
	else if (dir == 2)
		gen_print_left(game, (t_point){game->ppos.x + 1, game->ppos.y},
			game->ppos);
	else if (dir == 3)
		gen_print_right(game, (t_point){game->ppos.x - 1, game->ppos.y},
			game->ppos);
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
