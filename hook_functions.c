/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:54:20 by bekarada          #+#    #+#             */
/*   Updated: 2025/01/25 11:17:03 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

int	close_window(t_so_long *so_long)
{
	mlx_loop_end(so_long->mlx);
	mlx_destroy_image(so_long->mlx, so_long->player);
	mlx_destroy_image(so_long->mlx, so_long->wall);
	mlx_destroy_image(so_long->mlx, so_long->floor);
	mlx_destroy_image(so_long->mlx, so_long->coin);
	mlx_destroy_image(so_long->mlx, so_long->exit);
	mlx_destroy_window(so_long->mlx, so_long->win);
	free_map(so_long->map);
	free_map(so_long->map_clone);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	exit(0);
}

static void	map_import_window(t_so_long *so_long, int x, int y)
{
	while (y < so_long->map_y)
	{
		while (x < so_long->map_x)
		{
			if (so_long->map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->wall, x * 32, y * 32);
			else if (so_long->map[y][x] == '0')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->floor, x * 32, y * 32);
			else if (so_long->map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->coin, x * 32, y * 32);
			else if (so_long->map[y][x] == 'E')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->exit, x * 32, y * 32);
			else if (so_long->map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->win,
					so_long->player, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
}

int	so_long_loop(t_so_long *so_long)
{
	map_import_window(so_long, 0, 0);
	return (0);
}
