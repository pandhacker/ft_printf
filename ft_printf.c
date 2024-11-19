/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agantaum <agantaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:30 by agantaum          #+#    #+#             */
/*   Updated: 2024/11/18 17:35:03 by agantaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  issupported(char c)
{
    size_t  i;

    i = 0;
    while (SET[i] != NULL)
    {
        if (SET[i] == c)
            return (1);
        i++;
    }
    return (0);
}

static t_list *lst_getreplace(char *s)
{
    size_t  i;
    t_list  *lst;
    t_list  *newnode;

    i = 0;
    lst = NULL;
    if (s == NULL)
        return (lst);
    while (s[i] != '\0')
    {
        if(s[i] == '%' && issupported(s[i + 1]))
        {
            newnode = ft_lstnew(s[i + 1]);
            if (newnode == NULL)
            {
                ft_lstclear(&lst, free);
                return (NULL);
            }
            ft_lstaddback(&lst, newnode);
            i++;
        }
        i++;
    }
    return (lst);
}

int main()
{
    
}