/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-p <dperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:24:21 by dperez-p          #+#    #+#             */
/*   Updated: 2026/04/17 20:01:12 by dperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_args(t_data *data, char **argv)
{
	if (check_file(argv[1], true) == 1)
		clean_and_exit(data, 1);
	parse_data(argv[1], data);
	if (process_file_data(data, data->mapinfo.file) == FAILURE)
		return (free_data(data));
	if (validate_map(data, data->map) == FAILURE)
		return (free_data(data));

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