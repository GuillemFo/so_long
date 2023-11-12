/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/11/12 13:48:27 by gforns-s         ###   ########.fr       */
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

void	ft_start_game(t_game *game)
{
	game->col_y = 0;
	game->row_x = 0;
	game->playerpos.y = 0;
	game->playerpos.x = 0;
	game->exitpos.y = 0;
	game->exitpos.x = 0;
	game->counter.player = 0;
	game->counter.coin = 0;
	game->counter.exit = 0;
	game->counter.moves = 0;
	game->player = 'P';
	game->coin = 'C';
	game->exit = 'E';
}

void	count_obj(t_game *game, char **game_test)
{
	game->tools.x = -1;
	while (++game->tools.x < game->row_x)
	{
		game->tools.y = -1;
		while (++game->tools.y < game->col_y - 1)
		{	
			if (game_test[game->tools.x][game->tools.y] != '0' 
				&& game_test[game->tools.x][game->tools.y] != '1')
				{
					if (game_test[game->tools.x][game->tools.y] == 'P')
						game->counter.player++;
					else if (game_test[game->tools.x][game->tools.y] == 'C')
						game->counter.coin++;
					else if (game_test[game->tools.x][game->tools.y] == 'E')
						game->counter.exit++;
					else
						message ("ERROR\nWrong imput\n", game);
				}
		}
	}
	if (game->counter.player != 1)
				message ("ERROR\nNon or too many players\n", game);
	if (game->counter.exit != 1)
				message ("ERROR\nNon or too many exits\n", game);
	if (game->counter.coin < 1)
		message ("ERROR\nNo coins found\n", game);
}

void	find_pos(t_game *game, char **game_test)
{
	game->tools.x = -1;
	while (++game->tools.x < game->row_x)
	{
		game->tools.y = -1;
		while (++game->tools.y < game->col_y)
		{
			if (game_test[game->tools.x][game->tools.y] == 'P') 
			{								
				game->playerpos.y = game->tools.y;
				game->playerpos.x = game->tools.x;
			}
			else if (game_test[game->tools.x][game->tools.y] == 'C')
			{
				game->coinpos.y = game->tools.y;
				game->coinpos.x = game->tools.x;
			}
			else if (game_test[game->tools.x][game->tools.y] == 'E')
			{
				game->exitpos.y = game->tools.y;
				game->exitpos.x = game->tools.x;
			}
		}
	}
}


//duplico info
//apply strdup to create mallocs per each pos
/*
while y != game->row_x
	while line[x] != '\0'
		game_test[y][x] = line[x];
		x++;
	y++;



*/
int	confirm_all_connected(char **game_test, t_game *game)
{

	check_surround(game_test, game, pos ?? /*missing all coin pos*/); //the idea is to create a function that checks up down left right and confirms that any of that pos are = 'V'

	return (0);
}


void	check_bounds(t_game *game, char **game_test)
{
	game->tools.y = 0;
	game->tools.x = 0;
	while (game_test[0][game->tools.y] != '\0' && game_test[0][game->tools.y] != '\n')
	{
		if (game_test[0][game->tools.y] != '1')
			message("ERROR\nIncorrect boundaries\n", game);
		game->tools.y++;
	}
	while (game->tools.x < game->row_x)
	{
		if (game_test[game->tools.x][0] != '1' || game_test[game->tools.x][game->col_y -1] != '1')
			message("ERROR\nIncorrect boundaries\n", game);
		game->tools.x++;
	}
	game->tools.y = 0;
	while (game_test[game->row_x ] && game->tools.y < game->col_y)
	{

		if (game_test[game->row_x ][game->tools.y] != '1')
			message("ERROR\nIncorrect boundaries\n", game);
		game->tools.y++;
		
	}
}

void	flood_fill_macro(char **game_test, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->row_x || y >= game->col_y || (game_test[x][y] != '0' && game_test[x][y] != 'P'))
		return;
	game_test[x][y] = 'V';
	flood_fill_macro(game_test, game, x + 1, y);
	flood_fill_macro(game_test, game, x - 1, y);
	flood_fill_macro(game_test, game, x, y + 1);
	flood_fill_macro(game_test, game, x, y - 1);
}

int	check_map_playable(char *argv, t_game *game)
{
	int		i;
	char	*line;
	char	**game_test;
	int		fd;
	
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n", game);
	i = 0;
	game->map = malloc((game->row_x + 1) * sizeof(char *));
	line = get_next_line(fd);	
	while (line != NULL)
	{
		game->map[i] = ft_strdup(line); //ft_substr(line, 0, ft_strlen_n(line));
		if (game->map[i] == NULL)
		{
			ft_freemalloc(game->map, i);
			free (line);
			return(1);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close (fd);
	game->tools.x = 0;
	check_bounds(game, game->map);
	count_obj(game, game->map);
	find_pos(game, game->map);
	game_test = game->map;
	flood_fill_macro(game_test, game, game->playerpos.x, game->playerpos.y);
	if (confirm_all_connected(game_test, game) != 0)
		message("ERROR\nCan't reach all objects\n", game);
 	print_matrix(game_test, game->row_x, game->col_y);
	return (0);
}

int	check_map_size(int fd, t_game *game)
{
	char	*line;

	// if (!game)
	// 	message("ERROR\nMemory allocation error!\n", game);
	line = get_next_line(fd);
	if (line == 0)
		message("ERROR\nError reading first line\n", game);	
	game->col_y = ft_strlen_n(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line && (game->col_y != ((int)ft_strlen_n(line))))
			return (1);
		game->row_x++;
	}
	return (0);
}

int	check_args(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		message("Error, invalid number of arguments\n", game);
	if (check_ber(argv[1], ".ber") != 0)
		message("ERROR\nFile should be .ber type\n", game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n", game);
	if (check_map_size(fd, game) != 0)
		message("ERROR\nMap not correct\n", game);
	close (fd);
	check_map_playable(argv[1], game);
	return (0);
}
