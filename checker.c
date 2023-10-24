/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/24 17:03:45 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

int	check_ber(char *argv, char *text)
{
	int	tmp;

	tmp = ft_strlen(argv);
	if (ft_strncmp(&argv[tmp -4], text, 4) != 0)
		return (-1);
	return (0);
}

t_game	ft_start_game(void)
{
	t_game	game;

	game.row = 0;
	game.col = 0;
	game.playerpos = 0;
	game.coinpos = 0;
	game.exitpos = 0;
	game.coin = 'C';
	game.player = 'P';
	game.exit = 'E';
	return (game);
}

t_game	*check_map_playable(int fd, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	game->game_test[i] = line;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
		game->game_test[i] = line;
	}
	free(line);
	/// check lines, find and save coin player exit pos [x] [y]
	return (game);
}

void	check_map_size(int fd, t_game *game)
{
	char	*line;
	char	*all_game;
	int		tmp;

	ft_start_game();
	if (!game)
		return ("Memory allocation error!\n");
	line = get_next_line(fd);
	if (line == 0)
		message ((1, "ERROR\nError reading first line\n"), game);
	game->row = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		tmp = ft_strlen(line);
		if (tmp != &game->row)
			message ((1, "ERROR\nMap not correct\n"), game);
		else
			game->col++;
	}
}

char	**check_args(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		message (ft_printf("Error, invalid number of arguments\n"), &game);
	if (check_ber(argv[1], ".ber") != 0)
		message (ft_printf("Error, invalid number of arguments\n"), &game);
	if (ft_strlen(check_ber(argv[1], ".ber") != 4))
		message ((1, "ERROR\nFile should be .ber type\n"), &game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message ((1, "ERROR\nFile does not open\n"), &game);
	check_map_size(fd, &game);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message ((1, "ERROR\nFile does not open\n"), &game);
	check_map_playable(fd, &game);
	return ();
}
