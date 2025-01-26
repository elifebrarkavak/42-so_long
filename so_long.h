/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:11:23 by bekarada          #+#    #+#             */
/*   Updated: 2025/01/25 12:33:28 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_so_long
{
	void	*win;
	void	*mlx;
	void	*wall;
	void	*floor;
	void	*coin;
	void	*exit;
	void	*player;
	char	**map;
	char	**map_clone;
	int		move_count;
	int		coin_count;
	int		exit_count;
	int		error_count;
	int		map_x;
	int		map_y;
	int		exit_x;
	int		exit_y;
	int		player_count;
	int		player_x;
	int		player_y;
}	t_so_long;

int		ft_strncmp(const char *s1, const char *s2, int len);
char	*ft_strdup(const char *s1);

void	error_check(char *str, t_so_long *so_long);
void	obj_check(t_so_long *so_long);

void	free_map(char **result);
void	handle_error(char *error_message, t_so_long *so_long);
void	nextline_check_end_file(char *next, char *line, int fd);
void	get_next_free(int fd);

int		close_window(t_so_long *so_long);
int		so_long_loop(t_so_long *so_long);
int		move(int keycode, t_so_long *so_long);

#endif
