/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:37:09 by elikavak          #+#    #+#             */
/*   Updated: 2025/01/16 12:59:32 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int(int num, int *len)
{
	if (num >= 0)
	{
		if (num > 9)
			ft_int((num / 10), len);
		ft_putchar_len((num % 10) + '0', len);
	}
	else
	{
		if (num == -2147483648)
		{
			write (1, "-2147483648", 11);
			(*len) += 11;
		}
		else
		{
			ft_putchar_len('-', len);
			num = num * -1;
			ft_int(num, len);
		}
	}
}

void	ft_un_int(unsigned int num, int *len)
{
	if (num >= 10)
		ft_un_int((num / 10), len);
	ft_putchar_len((num % 10) + '0', len);
}

void	ft_hex_x(unsigned int num, int *len)
{
	char	*hex_digit;
	char	new_hex[9];
	int		i;

	hex_digit = "0123456789abcdef";
	i = 8;
	new_hex[i] = '\0';
	i--;
	if (num == 0)
		ft_putchar_len('0', len);
	else
	{
		while (num > 0)
		{
			new_hex[i] = hex_digit[num % 16];
			num /= 16;
			i--;
		}
		ft_str(&new_hex[i + 1], len);
	}
}

void	ft_hex_2(unsigned int num, int *len)
{
	char	*hex_digit2;
	char	new_hex2[9];
	int		i;

	hex_digit2 = "0123456789ABCDEF";
	i = 8;
	new_hex2[i] = '\0';
	i--;
	if (num == 0)
		ft_putchar_len('0', len);
	else
	{
		while (num > 0)
		{
			new_hex2[i] = hex_digit2[num % 16];
			num /= 16;
			i--;
		}
		ft_str(&new_hex2[i + 1], len);
	}
}

void	ft_pointer(size_t pointer, int *len)
{
	char	*poin;
	char	new_poin[17];
	int		i;

	poin = "0123456789abcdef";
	i = 16;
	new_poin[i] = '\0';
	i--;
	if (pointer == '\0')
		ft_str("(nil)", len);
	else
	{
		ft_str("0x", len);
		if (pointer == 0)
			ft_putchar_len('0', len);
		else
		{
			while (pointer > 0)
			{
				new_poin[i--] = poin[pointer % 16];
				pointer /= 16;
			}
			ft_str(&new_poin[i + 1], len);
		}
	}
}
