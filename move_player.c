/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:54:44 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/05 13:15:36 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"
int	if_prev_door(t_game *game)
{
	if (game->prepos.x == game->epos.x && game->prepos.y == game->epos.y)
	{
		game->map[game->prepos.y][game->prepos.x] = 'E';
		img_win(game->mlx, game->mlx_win, game->img[0].img_ptr,
			game->prepos.x * 32, game->prepos.y * 32);
		img_win(game->mlx, game->mlx_win, game->img[3].img_ptr,
			game->prepos.x * 32, game->prepos.y * 32);
		img_win(game->mlx, game->mlx_win, game->img[4].img_ptr,
			game->ppos.x * 32, game->ppos.y * 32);
		return (1);
	}
	return (0);
}

t_game	*precal_next_mv(t_game *game, int dir)
{
	game->prepos.x = game->ppos.x;
	game->prepos.y = game->ppos.y;
	game->next_pos.x = game->ppos.x;
	game->next_pos.y = game->ppos.y;
	if (dir == 0)
		game->next_pos.y -= 1;
	else if (dir == 1)
		game->next_pos.y += 1;
	else if (dir == 2)
		game->next_pos.x -= 1;
	else if (dir == 3)
		game->next_pos.x += 1;
	return (game);
}

t_game	*write_move_on_map(t_game *game, int dir)
{
	game->ppos.x = game->next_pos.x;
	game->ppos.y = game->next_pos.y;
	if (dir == 0)
	{
		game->map[game->ppos.y][game->ppos.x] = 'P';
		game->map[game->ppos.y + 1][game->ppos.x] = '0';
	}
	else if (dir == 1)
	{
		game->map[game->ppos.y][game->ppos.x] = 'P';
		game->map[game->ppos.y - 1][game->ppos.x] = '0';
	}
	else if (dir == 2)
	{
		game->map[game->ppos.y][game->ppos.x] = 'P';
		game->map[game->ppos.y][game->ppos.x + 1] = '0';
	}
	else if (dir == 3)
	{
		game->map[game->ppos.y][game->ppos.x] = 'P';
		game->map[game->ppos.y][game->ppos.x - 1] = '0';
	}
	return (game);
}

void	gen_print(t_game *game, t_point floor, t_point player1)
{		
	img_win(game->mlx, game->mlx_win, game->img[0].img_ptr,
		floor.x * 32, floor.y * 32);
	img_win(game->mlx, game->mlx_win, game->img[4].img_ptr,
		player1.x * 32, player1.y * 32);
}

void	print_new_player(t_game *game, int dir)
{
	if (dir == 0) //move up;
		gen_print(game, (t_point){game->ppos.x, game->ppos.y + 1}, game->ppos);
	else if (dir == 1) //move down;
		gen_print(game, (t_point){game->ppos.x, game->ppos.y - 1}, game->ppos);
	else if (dir == 2) //move left;
		gen_print(game, (t_point){game->ppos.x + 1, game->ppos.y}, game->ppos);
	else if (dir == 3) //move right;
		gen_print(game, (t_point){game->ppos.x - 1, game->ppos.y}, game->ppos);
}

int	apply_move(t_game *game, int dir) 
{
	precal_next_mv(game, dir); // CHECK IF ACTUAL POSS IS DOOR COORDS SO WHEN I DO NEXT MOVE, PRINT BACK DOOR.
	if_prev_door(game);
	if (game->map[game->next_pos.y][game->next_pos.x] == 'E') // door
	{
		write_move_on_map(game, dir);
		if (if_prev_door(game) == 0)
			print_new_player(game, dir);
		if (game->counter.coin == 0)
			return (2);
	}
	else if (game->map[game->next_pos.y][game->next_pos.x] == '0') // path
	{
		write_move_on_map(game, dir);
		if (if_prev_door(game) == 0)
		print_new_player(game, dir);
	}
	else if (game->map[game->next_pos.y][game->next_pos.x] == 'C') // coin
	{
		game->counter.coin--;
		write_move_on_map(game, dir);
		if (if_prev_door(game) == 0)
			print_new_player(game, dir);
	}
	return (1);
}
