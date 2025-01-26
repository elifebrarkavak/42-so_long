/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elikavak <elikavak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:36:08 by elikavak          #+#    #+#             */
/*   Updated: 2025/01/16 16:20:29 by elikavak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int		ft_printf(const char	*string, ...);
void	ft_putchar_len(char c, int *len);
void	ft_str(char *ar, int *len);
void	ft_int(int num, int *len);
void	ft_un_int(unsigned int num, int *len);
void	ft_hex_2(unsigned int num, int *len);
void	ft_hex_x(unsigned int num, int *len);
void	ft_pointer(size_t pointer, int *len);

#endif