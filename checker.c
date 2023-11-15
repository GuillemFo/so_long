/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/11/15 13:52:58 by gforns-s         ###   ########.fr       */
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
	while (++game->tools.x < game->col_x)
	{
		game->tools.x = -1;
		while (++game->tools.x < game->col_x)
		{
			if (game_test[game->tools.y][game->tools.x] == 'P') 
			{								
				game->playerpos.y = game->tools.y;
				game->playerpos.x = game->tools.x;
			}
			// else if (game_test[game->tools.y][game->tools.x] == 'C')
			// {
			// 	game->coinpos.y = game->tools.y;
			// 	game->coinpos.x = game->tools.x;
			// }
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
	while (game_test[game->row_y][game->tools.x] != '\0' || game_test[game->row_y][game->tools.x] != '\n') //ERROR 15/11/2023 11.55am
	{

		if (game_test[game->row_y][game->tools.x] != '1')
			message("ERROR\nIncorrect boundaries. Last line has issues\n", game);
		game->tools.x++;
		
	}
}

void	flood_fill_macro(char **game_test, t_game *game, int x, int y, int *all_found)
{
	if (x < 0 || y < 0 || x >= game->col_x || y >= game->row_y || (game_test[y][x] == '1' || all_found == 0))
		return;
	if (game_test[y][x] == 'C' || game_test[y][x] == 'E')
		all_found--;
	game_test[y][x] = 'V';
	flood_fill_macro(game_test, game, y + 1, x, all_found);
	flood_fill_macro(game_test, game, y - 1, x, all_found);
	flood_fill_macro(game_test, game, y, x + 1, all_found);
	flood_fill_macro(game_test, game, y, x - 1, all_found);
}

int	check_map_playable(char *argv, t_game *game)
{
	int		i;
	char	*line;
	char	**game_test;
	int		fd;
	int 	all_found;
	
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n", game);
	i = 0;
	game->map = malloc((game->row_y + 1) * sizeof(char *));
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
	game->tools.y = 0;
	check_bounds(game, game->map);
	count_obj(game, game->map);
	find_pos(game, game->map);
	all_found = game->counter.coin + 1;
	game_test = game->map;
	flood_fill_macro(game_test, game, game->playerpos.y, game->playerpos.x, &all_found);
	if (all_found != 0)
		message("ERROR\nObjectives not reachable\n", game);
 	print_matrix(game_test, game->row_y, game->col_x);
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
