/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:16:15 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/17 19:16:53 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

/*		RECORDAR: Matrix[Y][X]			*/
void	message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	(void)game->tools;
	//free_map(game->map);
	//mlx_destroy_window(game->mlx, );
	exit(0);
}

int	main(int argc, char **argv)
{
	
	void	*img;
	void	*mlx_win;
	t_game	game;

	ft_start_game(&game);
	check_args(argc, argv, &game);
	game.mlx = mlx_init();
	img = mlx_new_image(game.mlx, 1920, 1080);
	mlx_win = mlx_new_window(game.mlx, 1920, 1080, "so_long gforns-s");
	mlx_loop(game.mlx);
	
	
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