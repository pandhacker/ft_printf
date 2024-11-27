/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agantaum <agantaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:12:46 by agantaum          #+#    #+#             */
/*   Updated: 2024/11/27 15:40:09 by agantaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agantaum <agantaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:22:15 by agantaum          #+#    #+#             */
/*   Updated: 2024/11/17 13:54:11 by agantaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_strlen(char *s);
int	is_supported(char c);
int	ft_get_unilen(unsigned int uni, int len_set);
int	ft_putnbr_base_ns(unsigned long long int c, char *set);
int	ft_putnbr(int i);
int	ft_dochar(int c);
int	ft_dostr(char *str);
int	ft_doaddr(void *addr);
int	ft_doint(int i);
int	ft_dobase(unsigned long hex, char c);
int	ft_printf(const char *src, ...);

#endif