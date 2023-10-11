/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:16:15 by gforns-s          #+#    #+#             */
/*   Updated: 2023/10/11 18:40:32 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_printf("Error"));
	
	//aplicar get_nxt_line de todo argv
	//comprobar que si es primera fila son todo paredes
	//comprobar que primer y ultimo caracter son paredes
	//comprobar el lenght de todos par que sea el mismo. (cada vez que se añade linea)
	//comprobar que ultima linea son todo paredes.
	//comprobar que hay minimo un premio una puerta y un caracter
	//comprobar que sea accesible cada uno de ellos
	//plantear mover caracter???
}