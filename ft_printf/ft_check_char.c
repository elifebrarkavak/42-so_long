/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:30:27 by elikavak          #+#    #+#             */
/*   Updated: 2025/01/16 12:59:20 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_str(char *ar, int *len)
{
	int	i;

	i = 0;
	if (!ar)
	{
		write(1, "(null)", 6);
		*(len) += 6;
	}
	else
	{
		while (ar[i])
		{
			ft_putchar_len(ar[i], len);
			i++;
		}
	}
}
