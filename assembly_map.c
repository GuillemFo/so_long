/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:47:03 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/18 14:21:46 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"




//mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, 250, 250);


void	put_floor_walls(t_game *game)
{
	int	x;
	int y;
	
	x = 0;
	y = 0;
	
	while (y < game->row_y)
	{
		x = 0;
		while(x < game->col_x)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->img[1].img_ptr, x * 32, y * 32);
			else if (game->map[y][x] == '0' || game->map[y][x] == 'C' || game->map[y][x] == 'P' || game->map[y][x] == 'E')
					mlx_put_image_to_window(game->mlx, game->mlx_win, game->img[0].img_ptr, x * 32, y * 32);
			x++;
		}
		y++;
	}

}

void	put_images(t_game game)
{
	put_floor_walls(&game);
}
