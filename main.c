/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:15:06 by elikavak          #+#    #+#             */
/*   Updated: 2025/01/26 12:45:42 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

static void	file_to_image_for_other(t_so_long *so_long)
{
	int	i;
	int	j;

	so_long->floor = mlx_xpm_file_to_image(so_long->mlx, "textures/floor.xpm",
			&i, &j);
	if (so_long->floor == NULL)
		handle_error("Error\nAbout xpm", so_long);
	so_long->coin = mlx_xpm_file_to_image(so_long->mlx, "textures/coin.xpm",
			&i, &j);
	if (so_long->coin == NULL)
		handle_error("Error\nAbout xpm", so_long);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "textures/exit.xpm",
			&i, &j);
	if (so_long->exit == NULL)
		handle_error("Error\nAbout xpm", so_long);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "textures/wall.xpm",
			&i, &j);
	if (so_long->wall == NULL)
		handle_error("Error\nAbout xpm", so_long);
}

static void	file_to_image_for_player(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, "textures/ani.xpm",
			&i, &j);
	if (so_long->player == NULL)
		handle_error("Error\nAbout xpm", so_long);
	file_to_image_for_other(so_long);
}

static void	all_zero(t_so_long *so_long)
{
	so_long->move_count = 0;
	so_long->exit_count = 0;
	so_long->player_y = 0;
	so_long->player_x = 0;
	so_long->map_x = 0;
	so_long->map_y = 0;
	so_long->coin_count = 0;
	so_long->error_count = 0;
	so_long->player_count = 0;
	so_long->exit_x = 0;
	so_long->exit_y = 0;
	so_long->map = NULL;
	so_long->map_clone = NULL;
}

int	main(int argc, char *argv[])
{
	t_so_long	so_long;

	if (argc != 2)
		handle_error("Error\nWrong argument, please select map.", NULL);
	all_zero(&so_long);
	error_check(argv[1], &so_long);
	obj_check(&so_long);
	so_long.mlx = mlx_init();
	if (so_long.mlx == NULL)
		handle_error("Error\nFailed to initialize MinilibX.", &so_long);
	so_long.win = mlx_new_window(so_long.mlx, (so_long.map_x * 32),
			(so_long.map_y * 32), "./so_long");
	if (so_long.win == NULL)
		handle_error("Error\nFailed to create window", &so_long);
	file_to_image_for_player(&so_long);
	mlx_hook(so_long.win, 2, 1L << 0, move, &so_long);
	mlx_hook(so_long.win, 17, 0, close_window, &so_long);
	mlx_loop_hook(so_long.mlx, so_long_loop, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
