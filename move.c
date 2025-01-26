/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:11:27 by bekarada          #+#    #+#             */
/*   Updated: 2025/01/24 10:17:38 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

static void	move_w(t_so_long *so_long)
{
	if (so_long->map[so_long->player_y - 2][so_long->player_x - 1] == 'C')
		so_long->coin_count--;
	else if (so_long->map[so_long->player_y - 2][so_long->player_x - 1] == 'E')
	{
		if (so_long->coin_count == 0)
		{
			so_long->map[so_long->player_y - 1][so_long->player_x - 1] = '0';
			close_window(so_long);
		}
		else
			return ;
	}
	if (so_long->map[so_long->player_y - 2][so_long->player_x - 1] != '1')
	{
		so_long->map[so_long->player_y - 1][so_long->player_x - 1] = '0';
		so_long->map[so_long->player_y - 2][so_long->player_x - 1] = 'P';
		so_long->player_y--;
		so_long->move_count += 1;
	}
}

static void	move_s(t_so_long *so_long)
{
	if (so_long->map[so_long->player_y][so_long->player_x - 1] == 'C')
		so_long->coin_count--;
	else if (so_long->map[so_long->player_y][so_long->player_x - 1] == 'E')
	{
		if (so_long->coin_count == 0)
		{
			so_long->map[so_long->player_y - 1][so_long->player_x - 1] = '0';
			close_window(so_long);
		}
		else
			return ;
	}
	if (so_long->map[so_long->player_y][so_long->player_x -1] != '1')
	{
		so_long->map[so_long->player_y - 1][so_long->player_x - 1] = '0';
		so_long->map[so_long->player_y][so_long->player_x - 1] = 'P';
		so_long->player_y++;
		so_long->move_count += 1;
	}
}

static void	move_a(t_so_long *so_long)
{
	if (so_long->map[so_long->player_y - 1][so_long->player_x - 2] == 'C')
		so_long->coin_count--;
	else if (so_long->map[so_long->player_y - 1][so_long->player_x - 2] == 'E')
	{
		if (so_long->coin_count == 0)
		{
			so_long->map[so_long->player_y - 1][so_long->player_x - 1] = '0';
			close_window(so_long);
		}
		else
			return ;
	}
	if (so_long->map[so_long->player_y - 1][so_long->player_x - 2] != '1')
	{
		so_long->map[so_long->player_y - 1][so_long->player_x - 1] = '0';
		so_long->map[so_long->player_y - 1][so_long->player_x - 2] = 'P';
		so_long->player_x--;
		so_long->move_count += 1;
	}
}

static void	move_d(t_so_long *so_long)
{
	if (so_long->map[so_long->player_y - 1][so_long->player_x] == 'C')
		so_long->coin_count--;
	else if (so_long->map[so_long->player_y - 1][so_long->player_x] == 'E')
	{
		if (so_long->coin_count == 0)
		{
			so_long->map[so_long->player_y - 1][so_long->player_x - 1] = '0';
			close_window(so_long);
		}
		else
			return ;
	}
	if (so_long->map[so_long->player_y - 1][so_long->player_x] != '1')
	{
		so_long->map[so_long->player_y - 1][so_long->player_x - 1] = '0';
		so_long->map[so_long->player_y - 1][so_long->player_x] = 'P';
		so_long->player_x++;
		so_long->move_count += 1;
	}
}

int	move(int keycode, t_so_long *so_long)
{
	if (keycode == 65307)
		close_window(so_long);
	else if (keycode == 97 || keycode == 65361)
		move_a(so_long);
	else if (keycode == 115 || keycode == 65364)
		move_s(so_long);
	else if (keycode == 100 || keycode == 65363)
		move_d(so_long);
	else if (keycode == 119 || keycode == 65362)
		move_w(so_long);
	else
		return (0);
	ft_printf("Move: %d Coin: %d\n", so_long->move_count, so_long->coin_count);
	return (0);
}
