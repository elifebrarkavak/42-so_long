/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:52:29 by bekarada          #+#    #+#             */
/*   Updated: 2025/01/25 17:33:36 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

static void	len_check(char *line, int x, int fd, char *next)
{
	if (!(ft_strlen(line) == x && line[x - 1] == '\n')
		&& !(ft_strlen(line) == x - 1 && line[x - 1] == '\0' ))
	{
		free(line);
		free(next);
		get_next_free(fd);
		handle_error("Error\nThe map is not rectangular!", NULL);
	}
	free(line);
}

static void	object_number(char obj, t_so_long *so_long, int pos_y, int pos_x)
{
	if (obj == 'P')
	{
		so_long->player_count++;
		so_long->player_x = pos_x;
		so_long->player_y = pos_y;
	}
	else if (obj == 'E')
	{
		so_long->exit_count++;
		so_long->exit_x = pos_x;
		so_long->exit_y = pos_y;
	}
	else if (obj == 'C')
		so_long->coin_count++;
	else if (obj != '0' && obj != '1')
		so_long->error_count++;
}

static void	insert_map(char *path, char **t_map, t_so_long *so_long)
{
	char	*line;
	int		loc_y;
	int		loc_x;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		handle_error("Error\nCan't open the file.", so_long);
	loc_y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		t_map[loc_y] = ft_strdup(line);
		loc_x = 0;
		while (line[loc_x] != '\0' && line[loc_x] != '\n')
		{
			object_number(line[loc_x], so_long, loc_y + 1, loc_x + 1);
			loc_x++;
		}
		free(line);
		loc_y++;
		line = get_next_line(fd);
	}
	close(fd);
}

static void	map_check_and_find_xy(char *str, t_so_long *so_long)
{
	char	*next_line;
	char	*line;
	int		fd;
	int		x;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		handle_error("Error\nCan't open the file.", NULL);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		handle_error("Error\nNo element in the file", NULL);
	}
	x = ft_strlen(line);
	while (line != NULL)
	{
		next_line = get_next_line(fd);
		nextline_check_end_file(next_line, line, fd);
		len_check(line, x, fd, next_line);
		so_long->map_y++;
		line = next_line;
	}
	close(fd);
	so_long->map_x = x - 1;
}

void	error_check(char *str, t_so_long *so_long)
{
	int		len;

	len = ft_strlen(str);
	if (ft_strncmp(str, "maps/", 5) || ft_strncmp(str + len - 4, ".ber", 4))
		handle_error("Error\nFile path is not correct!", NULL);
	if (str[len - 5] == '/' && ft_strncmp(str + len - 4, ".ber", 4) == 0)
		handle_error("Error\nFile path is not correct!", NULL);
	map_check_and_find_xy(str, so_long);
	so_long->map = malloc(sizeof(char *) * (so_long->map_y + 1));
	if (so_long->map == NULL)
		handle_error("Error\nMalloc for map.", NULL);
	so_long->map[so_long->map_y] = NULL;
	insert_map(str, so_long->map, so_long);
}
