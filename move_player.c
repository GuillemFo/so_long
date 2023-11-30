/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:54:44 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/30 13:07:09 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"
t_game	*precal_next_mv(t_game *game, int dir)
{
	game->next_pos.x = game->playerpos.x;
	game->next_pos.y = game->playerpos.y;
	if (dir == 0)
		game->next_pos.y += 1;
	else if (dir == 1)
		game->next_pos.y -= 1;
	else if (dir == 2)
		game->next_pos.x -= 1;
	else if (dir == 3)
		game->next_pos.x += 1;
	return (game);
}

t_game	*write_move_on_map(t_game *game, int dir)
{
	game->playerpos.x = game->next_pos.x;
	game->playerpos.y = game->next_pos.y;
	if (dir == 0)
	{
		game->map[game->playerpos.y][game->playerpos.x] = 'C';
		game->map[game->playerpos.y - 1][game->playerpos.x] = '0';
	}
	else if (dir == 1)
	{
		game->map[game->playerpos.y][game->playerpos.x] = 'C';
		game->map[game->playerpos.y + 1][game->playerpos.x] = '0';
	}
	else if (dir == 2)
	{
		game->map[game->playerpos.y][game->playerpos.x] = 'C';
		game->map[game->playerpos.y][game->playerpos.x - 1] = '0';
	}
	else if (dir == 3)
	{
		game->map[game->playerpos.y][game->playerpos.x] = 'C';
		game->map[game->playerpos.y][game->playerpos.x + 1] = '0';
	}
	return (game);
}

void	print_new_player(t_game *game, int dir)
{
	if (dir == 0) //move up;
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, game->playerpos.x * 32, (game->playerpos.y -1)* 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, game->playerpos.x * 32, game->playerpos.y * 32);
	}
	else if (dir == 1) //move down;
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, game->playerpos.x * 32, (game->playerpos.y + 1) * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, game->playerpos.x * 32, game->playerpos.y * 32);
	}
	else if (dir == 2) //move left;
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, (game->playerpos.x + 1) * 32, game->playerpos.y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, game->playerpos.x * 32, game->playerpos.y * 32);
	}
	else if (dir == 3) //move right;
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, (game->playerpos.x - 1) * 32, game->playerpos.y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, game->playerpos.x * 32, game->playerpos.y * 32);
	}

}

void	apply_move(t_game *game, int dir) 
{	
	precal_next_mv(&game, dir);			// REMEMBER MOVE PLAYER ON ACTUAL MAP STRUCT
										// CHECK IF ACTUAL POSS IS DOOR COORDS SO WHEN I DO NEXT MOVE, PRINT BACK DOOR.

	if (game->map[game->next_pos.y][game->next_pos.x] == '0') // path
	{
		write_move_on_map(game, dir);
		print_new_player(game, dir);
	}
	else if (game->map[game->next_pos.y][game->next_pos.x] == 'C') // coin
	{
		write_move_on_map(game, dir);
		print_new_player(game, dir);
		// number of coins modified??
	}
	else if (game->map[game->next_pos.y][game->next_pos.x] == 'E') // door
	{
		write_move_on_map(game, dir);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, game->playerpos.x * 32, game->playerpos.y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[3].img_ptr, game->playerpos.x * 32, game->playerpos.y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, game->playerpos.x * 32, game->playerpos.y * 32);
		// print path on last poss
	}
}







/*


THE FUNCTIONS ABOVE ARE GENERAL, THEY ARE MEANT TO BE APPLYED FOLLOWING THE HOOKS INFO. 

REMEMBER CHECKING IF BEFORE POS WAS 'E' SO WE HAVE TO PRINT BACK THE DOOR

IF ALL COINS COLLECTED PRINT OPEN DOOR

TAKE TRACK OF THE PLAYER POSE ON THE MOVEMENT BEFORE

FINISH THE CHECKER SO WE KNOW IS A POSSIBLE MOVE

REMEMBER TO PRINT IN TERMINAL A COUNTER OF MOVES EVEREY TIME WE CLICK A KEY 
BUT INCREASE ITS VALUE ONLY WHEN MOVEMENT IS ALLOWED / POSSIBLE





*/