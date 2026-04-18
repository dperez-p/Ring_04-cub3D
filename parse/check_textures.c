/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-p <dperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:55:54 by dperez-p          #+#    #+#             */
/*   Updated: 2026/04/18 21:08:33 by dperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Check if the complete range of RGB is valid */
static int	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (err_msg(NULL, "Color range must be 0-255", FAILURE));
		i++;
	}
	return (SUCCESS);
}

/* Validate the the textures to be fill and the RGB*/
int	validate_textures(t_data *data, t_texinfo *textures)
{
	if (!textures->north || !textures->south
		|| !textures->east || !textures->west)
		return (err_msg(NULL, "Missing wall textures", FAILURE));
	if (check_file(textures->north, false) == FAILURE
		|| check_file(textures->south, false) == FAILURE
		|| check_file(textures->west, false) == FAILURE
		|| check_file(textures->east, false) == FAILURE)
		return (FAILURE);
	if (textures->floor == -1 || textures->ceiling == -1)
		return (err_msg(NULL, "Missing floor or ceiling colors", FAILURE));
	return (SUCCESS);
}
