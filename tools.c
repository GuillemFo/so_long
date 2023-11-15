/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:13:39 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/15 10:29:32 by gforns-s         ###   ########.fr       */
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
