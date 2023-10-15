/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:47:25 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/15 15:49:53 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft.h"
#include "get_next_line.h"
#include <mlx.h>

typedef struct s_map
{
    int n_row;
    int n_col;
    int n_exit;
    int n_player;
    int n_coins;
} t_map;

#endif