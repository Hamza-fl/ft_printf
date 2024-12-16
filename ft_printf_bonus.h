/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfalati <hfalati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:20:52 by hfalati           #+#    #+#             */
/*   Updated: 2024/12/03 10:39:35 by hfalati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	hash;
	int	plus;
	int	space;
	int	count;
	int	i;
}		t_flags;

int		ft_printf(const char *str, ...);
int		ft_printf_for(char format, va_list ar);
int		ft_putchar(char c);
int		ft_putaddr(unsigned long addr);
int		ft_puthex(unsigned int nbr, char format);
int		ft_put_unsigned(unsigned int nb);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_hash(va_list ar, int *i, const char *str, int value_hash);
void	value_flags(int *p, int *s, int *h);
void	check(const char *str, int *p, int *s, int *h);
int		ft_flag(va_list ar, int *i, const char *s);

#endif
