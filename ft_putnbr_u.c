/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:12:39 by hfalati           #+#    #+#             */
/*   Updated: 2024/11/29 20:20:05 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_put_unsigned(unsigned int nb)
{
	char	x;
	int		count;

	count = 0;
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