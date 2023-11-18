/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:16:15 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/18 04:18:57 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

/*		RECORDAR: Matrix[Y][X]			*/
void	message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	(void)game->tools;
	//free_map(game->map);
	//free(data.mlx);
	//mlx_destroy_window(data.mlx, );
	exit(0);
}

static void	image_holder(t_game *game)
{
	game->img[0].data = (int *)mlx_get_data_addr(game->img[0].image_ptr,
			&game->img[0].bpp, &game->img[0].size_l, &game->img[0].endian);
	game->img[1].data = (int *)mlx_get_data_addr(game->img[1].image_ptr,
			&game->img[1].bpp, &game->img[1].size_l, &game->img[1].endian);
	game->img[2].data = (int *)mlx_get_data_addr(game->img[2].image_ptr,
			&game->img[2].bpp, &game->img[2].size_l, &game->img[2].endian);
	game->img[3].data = (int *)mlx_get_data_addr(game->img[3].image_ptr,
			&game->img[3].bpp, &game->img[3].size_l, &game->img[3].endian);
	game->img[4].data = (int *)mlx_get_data_addr(game->img[4].image_ptr,
			&game->img[4].bpp, &game->img[4].size_l, &game->img[4].endian);
	game->img[5].data = (int *)mlx_get_data_addr(game->img[5].image_ptr,
			&game->img[5].bpp, &game->img[5].size_l, &game->img[5].endian);
	game->img[6].data = (int *)mlx_get_data_addr(game->img[6].image_ptr,
			&game->img[6].bpp, &game->img[6].size_l, &game->img[6].endian);
}

void	load_image(t_game *game)
{
	game->img = malloc (sizeof(t_data) * (7 + 1));
	game->img[0].image_ptr = mlx_xpm_file_to_image(game->mlx, "images/image0.xpm", 64, 64);
	game->img[1].image_ptr = mlx_xpm_file_to_image(game->mlx, "images/image1.xpm", 64, 64);
	game->img[2].image_ptr = mlx_xpm_file_to_image(game->mlx, "images/image2.xpm", 64, 64);
	game->img[3].image_ptr = mlx_xpm_file_to_image(game->mlx, "images/image3.xpm", 64, 64);
	game->img[4].image_ptr = mlx_xpm_file_to_image(game->mlx, "images/image4.xpm", 64, 64);
	game->img[5].image_ptr = mlx_xpm_file_to_image(game->mlx, "images/image5.xpm", 64, 64);
	game->img[6].image_ptr = mlx_xpm_file_to_image(game->mlx, "images/image6.xpm", 64, 64);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->mlx_win = mlx_new_window(game->mlx, game->col_x *64, game->row_y * 64, "so_long gforns-s");
	if (game->mlx_win == NULL)
	{
		//mlx_destroy_();
		free(game->mlx);
		return(1);
	}
	game->nw_img = mlx_new_image(game->mlx, 1920, 1080);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	ft_start_game(&game);
	check_args(argc, argv, &game);
	

	
	
	return (0);
}


// aplicar get_nxt_line de todo argv
// comprobar que si es primera fila son todo paredes
// comprobar que primer y ultimo caracter son paredes
// comprobar el lenght de todos par que sea el mismo. (cada vez que se añade linea)
// comprobar que ultima linea son todo paredes.
// comprobar que hay minimo un premio una puerta y un caracter
// comprobar que sea accesible cada uno de ellos
// plantear mover caracter???
/*Your program has to take as parameter a game description file ending with the .ber extension.

The game has to be constructed with 3 components: walls, collectibles, and free
space.
• The game can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a game exit,
P for the player’s starting position.
*/