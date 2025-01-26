/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:46:54 by elikavak          #+#    #+#             */
/*   Updated: 2025/01/16 12:58:37 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_checker(char c, va_list *ar, int *len)
{
	if (c == 'c')
		ft_putchar_len(va_arg(*ar, int), len);
	else if (c == 'd' || c == 'i')
		ft_int(va_arg(*ar, int), len);
	else if (c == 's')
		ft_str(va_arg(*ar, char *), len);
	else if (c == 'u')
		ft_un_int(va_arg(*ar, unsigned int), len);
	else if (c == 'x')
		ft_hex_x(va_arg(*ar, unsigned int), len);
	else if (c == 'X')
		ft_hex_2(va_arg(*ar, unsigned int), len);
	else if (c == 'p')
		ft_pointer(va_arg(*ar, size_t), len);
	else if (c == '%')
		ft_putchar_len('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ar;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ar, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_checker(str[++i], &ar, &len);
		else
			ft_putchar_len((char)str[i], &len);
		i++;
	}
	va_end(ar);
	return (len);
}
