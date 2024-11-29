/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:20:52 by hfalati           #+#    #+#             */
/*   Updated: 2024/11/29 21:40:36 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...);
int ft_printf_for(char format, va_list ar);
int	ft_putaddr(unsigned long addr);
int ft_putchar(char c);
int	ft_puthex(unsigned int nbr, char format);
int ft_put_unsigned(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);

#endif