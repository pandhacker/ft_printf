/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agantaum <agantaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:12:46 by agantaum          #+#    #+#             */
/*   Updated: 2024/11/18 17:28:40 by agantaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# define SET = "cspdiuxX%"
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_list_content
{
	char    type;
    void    *arg;
	size_t  len;
    size_t  index_string;
    size_t  index_args;
}				t_list_content;

#endif