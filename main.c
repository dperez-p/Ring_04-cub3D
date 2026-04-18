/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-p <dperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:24:21 by dperez-p          #+#    #+#             */
/*   Updated: 2026/04/18 20:56:19 by dperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	parse_args(t_data *data, char **argv)
{
	if (check_file(argv[1], true) == 1)
		clean_and_exit(data, 1);
	parse_data(argv[1], data);
	if (process_file_data(data, data->mapinfo.file) == FAILURE)
		return (free_data(data));
	if (validate_map(data, data->map) == FAILURE)
		return (free_data(data));
	if (validate_textures(data, &data->texinfo) == FAILURE)
		return (free_data(data));
	/*init_player_direction*/
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (err_msg("Usage", ERROR_USAGE, 1));
	init_data(&data);
	if (parse_args(&data, argv) != 0)
		return (1);

}