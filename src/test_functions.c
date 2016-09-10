/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:50:32 by ggane             #+#    #+#             */
/*   Updated: 2016/09/10 20:48:46 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void    display_data(t_data *data)
{
    ft_putstr("name : ");
    ft_putendl(data->name);
    ft_putstr("pathname : ");
    ft_putendl(data->pathname);
    ft_putstr("error : ");
    ft_putnbr(data->error);
    ft_putchar('\n');
}

void            print_list(t_list *list)
{
    t_list  *tmp;

    tmp = list;
    while (tmp)
    {
        display_data(tmp->content);
        tmp = tmp->next;
    }
}
