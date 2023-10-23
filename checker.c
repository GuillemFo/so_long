/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/23 11:59:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

t_game	ft_start_game(void)
{
	t_game	game;

	game.row = 0;
	game.col = 0;
	game.player = 0;
	game.coins = 0;
	game.exit = 0;
	return (game);
}

char	**check_args(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		message (ft_printf("Error, invalid number of arguments\n"), NULL);
	if (ft_strlen(ft_strstr(argv[1], ".ber")) != 4)
		message ((1, "ERROR\nFile should be .ber type\n"), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message ((1, "ERROR\nFile does not open\n"), game);
	load_game(fd, game)
	return ();
}

void	load_game(int fd, t_game *game)
{
	char	*line;
	char	*all_game;
	
	while()//rd bytes del gnl ??
	{
		line = get_next_line(fd);
		all_game = ft_strjoin(all_game, line);
	}
	ft_start_game();
	if (!game)
		return ("Memory allocation error!\n");
	return (game);
}
