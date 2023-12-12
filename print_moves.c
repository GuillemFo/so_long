/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:23:21 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/12 12:01:40 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gen_print_up(t_game *game, t_point floor, t_point player1)
{
	IMG_WIN(game->mlx, game->mlx_win, game->img[0].img_ptr, floor.x * 64,
		floor.y * 64);
	IMG_WIN(game->mlx, game->mlx_win, game->img[7].img_ptr, player1.x * 64,
		player1.y * 64);
}

void	gen_print_down(t_game *game, t_point floor, t_point player1)
{
	IMG_WIN(game->mlx, game->mlx_win, game->img[0].img_ptr, floor.x * 64,
		floor.y * 64);
	IMG_WIN(game->mlx, game->mlx_win, game->img[4].img_ptr, player1.x * 64,
		player1.y * 64);
}

void	gen_print_left(t_game *game, t_point floor, t_point player1)
{
	IMG_WIN(game->mlx, game->mlx_win, game->img[0].img_ptr, floor.x * 64,
		floor.y * 64);
	IMG_WIN(game->mlx, game->mlx_win, game->img[5].img_ptr, player1.x * 64,
		player1.y * 64);
}

void	gen_print_right(t_game *game, t_point floor, t_point player1)
{
	IMG_WIN(game->mlx, game->mlx_win, game->img[0].img_ptr, floor.x * 64,
		floor.y * 64);
	IMG_WIN(game->mlx, game->mlx_win, game->img[6].img_ptr, player1.x * 64,
		player1.y * 64);
}
