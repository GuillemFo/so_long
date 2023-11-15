/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:16:15 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/15 10:18:51 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

/*		RECORDAR: Matrix[Y][X]			*/
void	message(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	(void)game->tools;
	//free(game->map);
	//falta free de todo game
	exit(0);
}

int	main(int argc, char **argv)
{
	//void	*mlx;
	t_game	game;

	//mlx = mlx_init();
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