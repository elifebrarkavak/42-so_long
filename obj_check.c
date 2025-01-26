/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:55:35 by bekarada          #+#    #+#             */
/*   Updated: 2025/01/25 17:37:11 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"

static int	flood_fill(int x, int y, char **map, t_so_long *so_long)
{
	if (map[y][x] == 'E' && so_long->exit_count == 1)
		so_long->exit_count--;
	if (map[y][x] == 'C' && so_long->coin_count > 0)
		so_long->coin_count--;
	if (so_long->coin_count == 0 && so_long->exit_count == 0)
		return (0);
	if (map[y][x] != '1' && map[y][x] != 'E' && map[y][x] != 'M')
	{
		map[y][x] = 'M';
		flood_fill(x + 1, y, map, so_long);
		flood_fill(x - 1, y, map, so_long);
		flood_fill(x, y + 1, map, so_long);
		flood_fill(x, y - 1, map, so_long);
	}
	if (so_long->coin_count == 0 && so_long->exit_count == 0)
		return (0);
	return (1);
}

static void	clone_map(t_so_long *so_long)
{
	int		i;

	so_long->map_clone = malloc(sizeof(char *) * (so_long->map_y + 1));
	if (!so_long->map_clone)
		handle_error("Error\nMalloc for cloned map", so_long);
	i = 0;
	while (i < so_long->map_y)
	{
		so_long->map_clone[i] = ft_strdup(so_long->map[i]);
		if (!so_long->map_clone[i])
			handle_error("Error\nAbout Malloc in clone_map", so_long);
		i++;
	}
	so_long->map_clone[i] = NULL;
}

static void	wall_check(t_so_long *so_long)
{
	char	**map;
	int		i;

	map = so_long->map;
	i = 0;
	while (i < so_long->map_x)
	{
		if (!(map[0][i] == '1' && map[so_long->map_y - 1][i] == '1'))
			handle_error("Error\nThe map is not walled!", so_long);
		i++;
	}
	i = 0;
	while (i < so_long->map_y)
	{
		if (!(map[i][0] == '1' && map[i][so_long->map_x - 1] == '1'))
			handle_error("Error\nThe map is not walled!", so_long);
		i++;
	}
}

void	obj_check(t_so_long *so_long)
{
	int	coin;

	coin = so_long->coin_count;
	if (so_long->coin_count < 1)
		handle_error("Error\nThere are no coins on the map.", so_long);
	if (so_long->player_count != 1)
		handle_error("Error\nNumber of player is not correct!", so_long);
	if (so_long->error_count != 0)
		handle_error("Error\nThere is an unknown object!", so_long);
	if (so_long->exit_count != 1)
		handle_error("Error\nNumber of exit is not correct!", so_long);
	wall_check(so_long);
	clone_map(so_long);
	if (flood_fill(so_long->player_x -1, so_long->player_y -1,
			so_long->map_clone, so_long))
		handle_error("Error\nExit Or Coin Path Is Closed!", so_long);
	so_long->coin_count = coin;
	so_long->exit_count = 1;
}
