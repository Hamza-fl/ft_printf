/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:41:47 by hfalati           #+#    #+#             */
/*   Updated: 2024/11/29 20:12:05 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (str[i])
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}