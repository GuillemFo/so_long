/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:54:53 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/12 11:55:07 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*p_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		exit(0);
	else
		return (ret);
}

void	*ft_freemalloc_2(char **s2, int k)
{
	while (k >= 0)
	{
		free(s2[k]);
		k--;
	}
	free(s2);
	return (NULL);
}

int	ft_strlen_n(const char *var)
{
	int	count;

	count = 0;
	while (var[count] != '\0' && var[count] != '\n')
		count++;
	return (count);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (1);
}

int	esc_window(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	return (1);
}
