/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-p <dperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:49:16 by dperez-p          #+#    #+#             */
/*   Updated: 2026/04/16 20:13:02 by dperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* fill the map leng to be equal and the height */
static int	fill_map_array(t_data *data, char **file, int i)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->mapinfo.height)
	{
		data->map[row] = malloc(sizeof(char) * (data->mapinfo.width + 1));
		if (!data->map[row])
		{
			ft_free_matrix(data->map);
			return (FAILURE);
		}
		ft_memset(data->map[row], ' ', data->mapinfo.width);
		data->map[row][data->mapinfo.width] = '\0';
		col = 0;
		while (file[i][col] && file[i][col] != '\n')
		{
			data->map[row][col] = file[i][col];
			col++;
		}
		i++;
		row++;
	}
	data->map[row] = NULL;
	return (SUCCESS);
}

/* Count how many lines are from i index */
static int	count_map_lines(char **file, int i)
{
	int	count;

	count = 0;
	while (file[i])
	{
		i++;
		count++;
	}
	return (count);
}

/* Count the max width of the map */
static int	get_max_width(char **file, int i)
{
	int	max_w;
	int	len;

	max_w = 0;
	while (file[i])
	{
		len = ft_strlen(file[i]);
		if (len > max_w)
			max_w = len;
		i++;
	}
	return (max_w);
}

/* Start the map creatin getting the height and filling the array */
int	create_map(t_data *data, char **file, int i)
{
	data->mapinfo.height = count_map_lines(file, i);
	data->mapinfo.width = get_max_width(file, i);
	data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		return (err_msg(NULL, "Malloc map failed", FAILURE));
	if (fill_map_array(data, file, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
