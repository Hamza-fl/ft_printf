/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:27:39 by hfalati           #+#    #+#             */
/*   Updated: 2024/11/29 21:42:56 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(unsigned long addr)
{
    int count;
    char *base;

    base = "0123456789abcdef";
    count = 0;
    if (addr < 16)
		count += ft_putchar(base[addr]);
	else
	{
		count += ft_putaddr(addr / 16);
		count += ft_putaddr(addr % 16);
	}
	return (count);
}
