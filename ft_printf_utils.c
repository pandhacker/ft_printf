/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agantaum <agantaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:05:27 by agantaum          #+#    #+#             */
/*   Updated: 2024/11/27 15:36:32 by agantaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_supported(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'i' || c == 'd' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_putnbr_base_ns_rec(unsigned long long int c,
									char *set, int len_set)
{
	size_t	res;

	if (c > 0)
	{
		res = ft_putnbr_base_ns_rec(c / len_set, set, len_set);
		return (write(1, &set[c % len_set], 1) + res);
	}
	return (0);
}

int	ft_putnbr_base_ns(unsigned long long int c, char *set)
{
	size_t	len_set;
	size_t	res;

	len_set = ft_strlen(set);
	if (c == 0)
		return (write(1, &set[0], 1));
	res = ft_putnbr_base_ns_rec(c, set, len_set);
	return (res);
}

int	ft_putnbr(int i)
{
	int		len;
	char	c;

	len = 0;
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		i = -i;
		len = 1;
		write(1, "-", 1);
	}
	if (i > 9)
		len += ft_putnbr(i / 10);
	c = '0' + i % 10;
	return (len + write(1, &c, 1));
}
