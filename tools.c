/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:13:39 by gforns-s          #+#    #+#             */
/*   Updated: 2023/12/05 11:07:47 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

void print_matrix(char **matrix, int col, int row) {
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            ft_printf("%c ", matrix[j][i]);
        }
        ft_printf("\n");
    }
}

// HOW EXC KEY WILL KILL THE GAME

// int	moves_test(int keycode, void *param)
// {
// 	t_game *game;
// 	game = (t_game *)param;
// 	if (keycode == A_KEY)
// 		printf("Hello from key_hook!\n");
// 	if (keycode == ESC_KEY)
// 	{
// 		mlx_destroy_window(game->mlx, game->mlx_win);
// 		exit(0);
// 	}
// 	return (0);
// }