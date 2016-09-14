/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:50:32 by ggane             #+#    #+#             */
/*   Updated: 2016/09/14 15:46:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	display_data(t_list *list)
{
	t_data	*tmp;

	tmp = (t_data *)list->content;
	ft_putstr("name : ");
	ft_putendl(tmp->name);
	/*ft_putstr("pathname : ");
	ft_putendl(tmp->pathname);
	ft_putstr("error : ");
	ft_putnbr(tmp->error);
	ft_putchar('\n');
	print_flags(tmp->flags);
	ft_putchar('\n');*/
	ft_putendl("------");
}

void	print_list(t_list *list)
{
	while (list)
	{
		display_data(list);
		list = list->next;
	}
}

void    print_flags(int flags)
{
    int     switcher;

    switcher = 0;
    ft_putstr("flags ");
    if (flags & LOW_A_FLAG)
    {
        ft_putstr("-a ");
        switcher = 1;
    }
    if (flags & LOW_T_FLAG)
    {
        ft_putstr("-t ");
        switcher = 1;
    }
    if (flags & LOW_L_FLAG)
    {
        ft_putstr("-l ");
        switcher = 1;
    }
    if (flags & LOW_R_FLAG)
    {
        ft_putstr("-r ");
        switcher = 1;
    }
    if (flags & UPP_R_FLAG)
    {
        ft_putstr("-R ");
        switcher = 1;
    }
    if (switcher)
        ft_putendl(" activated\n");
    else
        ft_putendl(" not activated\n");
}
