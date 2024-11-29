/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:18:36 by hfalati           #+#    #+#             */
/*   Updated: 2024/11/29 20:13:10 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char	x;
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		x = nb + 48;
		count += ft_putchar(x);
	}
	return (count);
}