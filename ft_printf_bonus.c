/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:22:47 by hfalati           #+#    #+#             */
/*   Updated: 2024/12/03 10:42:23 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printf_for(char format, va_list ar)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ar, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ar, char *));
	else if (format == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putaddr((unsigned long)va_arg(ar, void *));
	}
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(ar, int));
	else if (format == 'u')
		count += ft_put_unsigned(va_arg(ar, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_puthex(va_arg(ar, unsigned int), format);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	t_flags	add;
	va_list	ar;

	if (write(1, 0, 0) == -1)
		return (-1);
	add.i = 0;
	add.count = 0;
	va_start(ar, str);
	while (str[add.i])
	{
		if (str[add.i] == '%')
		{
			(add.i)++;
			if (str[add.i] == '#' || str[add.i] == '+' || str[add.i] == ' ')
				add.count += ft_flag(ar, &(add.i), str);
			else
				add.count += ft_printf_for(str[add.i], ar);
		}
		else
			add.count += ft_putchar(str[add.i]);
		if (str[add.i])
			(add.i)++;
	}
	va_end(ar);
	return (add.count);
}
