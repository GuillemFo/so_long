/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/12/12 11:50:39 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_macro(char **game_test, t_game *game, t_point ppos,
		int *all_found)
{
	if (ppos.x < 0 || ppos.y < 0 || ppos.x >= (game->col_x - 1)
		|| ppos.y >= (game->row_y - 1) || game_test[ppos.y][ppos.x] == '1'
		|| game_test[ppos.y][ppos.x] == 'V' || *all_found == 0)
		return ;
	if (game_test[ppos.y][ppos.x] == 'C' || game_test[ppos.y][ppos.x] == 'E')
		*all_found -= 1;
	game_test[ppos.y][ppos.x] = 'V';
	flood_fill_macro(game_test, game, (t_point){ppos.x, ppos.y + 1}, all_found);
	flood_fill_macro(game_test, game, (t_point){ppos.x, ppos.y - 1}, all_found);
	flood_fill_macro(game_test, game, (t_point){ppos.x + 1, ppos.y}, all_found);
	flood_fill_macro(game_test, game, (t_point){ppos.x - 1, ppos.y}, all_found);
}

char	**load_map_file(char *argv, t_game *game)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n");
	i = 0;
	map = p_malloc((game->row_y + 1) * sizeof(char *));
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		if (map[i] == NULL)
			message("ERROR\nCouldn't load the file correctly\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	check_map_playable(char *argv, t_game *game)
{
	char	**game_test;
	int		all_found;

	game->map = load_map_file(argv, game);
	game_test = load_map_file(argv, game);
	game->tools.y = 0;
	check_bounds(game, game->map);
	count_obj(game, game->map);
	find_pos(game, game->map);
	all_found = game->counter.coin + game->counter.exit;
	flood_fill_macro(game_test, game, game->ppos, &all_found);
	ft_freemalloc_2(game_test, game->row_y);
	if (all_found != 0)
		message("ERROR\nObjectives not reachable\n");
	return (0);
}

int	check_map_size(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	if (line == 0)
		message("ERROR\nError reading first line\n");
	game->col_x = ft_strlen_n(line);
	if (game->col_x > SCREEN_W || game->col_x > 120)
		message("ERROR\nMap too big for so_long.h parameters. \
			\nCheck Instructions\n");
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line && (game->col_x != ((int)ft_strlen_n(line))))
		{
			free(line);
			return (1);
		}
		game->row_y++;
		if (game->row_y > SCREEN_H || game->row_y > 120)
			message("ERROR\nMap too big for so_long.h parameters. \
			\nCheck Instructions\n");
	}
	return (0);
}

int	check_args(int argc, char **argv, t_game *game)
{
	int	fd;

	if (argc != 2)
		message("Error, invalid number of arguments\n");
	if (check_ber(argv[1], ".ber") != 0)
		message("ERROR\nFile should be .ber type\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message("ERROR\nFile does not open\n");
	if (check_map_size(fd, game) != 0)
	{
		message("ERROR\nMap not correct\n");
		close(fd);
	}
	close(fd);
	check_map_playable(argv[1], game);
	return (0);
}
