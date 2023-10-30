/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/30 14:17:31 by gforns-s         ###   ########.fr       */
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
	game.tools.y = -1;
	while (++game.tools.y < game.col)
	{
		game.tools.x = -1;
		while (++game.tools.x < game.row)
		{	
			if (game_test[game.tools.y][game.tools.x] == 'P') //y es columna -- x es fila -- 
				game.counter.player++;	//el doble puntero guarda primero columna y luego fila?
			else if (game_test[game.tools.y][game.tools.x] == 'C')
				game.counter.coin++;
			else if (game_test[game.tools.y][game.tools.x] == 'E')
				game.counter.exit++;
		}
	}
	if (game.counter.player != 1)
				message ("ERROR\nMore than one player found\n", game);
	if (game.counter.exit != 1)
				message ("ERROR\nMore than one exit found\n", game);
	if (game.counter.coin < 1)
		message ("ERROR\nNo coins found\n", game);
	return (game);
}

t_game	find_pos(t_game game, char **game_test)
{
	game.tools.y = -1;
	while (++game.tools.y < game.col)
	{
		game.tools.x = -1;
		while (++game.tools.x < game.row)
		{
			if (game_test[game.tools.y][game.tools.x] == 'P') //Y es columna -- X es fila -- 
			{								//el doble puntero guarda primero columna y luego fila?
				game.playerpos.x = game.tools.x;
				game.playerpos.y = game.tools.y;
			}
			else if (game_test[game.tools.y][game.tools.x] == 'C')
			{
				game.coinpos.x = game.tools.x;
				game.coinpos.y = game.tools.y;
			}
			else if (game_test[game.tools.y][game.tools.x] == 'E')
			{
				game.exitpos.x = game.tools.x;
				game.exitpos.y = game.tools.y;
			}
		}
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

void	check_bounds(t_game game, char **game_test) //add **game_test to the message func to be able to free all info?
{
	game.tools.x = 0;
	game.tools.y = 0;
	while (game_test[0][game.tools.x] != '\0' && game_test[0][game.tools.x] != '\n')
	{
		if (game_test[0][game.tools.x] != '1')
		{
			printf("%d line 120\n", game.tools.x);//Printf debug
			message("ERROR - 1\nIncorrect boundaries\n", game);//debug error message modified;
		}
		game.tools.x++;
	}
	game.tools.x = 0;
	while (game_test[game.col][game.tools.x] != '\0')
	{
		if (game_test[game.col][game.tools.x] != '1')
		{
			printf("%s 130\n", game_test[game.col]);//Printf debug
			message("ERROR - 2\nIncorrect boundaries\n", game);//debug error message modified;
		}
		game.tools.x++;
	}
	while (game.tools.y < game.col)
	{
		if (game_test[game.tools.y][0] != '1')
			message("ERROR - A\nIncorrect boundaries\n", game);
		printf("%d\n", game.row);
		if (game_test[game.tools.y][game.row -1] != '1')
		{
			printf("%s 141\n", game_test[game.tools.y]);//Printf debug
			message("ERROR - B\nIncorrect boundaries\n", game);//debug error message modified;
		}
		game.tools.y++;
	}
}


t_game	check_map_playable(char *argv, t_game game)
{
	int		i;
	char	*line;
	char	**game_test;
	int		fd;
	
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n", game);
	i = 0;
	ft_printf("GAME COL %d\n", game.col);
	game_test = malloc (game.col * sizeof(char *));
	if (!game_test)
		return (ft_printf("AAAAAAAA"), game);
	line = get_next_line(fd);	
	while (line != NULL)
	{
		game_test[i] = ft_strdup(line); //ft_substr(line, 0, ft_strlen_n(line));
		ft_printf("----------%s", game_test[i]);
		if (game_test[i] == NULL)
		{
			ft_freemalloc(game_test, i);
			free (line);
			ft_printf("AAAAAA");
			return(game);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	ft_printf("----%d------\n", i);
	game_test[i] = NULL;
	ft_printf("+++++++++++%s", game_test[0]);
	close (fd);
	game.tools.y = 0;
	while (game_test[game.tools.y])
	{
		ft_printf("%s", game_test[game.tools.y]);
		game.tools.y++;
	}
	//check_bounds(game, game_test);
	//game = count_obj(game, game_test);
	//game = find_pos(game, game_test);
	/// check lines, find and save: coin, player & exit pos [x] [y]
	return (game);
}

t_game	check_map_size(int fd, t_game game)
{
	char	*line;

	game = ft_start_game();
	// if (!game)
	// 	message("ERROR\nMemory allocation error!\n", game);
	line = get_next_line(fd);
	if (line == 0)
		message("ERROR\nError reading first line\n", game);	
	game.row = ft_strlen_n(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (game);
		if (game.row != ((int)ft_strlen_n(line)))
			message("ERROR\nMap not correct\n", game);
		else
			game.col++;
	}
	return (game);
}

t_game	check_args(int argc, char **argv, t_game game)
{
	int	fd;

	if (argc != 2)
		message("Error, invalid number of arguments\n", game);
	if (check_ber(argv[1], ".ber") != 0)
		message("ERROR\nFile should be .ber type\n", game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n", game);
	game = check_map_size(fd, game);
	close (fd);
	game = check_map_playable(argv[1], game);
	return (game);
}
