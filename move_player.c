/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:54:44 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/30 09:53:17 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

void	print_new_player(t_game *game, int x, int y, int dir)
{
	if (dir == 0) //move up;
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, x * 32, (y - 1)* 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, x * 32, y * 32);
	}
	if (dir == 1) //move down;
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, x * 32, (y + 1) * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, x * 32, y * 32);
	}
	if (dir == 2) //move left;
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, (x + 1) * 32, y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, x * 32, y * 32);
	}
	if (dir == 3) //move right;
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, (x - 1) * 32, y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, x * 32, y * 32);
	}

}

void	apply_move(t_game *game, int x, int y, int dir) // REMEMBER MOVE PLAYER ON ACTUAL MAP STRUCT
{	
	
	if (game->map[y][x] == '0') // path
	{
		print_new_player(game, x, y, dir);
	}
	else if (game->map[y][x] == 'C') // coin
	{
		print_new_player(game, x, y, dir);
		// number of coins modified??
	}
	else if (game->map[y][x] == 'E') // door
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, x * 32, y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[3].img_ptr, x * 32, y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[4].img_ptr, x * 32, y * 32);
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