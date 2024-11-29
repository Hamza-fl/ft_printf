/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:02:15 by hfalati           #+#    #+#             */
/*   Updated: 2024/11/29 20:21:41 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, char format)
{
    int     count;
    char    *base;
    
    count = 0;
    if (format == 'x')
        base = "0123456789abcdef";
    else
		base = "0123456789ABCDEF";
    if (nbr < 16)
        count += ft_putchar(base[nbr % 16]);
    else
    {
        count += ft_puthex(nbr / 16, format);
        count += ft_puthex(nbr % 16, format);
    }
    return (count);
}