/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-p <dperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:20:52 by dperez-p          #+#    #+#             */
/*   Updated: 2026/04/15 20:59:38 by dperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	fill_direction_texture(t_texinfo *textures, char *line, int j)
{
	if (line[j] == 'N' && line[j + 1] == 'O')
	{
		if (textures->north != NULL)
			return (err_msg("NO", "Duplicate texture", 1));
		textures->north = get_texture_path(line, j + 2);
	}
	if (line[j] == 'S' && line[j + 1] == 'O')
	{
		if (textures->south != NULL)
			return (err_msg("SO", "Duplicate texture", 1));
		textures->south = get_texture_path(line, j + 2);
	}
	if (line[j] == 'W' && line[j + 1] == 'E')
	{
		if (textures->west != NULL)
			return (err_msg("WE", "Duplicate texture", 1));
		textures->west = get_texture_path(line, j + 2);
	}
	if (line[j] == 'E' && line[j + 1] == 'A')
	{
		if (textures->east != NULL)
			return (err_msg("EA", "Duplicate texture", 1));
		textures->east = get_texture_path(line, j + 2);
	}
	return (0);
}

/* Process the current line to get the information and when the map start*/
static int	process_line(t_data *data, char *line)
{
	int	j;

	j = 0;
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] == '\0'|| line[j] == '\n')
		return (4);
	if (ft_strncmp(&line[j], "NO ", 3) == 0 || ft_strncmp(&line[j], "SO ", 3) == 0
			|| ft_strncmp(&line[j], "WE ", 3) == 0
			|| ft_strncmp(&line[j], "EA ", 3) == 0)
	{
		return (fill_direction_textures(&data->texinfo, line, j));
	}
	else if (ft_strncmp(&line[j], "F ", 2) == 0 || ft_strncmp(&line[j], "C ", 2) == 0)
	{
		return (fill_color_textures(data, &data->texinfo, line, j));
	}
	else if (line[j] == '1' || line[j] == '0')
	{
		return (BREAK);
	}
	return (err_msg(NULL, "Invalid configuration line", 1));
}

int	process_file_data(t_data *data, char **map)
{
	int	i;
	int	status;

	i = 0;
	while (map[i])
	{
		status = process_line(data, map[i]);
		if (status == 1)
			return (1);
		if (status == BREAK)
		{
			break ;
		}
		i++;
	}
	if (!all_info_filled(data))
	{
		return (err_msg("Config", "Missing textures or colors", 1));
	}
	return (0);
}