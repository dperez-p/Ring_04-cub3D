/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-p <dperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 10:27:04 by dperez-p          #+#    #+#             */
/*   Updated: 2026/04/12 10:32:43 by dperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Inicialize texture info */
void	init_texinfo(t_texinfo *texture)
{
	texture->north = NULL;
	texture->south = NULL;
	texture->west = NULL;
	texture->east = NULL;
	texture->floor = 0;
	texture->ceiling = 0;
	texture->hex_floor = 0x0;
	texture->hex_ceiling = 0x0;
	texture->size = TEX_SIZE;
	texture->step = 0.0;
	texture->possition = 0.0;
	texture->x = 0;
	texture->y = 0;
}
