/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:39:10 by hfalati           #+#    #+#             */
/*   Updated: 2024/12/03 10:26:48 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_hash(va_list ar, int *i, const char *str, int value_hash)
{
	int	nb;

	nb = va_arg(ar, int);
	if (!value_hash)
	{
		if (nb != 0 && str[*i] == 'x')
			return (ft_puthex(nb, 'x'));
		else if (nb != 0 && str[*i] == 'X')
			return (ft_puthex(nb, 'X'));
	}
	if (nb != 0 && str[*i] == 'x')
		return (ft_putstr("0x") + ft_puthex(nb, 'x'));
	else if (nb != 0 && str[*i] == 'X')
		return (ft_putstr("0X") + ft_puthex(nb, 'X'));
	else
		return (ft_putnbr(nb));
	return (0);
}

void	value_flags(int *p, int *s, int *h)
{
	*p = 0;
	*s = 0;
	*h = 0;
}

void	check(const char *str, int *p, int *s, int *h)
{
	if (*str == '+')
		*p = 1;
	else if (*str == ' ')
		*s = 1;
	else if (*str == '#')
		*h = 1;
}

int	ft_flag(va_list ar, int *i, const char *s)
{
	t_flags	flag;
	int		nb;

	value_flags(&flag.plus, &flag.space, &flag.hash);
	while (s[*i] && (s[*i] == '+' || s[*i] == ' ' || s[*i] == '#'))
	{
		check(s + *i, &flag.plus, &flag.space, &flag.hash);
		(*i)++;
	}
	if (s[*i] && (s[*i] == 'p'))
		return (ft_putaddr(va_arg(ar, unsigned long)));
	else if (s[*i] && (s[*i] == 'x' || s[*i] == 'X'))
		return (ft_hash(ar, i, s, flag.hash));
	else if (s[*i] && s[*i] == 's')
		return (ft_putstr(va_arg(ar, char *)));
	nb = va_arg(ar, int);
	if (s[*i] && (s[*i] == 'd' || s[*i] == 'i') && (nb >= 0 && flag.plus))
		return (ft_putchar('+') + ft_putnbr(nb));
	else if (s[*i] && (s[*i] == 'd' || s[*i] == 'i') && (nb >= 0 && flag.space))
		return (ft_putchar(' ') + ft_putnbr(nb));
	else if (s[*i] && (s[*i] == 'd' || s[*i] == 'i'))
		return (ft_putnbr(nb));
	else if (s[*i])
		return (ft_putchar(s[*i]));
	return (0);
}
