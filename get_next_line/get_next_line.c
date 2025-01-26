/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:17:12 by elikavak          #+#    #+#             */
/*   Updated: 2025/01/16 13:00:54 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_buf(int fd, char *str)
{
	char	*res;
	int		i;

	res = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 1;
	while (ft_strchr(str, '\n') == 0 && i != 0)
	{
		i = read(fd, res, BUFFER_SIZE);
		if (i == -1)
		{
			free(res);
			free(str);
			return (NULL);
		}
		res[i] = '\0';
		str = ft_strjoin(str, res);
	}
	free(res);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*new;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read_buf(fd, str);
	if (!str)
		return (NULL);
	new = ft_get_line(str);
	str = ft_new_left(str);
	return (new);
}
