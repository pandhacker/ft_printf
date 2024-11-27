/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agantaum <agantaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:18:33 by agantaum          #+#    #+#             */
/*   Updated: 2024/11/27 15:39:14 by agantaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dochar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_dostr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(str);
	return (write(1, str, i));
}

int	ft_doaddr(void *addr)
{
	int	len;

	if (addr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = ft_putnbr_base_ns((long long int)addr, "0123456789abcdef");
	return (len + 2);
}

int	ft_doint(int i)
{
	int	len;

	len = ft_putnbr(i);
	return (len);
}

int	ft_dobase(unsigned long unsignedl, char c)
{
	int	len;

	if (c == 'X')
		len = ft_putnbr_base_ns(unsignedl, "0123456789ABCDEF");
	else if (c == 'x')
		len = ft_putnbr_base_ns(unsignedl, "0123456789abcdef");
	else
		len = ft_putnbr_base_ns(unsignedl, "0123456789");
	return (len);
}
