/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:14:07 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/05 15:59:04 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

int	check_ber(char *argv, char *text)
{
	int	tmp;

	tmp = ft_strlen(argv);
	if (ft_strncmp(&argv[tmp - 4], text, 4) != 0)
		return (-1);
	return (0);
}

void	ft_start_game(t_game *game)
{
	game->row_y = 0;
	game->col_x = 0;
	game->ppos.y = 0;
	game->ppos.x = 0;
	game->epos.y = 0;
	game->epos.x = 0;
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
						message("ERROR\nToo many players\n", game);
				}
				else if (game_test[game->tools.y][game->tools.x] == 'C')
					game->counter.coin++;
				else if (game_test[game->tools.y][game->tools.x] == 'E')
				{
					game->counter.exit++;
					if (game->counter.exit != 1)
						message("ERROR\nToo many exits\n", game);
				}
				else
					message("ERROR\nWrong imput\n", game);
			}
		}
	}
	if (game->counter.player != 1)
		message("ERROR\nNo player found\n", game);
	if (game->counter.exit != 1)
		message("ERROR\nNo exit found\n", game);
	if (game->counter.coin < 1)
		message("ERROR\nNo coins found\n", game);
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
				game->ppos.y = game->tools.y;
				game->ppos.x = game->tools.x;
			}
			else if (game_test[game->tools.y][game->tools.x] == 'E')
			{
				game->epos.y = game->tools.y;
				game->epos.x = game->tools.x;
			}
		}
	}
}

void	check_bounds(t_game *game, char **game_test)
{
	game->tools.y = 0;
	game->tools.x = 0;
	while (game_test[0][game->tools.x] != '\0'
		&& game_test[0][game->tools.x] != '\n')
	{
		if (game_test[0][game->tools.x] != '1')
			message("ERROR\nIncorrect boundaries.\n", game);
		game->tools.x++;
	}
	while (game->tools.y < game->row_y)
	{
		if (game_test[game->tools.y][0] != '1'
			|| game_test[game->tools.y][game->col_x - 1] != '1')
			message("ERROR\nIncorrect boundaries.\n", game);
		game->tools.y++;
	}
	game->tools.x = 0;
	while (game_test[game->row_y - 1][game->tools.x] != '\0'
		&& game_test[game->row_y - 1][game->tools.x] != '\n')
	{
		if (game_test[game->row_y - 1][game->tools.x] != '1')
			message("ERROR\nIncorrect boundaries.\n", game);
		game->tools.x++;
	}
}
