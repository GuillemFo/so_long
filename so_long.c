/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:16:15 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/07 10:27:36 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

/*		REMINDER: Matrix[Y][X]			*/
void	message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	(void)game;
	exit(0);
}

void	load_image(t_game *game)
{
	game->img[0].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/grass.xpm",
			&game->img[0].endian, &game->img[0].size_l);
	game->img[1].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm",
			&game->img[0].endian, &game->img[0].size_l);
	game->img[2].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/log.xpm",
			&game->img[0].endian, &game->img[0].size_l);
	game->img[3].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/fire.xpm",
			&game->img[0].endian, &game->img[0].size_l);
	game->img[4].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/front.xpm",
			&game->img[0].endian, &game->img[0].size_l);
	game->img[5].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/left.xpm",
			&game->img[0].endian, &game->img[0].size_l);
	game->img[6].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/right.xpm",
			&game->img[0].endian, &game->img[0].size_l);
	game->img[7].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/back.xpm",
			&game->img[0].endian, &game->img[0].size_l);
	game->img[8].img_ptr = mlx_xpm_file_to_image(game->mlx, "images/end.xpm",
			&game->img[0].endian, &game->img[0].size_l);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->col_x * 64, game->row_y
			* 64, "so_long gforns-s");
	load_image(game);
	put_images(*game);
	mlx_hook(game->mlx_win, KEYDOWN, 0, moves, game);
	mlx_hook(game->mlx_win, DESTROY, 0, close_window, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_start_game(&game);
	check_args(argc, argv, &game);
	start_game(&game);
	return (0);
}
