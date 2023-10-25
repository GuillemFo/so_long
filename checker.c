/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/25 16:08:21 by gforns-s         ###   ########.fr       */
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
	game.playerpos.x = 0;
	game.playerpos.y = 0;
	game.exitpos.x = 0;
	game.exitpos.y = 0;
	game.counter.player = 0;
	game.counter.coin = 0;
	game.counter.exit = 0;
	game.counter.moves = 0;
	game.player = 'P';
	game.coin = 'C';
	game.exit = 'E';
	return (game);
}

t_game	count_obj(t_game game, char **game_test)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (y != game.col)
	{
		while (x != game.row)
		{	if (game.counter.player > 1)
				message ((1, "ERROR\nMore than one player found\n"), game);
			if (game.counter.exit > 1)
				message ((1, "ERROR\nMore than one exit found\n"), game);
			else if (game_test[y][x] == 'P') //y es columna -- x es fila -- 
				game.counter.player++;	//el doble puntero guarda primero columna y luego fila?
			else if (game_test[y][x] == 'C')
				game.counter.coin++;
			else if (game_test[y][x] == 'E')
				game.counter.exit++;
			x++;
		}
		y++;
	}
	return (game);
}

t_game	find_pos(t_game game, char **game_test)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (y != game.col)
	{
		while (x != game.row)
		{
			if (game_test[y][x] == 'P') //y es columna -- x es fila -- 
			{								//el doble puntero guarda primero columna y luego fila?
				game.playerpos.x = x;
				game.playerpos.y = y;
			}
			else if (game_test[y][x] == 'C')
			{
				game.coinpos.x = x;
				game.coinpos.y = y;
			}
			else if (game_test[y][x] == 'E')
			{
				game.exitpos.x = x;
				game.exitpos.y = y;
			}
			x++;
		}
		y++;
	}
	return (game);
}


//duplico info
//apply strdup to create mallocs per each pos
/*
while y != game.col
	while line[x] != '\0'
		game_test[y][x] = line[x];
		x++;
	y++;



*/

t_game	check_map_playable(int fd, t_game game)
{
	int		i;
	char	*line;
	char	**game_test;

	i = 0;
	game_test = malloc (game.col * sizeof(char *));
	line = get_next_line(fd);
	game_test[i] = ft_strdup(line);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
		game_test[i] = ft_strdup(line);
	}
					//free(line);
	game = count_obj(game, &game_test);
	game = find_pos(game, &game_test);
	/// check lines, find and save: coin, player & exit pos [x] [y]
	return (game);
}

t_game	check_map_size(int fd, t_game game)
{
	char	*line;

	game = ft_start_game();
	if (!game)
		message ((1, "Memory allocation error!\n"), game);
	line = get_next_line(fd);
	if (line == 0)
		message ((1, "ERROR\nError reading first line\n"), game);
	game.row = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (ft_strlen(line) != game.row)
			message ((1, "ERROR\nMap not correct\n"), game);
		else
			game.col++;
	}
	return (game);
}

t_game	check_args(int argc, char **argv, t_game game)
{
	int	fd;

	if (argc != 2)
		message (ft_printf("Error, invalid number of arguments\n"), game);
	if (check_ber(argv[1], ".ber") != 0)
		message (ft_printf("Error, invalid number of arguments\n"), game);
	if (ft_strlen(check_ber(argv[1], ".ber") != 4))
		message ((1, "ERROR\nFile should be .ber type\n"), game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message ((1, "ERROR\nFile does not open\n"), game);
	check_map_size(fd, game);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message ((1, "ERROR\nFile does not open\n"), game);
	game = check_map_playable(fd, game);
	return (game);
}
