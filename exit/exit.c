/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-p <dperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 11:04:36 by dperez-p          #+#    #+#             */
/*   Updated: 2026/04/12 11:41:07 by dperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Cleans all resources (MLX, window, and allocated memory)
	and exits the program */
void	clean_and_exit(t_data *data, int code)
{
	if (!data)
		exit(code);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	free_data(data);
	exit(code);
}

/* Close cub3D safety */
int	quit_cub3d(t_data  *data)
{
	clean_and_exit(data, 0);
	return (0);
}