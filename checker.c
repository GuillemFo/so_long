/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/15 18:04:19 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

t_map	ft_start_all(void)
{
	t_map	map;

	map.row = 0;
	map.col = 0;
	map.player = 0;
	map.coins = 0;
	map.exit = 0;
	return (map);
}

char	**check_args(int argc, char **argv, t_map *map)
{
	int	fd;

	if (argc != 2)
		return (ft_printf("Error, invalid number of arguments\n"), NULL);
	if (ft_strlen(ft_strstr(file, ".ber")) != 4)
		return ((1, "ERROR\nFile should be .ber type\n"), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ((1, "ERROR\nFile does not open\n"), NULL);
	return (check_map(fd, map));
}

char	**check_map(int fd, t_map *map)
{
	char	*map_row;
	char	**map;

	map_row = NULL;
	map = NULL;
	*map = ft_start_all();
	ft_read_map(fd, &map_row);
	map = ft_split(map_row, '\n');
	free(map_row);
	if (!map)
		return ("Memory allocation error!\n");
	return (map);
}

void	ft_read_map(int fd, t_map map *map)