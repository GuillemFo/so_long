/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/11/18 15:41:44 by gforns-s         ###   ########.fr       */
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
	game->row_y = 0;
	game->col_x = 0;
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
	game->tools.y = -1;
	while (++game->tools.y < game->row_y)
	{
		game->tools.x = -1;
		while (++game->tools.x < game->col_x - 1)
		{	
			if (game_test[game->tools.y][game->tools.x] != '0' 
				&& game_test[game->tools.y][game->tools.x] != '1')
				{
					if (game_test[game->tools.y][game->tools.x] == 'P')
					{
						game->counter.player++;
						if (game->counter.player != 1)
							message ("ERROR\nToo many players\n", game);
					}
					else if (game_test[game->tools.y][game->tools.x] == 'C')
						game->counter.coin++;
					else if (game_test[game->tools.y][game->tools.x] == 'E')
					{
						game->counter.exit++;
						if (game->counter.exit != 1)
							message ("ERROR\nToo many exits\n", game);
					}
					else
						message ("ERROR\nWrong imput\n", game);
				}
		}
	}
	if (game->counter.player != 1)
				message ("ERROR\nNo player found\n", game);
	if (game->counter.exit != 1)
				message ("ERROR\nNo exit found\n", game);
	if (game->counter.coin < 1)
		message ("ERROR\nNo coins found\n", game);
}

void	find_pos(t_game *game, char **game_test)
{
	game->tools.y = -1;
	while (++game->tools.y < game->row_y)
	{
		game->tools.x = -1;
		while (++game->tools.x < game->col_x)
		{
			if (game_test[game->tools.y][game->tools.x] == 'P') 
			{								
				game->playerpos.y = game->tools.y;
				game->playerpos.x = game->tools.x;
			}
			else if (game_test[game->tools.y][game->tools.x] == 'E')
			{
				game->exitpos.y = game->tools.y;
				game->exitpos.x = game->tools.x;
			}
		}
	}
}

void	check_bounds(t_game *game, char **game_test)
{
	game->tools.y = 0;
	game->tools.x = 0;
	while (game_test[0][game->tools.x] != '\0' && game_test[0][game->tools.x] != '\n')
	{
		if (game_test[0][game->tools.x] != '1')
			message("ERROR\nIncorrect boundaries. First line has issues\n", game);
		game->tools.x++;
	}
	while (game->tools.y < game->row_y)
	{
		if (game_test[game->tools.y][0] != '1' || game_test[game->tools.y][game->col_x -1] != '1')
			message("ERROR\nIncorrect boundaries. Some line is not starting or ending with 1 \n", game);
		game->tools.y++;
	}
	game->tools.x = 0;
	while (game_test[game->row_y -1 ][game->tools.x] != '\0' && game_test[game->row_y -1][game->tools.x] != '\n')
	{

		if (game_test[game->row_y -1][game->tools.x] != '1')
			message("ERROR\nIncorrect boundaries. Last line has issues\n", game);
		game->tools.x++;
		
	}
}

void	flood_fill_macro(char **game_test, t_game *game, int y, int x, int *all_found)
{
	if (x < 0 || y < 0 || x >= (game->col_x -1) || y >= (game->row_y -1) || game_test[y][x] == '1' || game_test[y][x] == 'V' || *all_found == 0) //player poss incorrect 17/11/23 15.27
		return;
	if (game_test[y][x] == 'C' || game_test[y][x] == 'E')
		*all_found -= 1;
	game_test[y][x] = 'V';
	flood_fill_macro(game_test, game, y, x + 1, all_found);
	flood_fill_macro(game_test, game, y, x - 1, all_found);
	flood_fill_macro(game_test, game, y + 1, x, all_found);
	flood_fill_macro(game_test, game, y - 1, x, all_found);
}

char **load_map_file(char *argv, t_game *game)
{
	int		i;
	int		fd;
	char	*line;
	char 	**map;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n", game);
	i = 0;
	map = malloc((game->row_y + 1) * sizeof(char *));
	line = get_next_line(fd);	
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		if (map[i] == NULL)
			message("ERROR\nCouldn't load the file correctly\n", game);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close (fd);
	return (map);
}

int	check_map_playable(char *argv, t_game *game)
{
	char	**game_test;
	int 	all_found;
	game->map = load_map_file(argv, game);
	game_test = load_map_file(argv, game);
	game->tools.y = 0;
	check_bounds(game, game->map);
	count_obj(game, game->map);
	find_pos(game, game->map);
	all_found = game->counter.coin + game->counter.exit;
	flood_fill_macro(game_test, game, game->playerpos.y, game->playerpos.x, &all_found);
	//ft_freemalloc(game_test, game->row_y);
	if (all_found != 0)
		message("ERROR\nObjectives not reachable\n", game);
 	print_matrix(game->map, game->row_y, game->col_x);
	return (0);
}



int	check_map_size(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (line == 0)
		message("ERROR\nError reading first line\n", game);	
	game->col_x = ft_strlen_n(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line && (game->col_x != ((int)ft_strlen_n(line))))
			return (1);
		game->row_y++;
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
