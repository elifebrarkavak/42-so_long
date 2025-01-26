/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:53:50 by bekarada          #+#    #+#             */
/*   Updated: 2025/01/26 10:24:08 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"

void	free_map(char **result)
{
	int	index;

	index = 0;
	while (result[index])
		index++;
	while (index-- > 0)
		free(result[index]);
	free(result);
	result = NULL;
}

void	handle_error(char *error_message, t_so_long *so_long)
{
	if (so_long != NULL)
	{
		if (so_long->map != NULL)
			free_map(so_long->map);
		if (so_long->map_clone != NULL)
			free_map(so_long->map_clone);
	}
	ft_printf("%s\n", error_message);
	exit(-1);
}

int	ft_strncmp(const char *s1, const char *s2, int len)
{
	if (len == 0)
		return (0);
	while (*s1 && *s2 && len -1 > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		len--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dest;

	len = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	nextline_check_end_file(char *next, char *line, int fd)
{
	if (next == NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
		{
			close(fd);
			free(line);
			free(next);
			handle_error("Error\nThe last line mustn't newline!", NULL);
		}
	}
}
