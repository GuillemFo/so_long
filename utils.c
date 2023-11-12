/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:54:53 by gforns-s          #+#    #+#             */
/*   Updated: 2023/11/12 13:48:28 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

void	*ft_freemalloc(char **s2, int k)
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