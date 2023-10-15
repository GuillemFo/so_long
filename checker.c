/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:36:53 by codespace         #+#    #+#             */
/*   Updated: 2023/10/15 15:48:36 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/so_long.h"

something check_args(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (ft_printf("Error, invalid number of arguments\n"), NULL);
	if (ft_strlen(ft_strstr(file, ".ber")) != 4)
		return ((1, "ERROR\nFile should be .ber type\n"), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ((1, "ERROR\nFile does not open\n"), NULL);
	return (fd);
}

something check_map(fd)
{
	char *row;
	
	row = get_next_line(fd);
	if (!row)
		return ((1, "ERROR\nFile is empty\n"), NULL);
}