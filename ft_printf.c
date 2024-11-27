/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agantaum <agantaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:30:34 by agantaum          #+#    #+#             */
/*   Updated: 2024/11/27 15:39:51 by agantaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	match_list(const char *src, int i, va_list args)
{
	int	res;

	res = 0;
	if (src[i + 1] == 'c')
		res = ft_dochar(va_arg(args, int));
	else if (src[i + 1] == 's')
		res = ft_dostr(va_arg(args, char *));
	else if (src[i + 1] == 'p')
		res = ft_doaddr(va_arg(args, void *));
	else if (src[i + 1] == 'i' || src[i + 1] == 'd')
		res = ft_doint(va_arg(args, int));
	else if (src[i + 1] == 'x' || src[i + 1] == 'X' || src[i + 1] == 'u')
		res = ft_dobase(va_arg(args, unsigned int), src[i + 1]);
	else if (src[i + 1] == '%')
		res = ft_dochar('%');
	return (res);
}

static int	ft_printf_run(const char *src, va_list args)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '%')
		{
			if (is_supported(src[i + 1]))
				res += match_list(src, i, args);
			else
				res += write(1, &src[i], 1);
			i++;
		}
		else
			res += write(1, &src[i], 1);
		i++;
	}
	return (res);
}

int	ft_printf(const char *src, ...)
{
	va_list	args;
	int		res;

	va_start(args, src);
	res = ft_printf_run(src, args);
	va_end(args);
	return (res);
}
