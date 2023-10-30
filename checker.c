/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/30 17:31:39 by gforns-s         ###   ########.fr       */
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

	game.col_y = 0;
	game.row_x = 1;
	game.playerpos.y = 0;
	game.playerpos.x = 0;
	game.exitpos.y = 0;
	game.exitpos.x = 0;
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
	game.tools.x = -1;
	while (++game.tools.x < game.row_x)
	{
		game.tools.y = -1;
		while (++game.tools.y < game.col_y)
		{	
			if (game_test[game.tools.x][game.tools.y] != '0' 
				&& game_test[game.tools.x][game.tools.y] != '1')
				{
					if (game_test[game.tools.x][game.tools.y] == 'P')
						game.counter.player++;
					else if (game_test[game.tools.x][game.tools.y] == 'C')
						game.counter.coin++;
					else if (game_test[game.tools.x][game.tools.y] == 'E')
						game.counter.exit++;
					else
						message ("ERROR\nWrong imput\n", game);
				}
		}
	}
	if (game.counter.player != 1)
				message ("ERROR\nNon or too many players\n", game);
	if (game.counter.exit != 1)
				message ("ERROR\nNon or too many exits\n", game);
	if (game.counter.coin < 1)
		message ("ERROR\nNo coins found\n", game);
	return (game);
}

t_game	find_pos(t_game game, char **game_test)
{
	game.tools.x = -1;
	while (++game.tools.x < game.row_x)
	{
		game.tools.y = -1;
		while (++game.tools.y < game.col_y)
		{
			if (game_test[game.tools.x][game.tools.y] == 'P') 
			{								
				game.playerpos.y = game.tools.y;
				game.playerpos.x = game.tools.x;
			}
			else if (game_test[game.tools.x][game.tools.y] == 'C')
			{
				game.coinpos.y = game.tools.y;
				game.coinpos.x = game.tools.x;
			}
			else if (game_test[game.tools.x][game.tools.y] == 'E')
			{
				game.exitpos.y = game.tools.y;
				game.exitpos.x = game.tools.x;
			}
		}
	}
	return (game);
}


//duplico info
//apply strdup to create mallocs per each pos
/*
while y != game.row_x
	while line[x] != '\0'
		game_test[y][x] = line[x];
		x++;
	y++;



*/

void	check_bounds(t_game game, char **game_test)
{
	game.tools.y = 0;
	game.tools.x = 0;
	while (game_test[0][game.tools.y] != '\0' && game_test[0][game.tools.y] != '\n')
	{
		if (game_test[0][game.tools.y] != '1')
			message("ERROR\nIncorrect boundaries\n", game);
		game.tools.y++;
	}
	while (game.tools.x < game.row_x)
	{
		if (game_test[game.tools.x][0] != '1' || game_test[game.tools.x][game.col_y -1] != '1')
			message("ERROR\nIncorrect boundaries\n", game);
		game.tools.x++;
	}
	game.tools.y = 0;
	while (game_test[game.row_x -1] && game.tools.y < game.col_y)
	{

		if (game_test[game.row_x -1][game.tools.y] != '1')
			message("ERROR\nIncorrect boundaries\n", game);
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
	game_test = malloc ((game.row_x + 1) * sizeof(char *));
	line = get_next_line(fd);	
	while (line != NULL)
	{
		game_test[i] = ft_strdup(line); //ft_substr(line, 0, ft_strlen_n(line));
		if (game_test[i] == NULL)
		{
			ft_freemalloc(game_test, i);
			free (line);
			return(game);
		}
		//free(line);
		line = get_next_line(fd);
		i++;
	}
	game_test[i] = NULL;
	close (fd);
	game.tools.x = 0;
	check_bounds(game, game_test);
	game = count_obj(game, game_test);
	game = find_pos(game, game_test);
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
	game.col_y = ft_strlen_n(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			return (game);
		if (game.col_y != ((int)ft_strlen_n(line)))
			message("ERROR\nMap not correct\n", game);
		else
			game.row_x++;
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
